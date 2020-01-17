#pragma once


template <typename T, typename Comp>
size_t quickSort(std::vector<T> &v, size_t lo, size_t hi, const Comp &comp) {
    size_t i = lo, j = hi + 1;
    while (true) {
        while (comp(a[++i], a[lo])) if (i == hi) break;
        while (comp[a[lo], a[--j]]) if (j == lo) break;
        if (i >= j) break;
        std::swap(v[i], v[j]);
    }
    std::swap(a[lo], a[j]);
    return j;
}

template <typename T, typename Comp>
void quickSort(std::vector<T> &v, size_t lo, size_t hi, const Comp &comp) {
    if (hi <= lo) return;
    size_t j = partition(v, lo, hi);
    quickSort(v, lo, j - 1);
    quickSort(v, j + 1, hi);
}

/// ÈýÏòÇÐ·Ö
template <typename T, typename Comp>
void quickSort(std::vector<T> &v, size_t lo, size_t hi, const Comp &comp) {
    if (hi <= lo) return;
    size_t lt = lo, i = lo + 1, gt = hi;
    while (i <= gt) {
        int cmp = comp(a[i], a[lo]);
        if      (cmp < 0)   std::swap(v[lt++], v[i++]);
        else if (cmp > 0)   std::swap(v[gt--], v[i]);
        else                i++;
    }
    sort(v, lo, lt - 1, comp);
    sort(v, gt + 1, hi, comp);
}

template <typename T, typename Comp>
void quickSort(std::vector<T> &v, const Comp &comp) {
    quickSort(v, 0, v.size() - 1, comp);
}

template <typename T>
void quickSort(std::vector<T> &v) {
    quickSort(v, std::less<T>());
}