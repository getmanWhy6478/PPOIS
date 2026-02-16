#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility> 

class HeapSort {
private:
    template<typename RandomIt>
    void heapify(RandomIt begin, size_t heap_size, size_t root_index) {
        size_t largest = root_index;
        size_t left = 2 * root_index + 1;
        size_t right = 2 * root_index + 2;

        if (left < heap_size && *(begin + left) > *(begin + largest))
            largest = left;
        if (right < heap_size && *(begin + right) > *(begin + largest))
            largest = right;

        if (largest != root_index) {
            std::swap(*(begin + root_index), *(begin + largest));
            heapify(begin, heap_size, largest);
        }
    }

    template<typename RandomIt>
    void build_heap(RandomIt begin, size_t heap_size) {
        for (int i = static_cast<int>(heap_size / 2) - 1; i >= 0; --i)
            heapify(begin, heap_size, static_cast<size_t>(i));
    }

public:
    template<typename RandomIt>
    void sort(RandomIt begin, RandomIt end) {
        size_t n = std::distance(begin, end);
        if (n < 2) return;

        build_heap(begin, n);

        for (size_t i = n - 1; i > 0; --i) {
            std::swap(*begin, *(begin + i));
            heapify(begin, i, 0);
        }
    }
};
