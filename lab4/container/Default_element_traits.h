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

template<typename T>
class Default_element_traits {
public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;
    using const_pointer = const T*;

    using comparator = std::less<T>;

    static void print(std::ostream& os, const T& v) {
        os << v;
    }
};