#pragma once
#include "Default_element_traits.h"

template<typename T, typename Traits = Default_element_traits<T>>
class Flex_list {
    class node {
    public:
        T value;
        node* prev{nullptr};
        node* next{nullptr};
        explicit node(const T& v) : value(v) {}
        explicit node(T&& v) : value(std::move(v)) {}
    };

    node* head_{nullptr};
    node* tail_{nullptr};
    std::size_t size_{0};

public:
    using value_type = typename Traits::value_type;
    using reference  = typename Traits::reference;
    using const_reference = typename Traits::const_reference;
    using pointer = typename Traits::pointer;
    using const_pointer = typename Traits::const_pointer;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using traits_type = Traits;

    class iterator {
        friend class Flex_list;
        node* p_{nullptr};
        explicit iterator(node* n) : p_(n) {}
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = typename Flex_list::value_type;
        using difference_type = std::ptrdiff_t;
        using pointer = typename Flex_list::pointer;
        using reference = typename Flex_list::reference;

        iterator() = default;
        reference operator*()  const { 
            return p_->value; 
        }
        pointer   operator->() const {
             return &p_->value; 
            }
        iterator& operator++() {
             p_ = p_ ? p_->next : nullptr; return *this; 
            }
        iterator  operator++(int){
             iterator tmp(*this); ++(*this);
             return tmp; 
            }
        iterator& operator--() {
            if (!p_) 
                throw std::out_of_range("Iterator decrement on end()");
            p_ = p_->prev;
            return *this;
        }
        iterator  operator--(int){
             iterator tmp(*this);
              --(*this); 
              return tmp; 
        }
        bool operator==(const iterator& rhs) const {
             return p_ == rhs.p_; 
        }

        bool operator!=(const iterator& rhs) const {
             return p_ != rhs.p_; 
        }
    };

    class const_iterator {
        friend class Flex_list;
        const node* p_{nullptr};
        explicit const_iterator(const node* n) : p_(n) {}
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = typename Flex_list::value_type;
        using difference_type = std::ptrdiff_t;
        using pointer = typename Flex_list::const_pointer;
        using reference = typename Flex_list::const_reference;

        const_iterator() = default;
        const_reference operator*()  const { 
            return p_->value; 
        }
        pointer operator->() const {
            return &p_->value; 
            }
        const_iterator& operator++() {
            p_ = p_ ? p_->next : nullptr; 
            return *this; 
        }
        const_iterator  operator++(int){ const_iterator tmp(*this); ++(*this); return tmp; }
        const_iterator& operator--() {
            if (!p_) 
                throw std::out_of_range("Const_iterator decrement on end()");
            p_ = p_->prev;
            return *this;
        }
        const_iterator  operator--(int){
             const_iterator tmp(*this);
              --(*this);
               return tmp; }
        bool operator==(const const_iterator& rhs) const { return p_ == rhs.p_; }
        bool operator!=(const const_iterator& rhs) const { return p_ != rhs.p_; }
    };

    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    Flex_list() = default;

    Flex_list(const Flex_list& other) {
        for (const auto& v : other) push_back(v);
    }

    Flex_list(Flex_list&& other) noexcept
        : head_(other.head_), tail_(other.tail_), size_(other.size_) {
        other.head_ = other.tail_ = nullptr;
        other.size_ = 0;
    }

    ~Flex_list() { clear(); }

    Flex_list& operator=(Flex_list other) noexcept {
        swap(other);
        return *this;
    }

    void swap(Flex_list& other) noexcept {
        std::swap(head_, other.head_);
        std::swap(tail_, other.tail_);
        std::swap(size_, other.size_);
    }

    bool empty() const noexcept {
        return size_ == 0; 
    }
    size_type size() const noexcept { 
        return size_; 
    }

    reference front() {
        return head_->value;
    }
    const_reference front() const {
        if (empty())
            throw std::out_of_range("front() on empty container");
        return head_->value;
    }
    reference back() {
        return tail_->value;
    }
    const_reference back() const {
        if (empty())
            throw std::out_of_range("back() on empty container");
        return tail_->value;
    }

    void clear() noexcept {
        node* p = head_;
        while (p) {
            node* nxt = p->next;
            delete p;
            p = nxt;
        }
        head_ = tail_ = nullptr;
        size_ = 0;
    }

