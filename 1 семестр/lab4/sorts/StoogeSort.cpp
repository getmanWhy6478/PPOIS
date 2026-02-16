class StoogeSort {
private:
    template<typename T>
    void mySwap(T& a, T& b) {
        T tmp = a;
        a = b;
        b = tmp;
    }

public:
    template<typename RandomIt>
    void sort(RandomIt begin, RandomIt end) {
        auto len = end - begin;
        if (len <= 1) return;

        if (*(end - 1) < *begin) {
            mySwap(*begin, *(end - 1));
        }

        if (len > 2) {
            auto third = len / 3;
            sort(begin, end - third);
            sort(begin + third, end);
            sort(begin, end - third);
        }
    }
};
