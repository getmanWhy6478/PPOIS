#pragma once
#include <iterator>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <ostream>
#include <type_traits>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <vector>
template<typename VId>
class Edge_sequence {
public:
    using edge_type  = std::pair<VId,VId>;
    using container_type = std::vector<edge_type>;

    using iterator = typename container_type::iterator;
    using const_iterator = typename container_type::const_iterator;
    using reverse_iterator = typename container_type::reverse_iterator;
    using const_reverse_iterator = typename container_type::const_reverse_iterator;

private:
    container_type edges_;

public:
    bool empty() const noexcept { 
        return edges_.empty(); 
    }
    std::size_t size() const noexcept { 
        return edges_.size(); 
    }

    iterator begin() noexcept { 
        return edges_.begin(); 
    }
    iterator end()   noexcept { 
        return edges_.end(); 
    }
    const_iterator begin() const noexcept { 
        return edges_.begin(); 
    }
    const_iterator end()   const noexcept { 
        return edges_.end(); 
    }
    const_iterator cbegin() const noexcept { 
        return edges_.cbegin(); 
    }
    const_iterator cend()   const noexcept { 
        return edges_.cend(); 
    }

    reverse_iterator rbegin() noexcept { 
        return edges_.rbegin(); 
    }
    reverse_iterator rend()   noexcept { 
        return edges_.rend(); 
    }
    const_reverse_iterator rbegin() const noexcept { 
        return edges_.rbegin(); 
    }
    const_reverse_iterator rend()   const noexcept { 
        return edges_.rend(); 
    }
    const_reverse_iterator crbegin() const noexcept { 
        return edges_.crbegin(); 
    }
    const_reverse_iterator crend()   const noexcept { 
        return edges_.crend(); 
    }

    const_iterator find(const edge_type& e) const {
        return std::find(edges_.begin(), edges_.end(), e);
    }

    iterator find(const edge_type& e) {
        return std::find(edges_.begin(), edges_.end(), e);
    }

    iterator insert(edge_type e) {
        edges_.push_back(std::move(e));
        return std::prev(edges_.end());
    }

    iterator erase(const_iterator pos) {
        return edges_.erase(pos);
    }

    void erase_all_incident(VId v) {
        edges_.erase(std::remove_if(edges_.begin(), edges_.end(),
                       [&](const edge_type& e){ return e.first == v || e.second == v; }),
                     edges_.end());
    }
};