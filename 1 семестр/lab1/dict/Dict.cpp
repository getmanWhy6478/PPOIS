#include "Dict.h"
#include <UnitTest++/UnitTest++.h>
#include <iostream>

Dict::Dict() : root(nullptr), count(0) {}
Dict::Node::Node(const string& eng, const string& rus)
    : english(eng), russian(rus), left(nullptr), right(nullptr) {
}
void Dict::Node::set_left(Node* node) {
    left = node;
}
void Dict::Node::set_right(Node* node) {
    right = node;
}
void Dict::Node::set_russian(const string& rus) {
    russian = rus;
}
const string& Dict::Node::get_english() {
    return english;
}
const string& Dict::Node::get_russian() const {
    return russian;
}
string& Dict::Node::get_russian() {
    return russian;
}
Dict::Node* Dict::Node::get_left() const {
    return left;
}
Dict::Node* Dict::Node::get_right() const {
    return right;
}


Dict::Dict(const Dict& other) : root(nullptr), count(0) {
    root = copy_tree(other.root);
    count = other.count;
}

Dict::~Dict() {
    clear_tree(root);
}

Dict& Dict::operator=(const Dict& other) {
    if (this != &other) {
        clear_tree(root);
        root = copy_tree(other.root);
        count = other.count;
    }
    return *this;
}

Dict::Node* Dict::add_node(Node* node, const string& english, const string& russian) {
    if (!node) {
        count++;
        return new Node(english, russian);
    }
    const string& english_word = node->get_english();
    if (english < english_word) {
        Dict::Node* left_node = node->get_left();
        node->set_left(add_node(left_node, english, russian));
    }
    else if (english > english_word) {
        Dict::Node* right_node = node->get_right();
        node->set_right(add_node(right_node, english, russian));
    }
    else {
        node->set_russian(russian);
    }

    return node;
}

Dict::Node* Dict::remove_node(Node* node, const string& english) {
    if (!node)
        return nullptr;

    string eng = node->get_english();
    if (english < eng) {
        Node* left_child = node->get_left();
        node->set_left(remove_node(left_child, english));
    }
    else if (english > eng) {
        Node* right_child = node->get_right();
        node->set_right(remove_node(right_child, english));
    }
    else
        node = direct_remove_node(node, english);

    return node;
}
Dict::Node* Dict::direct_remove_node(Node* node, const string& english) {
    if (!node->get_left()) {
        Node* right_child = node->get_right();
        count--;
        delete node;
        return right_child;
    }
    else if (!node->get_right()) {
        Node* left_child = node->get_left();
        count--;
        delete node;
        return left_child;
    }
    else {
        Node* min_right = find_min(node->get_right()), * left_child = node->get_left(), * right_child = node->get_right();
        string eng = min_right->get_english(), rus = min_right->get_russian();
        Node* new_node = new Node(eng, rus);
        new_node->set_left(left_child);
        new_node->set_right(remove_node(right_child, eng));
        delete node;
        return new_node;
    }
}
Dict::Node* Dict::find_min(Node* node) const {
    while (node->get_left())
        node = node->get_left();
    return node;
}

Dict::Node* Dict::find_node(Node* node, const string& english) const {
    if (!node || node->get_english() == english)
        return node;

    if (english < node->get_english()){
        Node* left_child = node->get_left();
        return find_node(left_child, english);
    }
    else{
        Node* right_child = node->get_right();
        return find_node(right_child, english);
    }
        
}

void Dict::clear_tree(Node* node) {
    if (node) {
        clear_tree(node->get_left());
        clear_tree(node->get_right());
        delete node;
    }
}

Dict::Node* Dict::copy_tree(Node* node) const {
    if (!node)
        return nullptr;
    Node* new_node = new Node(node->get_english(), node->get_russian());
    Node* left_child = node->get_left(), *right_child = node->get_right();
    new_node->set_left(copy_tree(left_child));
    new_node->set_right(copy_tree(right_child));

    return new_node;
}

Dict& Dict::operator+=(const pair<char*, char*>& pair) {
    root = add_node(root, pair.first, pair.second);
    return *this;
}

Dict& Dict::operator+=(const pair<string, string>& pair) {
    root = add_node(root, pair.first, pair.second);
    return *this;
}

Dict& Dict::operator-=(const char* english) {
    root = remove_node(root, english);
    return *this;
}

Dict& Dict::operator-=(const string& english) {
    root = remove_node(root, english);
    return *this;
}

string& Dict::operator[](const char* english) {
    Node* node = find_node(root, english);
    if (!node)
        throw runtime_error("Word not found: " + string(english));
    return node->get_russian();
}

string& Dict::operator[](const string& english) {
    return this->operator[](english.c_str());
}

int Dict::size() const {
    return count;
}

// �������� ������� �� �����
void Dict::load_from_file(const string& filename) {
    ifstream file(filename);
    if (!file.is_open())
        throw runtime_error("Cannot open file: " + filename);

    string line;
    while (getline(file, line)) {
        if (line.empty()) 
            continue;

        size_t delimiter_pos = string::npos;
        char delimiters[] = { '=', ':', '\t' };

        for (char delim : delimiters) {
            delimiter_pos = line.find(delim);
            if (delimiter_pos != string::npos)
                break;
        }

        if (delimiter_pos != string::npos) {
            string english = line.substr(0, delimiter_pos);
            string russian = line.substr(delimiter_pos + 1);

            english.erase(0, english.find_first_not_of(" "));
            english.erase(english.find_last_not_of(" ") + 1);

            russian.erase(0, russian.find_first_not_of(" "));
            russian.erase(russian.find_last_not_of(" ") + 1);

            if (!english.empty() && !russian.empty()) {
                root = add_node(root, english, russian);
            }
        }
    }
}

void Dict::clear() {
    clear_tree(root);
    root = nullptr;
    count = 0;
}
bool Dict::contains(const string& english) const {
    return find_node(root, english) != nullptr;
}

bool Dict::contains(const char* english) const {
    return find_node(root, english) != nullptr;
}

int main() {
    return UnitTest::RunAllTests();
}
