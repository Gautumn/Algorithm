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
 


/// 算法改进1: 对于小规模子数组使用插入排序
template <typename T, typename Comp>
void mergeSort1(std::vector<T> &v, std::vector<T> &tmp, size_t l, size_t r, const Comp &comp) {
    /// 当相差16的时候进入插入排序
    if (r <= l + 16) { return insertSort(v, l, r); }

    size_t mid = l + (r - l) / 2;
    mergeSort(v, tmp, l, mid, comp);
    mergeSort(v, tmp, mid + 1, r, comp);
    merge(v, tmp, l, mid, r, comp);
}

/// 算法改进2：测试数组是否有序
template <typename T, typename Comp>
void mergeSort2(std::vector<T> &v, std::vector<T> &tmp, size_t l, size_t r, const Comp &comp) {
    if (l >= r) return;
    size_t mid = l + (r - l) / 2;
    mergeSort(v, tmp, l, mid, comp);
    mergeSort(v, tmp, mid + 1, r, comp);
    /// 如果a[mid]小于等于a[mid+1]，我们就认为数组是有序的，并调过merge方法。
    if (v[mid] <= v[mid + 1]) return;
    merge(v, tmp, l, mid, r, comp);
}

/// 算法改进3：不将元素复制到辅助数组
template <typename T, typename Comp>
void merge3(std::vector<T> &src, std::vector<T> &dst, size_t l, size_t mid, size_t r, const Comp &comp) {
    size_t i = l, j = mid + 1;

    for (size_t k = l; k <= r; k++) {
        if (i > mid)                    dst[k] = src[j++];
        else if (j > r)                 dst[k] = src[i++];
        else if (comp(src[j], src[i]))  dst[k] = src[j++];
        else                            dst[k] = src[i++];
    }
}

template <typename T, typename Comp>
void mergeSort3(std::vector<T> &src, std::vector<T> &dst, size_t l, size_t r, const Comp &comp) {
    if (l >= r) return;
    size_t mid = l + (r - l) / 2;
    mergeSort3(dst, src, l, mid, comp);
    mergeSort3(dst, src, mid + 1, r, comp);
    merge3(src, dst, l, mid, r, comp);
}

template <typename T, typename Comp>
void mergeSort3(std::vector<T> &dst, const Comp &comp) {
    std::vector<T> src(dst);
    mergeSort3(src, dst, 0, dst.size() - 1, comp);
}

template <typename T>
void mergeSort3(std::vector<T> &dst) {
    std::vector<T> src(dst);
    mergeSort3(src, dst, 0, dst.size() - 1, std::less<T>());
}
