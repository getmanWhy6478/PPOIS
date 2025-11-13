#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

// Восстановление свойства max-heap
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

// Построение кучи
template<typename RandomIt>
void build_heap(RandomIt begin, size_t heap_size) {
    for (int i = heap_size / 2 - 1; i >= 0; --i)
        heapify(begin, heap_size, i);
}

// Основной алгоритм HeapSort
template<typename RandomIt>
void heapsort(RandomIt begin, RandomIt end) {
    size_t n = std::distance(begin, end);
    build_heap(begin, n);

    for (size_t i = n - 1; i > 0; --i) {
        std::swap(*begin, *(begin + i)); // Переместить максимум в конец
        heapify(begin, i, 0);            // Восстановить кучу
    }
}
