#pragma once

#include <vector>

/// 归并排序

template <typename T, typename Comp>
void merge(std::vector<T> &v, std::vector<T> &tmp, size_t l, size_t mid, size_t r, const Comp &comp) {
    size_t k;
    size_t i = l, j = mid + 1;

    for (k = l; k <= r; k++) {
        tmp[k] = v[k];
    }

    for (k = l; k <= r; k++) {
        if      (i > mid)               v[k] = tmp[j++];
        else if (j > r)                 v[k] = tmp[i++];
        else if (comp(tmp[j], tmp[i]))  v[k] = tmp[j++];
        else                            v[k] = tmp[i++];
    }
}

template <typename T, typename Comp>
void mergeSort(std::vector<T> &v, std::vector<T> &tmp, size_t l, size_t r, const Comp &comp) {
    if (l >= r) return;
    size_t mid = l + (r - l) / 2;
    mergeSort(v, tmp, l, mid, comp);
    mergeSort(v, tmp, mid + 1, r, comp);
    merge(v, tmp, l, mid, r, comp);
}

/// 自顶向下
// template <typename T, typename Comp>
// void mergeSort(std::vector<T> &v, const Comp &comp) {
//     std::vector<T> tmp(v.size());
//     mergeSort(v, tmp, 0, v.size() - 1, comp);
// }

/// 自底向上
template <typename T, typename Comp>
void mergeSort(std::vector<T> &v, const Comp &comp) {
    std::vector<T> tmp(v.size());
    for (size_t i = 1; i < v.size(); i = i + i) {
        for (size_t j = 0; j < v.size() - i; j += i + i) {
            merge(v, tmp, j, j + i - 1, std::min(j + i + i - 1, v.size() - 1), comp);
        }
    }
}


template <typename T>
void mergeSort(std::vector<T> &v) {
    mergeSort(v, std::less<T>());
}
 