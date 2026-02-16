#pragma once
template<typename VId, typename AdjContainer>
class Adjacent_forward_iterator {
    using inner_it = typename AdjContainer::const_iterator;
    inner_it it_{};
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type        = VId;
    using difference_type   = std::ptrdiff_t;
    using pointer           = const VId*;
    using reference         = const VId&;

    Adjacent_forward_iterator() = default;
    explicit Adjacent_forward_iterator(inner_it it) : it_(it) {}

    reference operator*()  const { 
        return *it_; 
    }
    pointer   operator->() const {
         return &(*it_); 
    }
    Adjacent_forward_iterator& operator++() {
         ++it_; return *this; 
    }
    Adjacent_forward_iterator  operator++(int){
         auto tmp(*this); ++(*this); return tmp; 
    }
    bool operator==(const Adjacent_forward_iterator& r) const {
         return it_ == r.it_; 
    }
    bool operator!=(const Adjacent_forward_iterator& r) const {
         return it_ != r.it_; 
    }
};