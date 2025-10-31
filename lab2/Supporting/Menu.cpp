#include "Menu.h"

// Конструктор по умолчанию
Menu::Menu() = default;

// Конструктор с начальными элементами
Menu::Menu(const vector<Eatable*>& items)
    : items(items) {}

void Menu::addItem(Eatable* item) {
    items.push_back(item);
}

void Menu::removeItemByName(const string& name) {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i] && items[i]->getName() == name) {
            items.erase(items.begin() + i);
            break;
        }
    }
}

Eatable* Menu::findItemByName(const string& name) {
    for (auto* item : items) {
        if (item && item->getName() == name) {
            return item;
        }
    }
    return nullptr;
}

vector<Eatable*> Menu::getItems() const {
    return items;
}

void Menu::clear() {
    items.clear();
}