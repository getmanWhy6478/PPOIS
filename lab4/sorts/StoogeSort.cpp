#include <algorithm>
template<typename RandomIt>
void stoogeSort(RandomIt begin, RandomIt end) {
    auto len = end - begin;
    if (len <= 1) return;

    if (*(end - 1) < *begin)
        std::iter_swap(begin, end - 1);

    if (len > 2) {
        auto third = len / 3;
        stoogeSort(begin, end - third);
        stoogeSort(begin + third, end);
        stoogeSort(begin, end - third);
    }
}
