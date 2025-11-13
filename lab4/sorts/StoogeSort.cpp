template<typename RandomIt>
void stoogeSort(RandomIt begin, RandomIt end) {
    auto len = end - begin;
    if (len <= 1) return;

    if (*(end - 1) < *begin)
        std::iter_swap(begin, end - 1);

    if (len > 2) {
        auto third = len / 3;
        stoogeSort(begin, end - third);      // Первые 2/3
        stoogeSort(begin + third, end);      // Последние 2/3
        stoogeSort(begin, end - third);      // Первые 2/3 снова
    }
}