    void push_front(const T& v) {
        emplace_front(v); 
    }

    void push_front(T&& v){
         emplace_front(std::move(v)); 
    }

    template<typename U>
    void emplace_front(U&& v) {
        node* n = new node(std::forward<U>(v));
        n->next = head_;
        if (head_)
            head_->prev = n;
        head_ = n;
        if (!tail_)
            tail_ = n;
        ++size_;
    }

    void push_back(const T& v) {
         emplace_back(v); 
    }
    void push_back(T&& v){
         emplace_back(std::move(v)); 
    }

    template<typename U>
    void emplace_back(U&& v) {
        node* n = new node(std::forward<U>(v));
        n->prev = tail_;
        if (tail_)
            tail_->next = n;
        tail_ = n;
        if (!head_)
            head_ = n;
        ++size_;
    }

    iterator insert(const_iterator pos, const T& v) {
        return emplace(pos, v); 
        }
    iterator insert(const_iterator pos, T&& v){ 
        return emplace(pos, std::move(v)); 
    }

    template<typename U>
    iterator emplace(const_iterator pos, U&& v) {
        if (pos.p_ == nullptr) {
            emplace_back(std::forward<U>(v));
            return iterator(tail_);
        }
        node* curr = const_cast<node*>(pos.p_);
        node* n = new node(std::forward<U>(v));
        n->prev = curr->prev;
        n->next = curr;
        if (curr->prev) 
            curr->prev->next = n;
        else 
            head_ = n;
        curr->prev = n;
        ++size_;
        return iterator(n);
    }
    iterator erase(iterator pos) {
    node* curr = pos.p_;
    node* next = curr->next;
    if (curr->prev) 
        curr->prev->next = curr->next; else head_ = curr->next;
    if (curr->next) 
        curr->next->prev = curr->prev; else tail_ = curr->prev;
    delete curr;
    --size_;
    return iterator(next);
}
    iterator erase(const_iterator pos) {
        if (!pos.p_) 
            throw std::out_of_range("erase(end()) is invalid");
        node* curr = const_cast<node*>(pos.p_);
        node* next = curr->next;
        if (curr->prev) 
            curr->prev->next = curr->next; 
        else 
            head_ = curr->next;
        if (curr->next)
            curr->next->prev = curr->prev;
        else 
            tail_ = curr->prev;
        delete curr;
        --size_;
        return iterator(next);
    }

    iterator begin() noexcept { return iterator(head_); }
    iterator end()   noexcept { return iterator(nullptr); }
    const_iterator begin() const noexcept { return const_iterator(head_); }
    const_iterator end()   const noexcept { return const_iterator(nullptr); }
    const_iterator cbegin() const noexcept { return const_iterator(head_); }
    const_iterator cend()   const noexcept { return const_iterator(nullptr); }

    reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }
    reverse_iterator rend()   noexcept { return reverse_iterator(begin()); }
    const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(end()); }
    const_reverse_iterator rend()   const noexcept { return const_reverse_iterator(begin()); }
    const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(end()); }
    const_reverse_iterator crend()   const noexcept { return const_reverse_iterator(begin()); }

    friend bool operator==(const Flex_list& a, const Flex_list& b) {
        if (a.size_ != b.size_) return false;
        auto it1 = a.begin(), it2 = b.begin();
        for (; it1 != a.end(); ++it1, ++it2) {
            if (!(*it1 == *it2)) 
                return false;
        }
        return true;
    }
    friend bool operator!=(const Flex_list& a, const Flex_list& b) { return !(a == b); }
    friend bool operator< (const Flex_list& a, const Flex_list& b) {
        return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
    }
    friend bool operator> (const Flex_list& a, const Flex_list& b) { return b < a; }
    friend bool operator<=(const Flex_list& a, const Flex_list& b) { return !(b < a); }
    friend bool operator>>= (const Flex_list& a, const Flex_list& b) = delete; // защитный
    friend bool operator>=(const Flex_list& a, const Flex_list& b) { return !(a < b); }

    friend std::ostream& operator<<(std::ostream& os, const Flex_list& lst) {
        bool first = true;
        os << "[";
        std::for_each(lst.begin(), lst.end(), [&](const T& v){
            if (!first) os << ", ";
            first = false;
            Traits::print(os, v);
        });
        os << "]";
        return os;
    }
};