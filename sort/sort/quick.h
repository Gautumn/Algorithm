#pragma once



template <typename T, typename Comp>
void quickSort(std::vector<T> &v, const Comp &comp) {

}

template <typename T>
void quickSort(v) {
    quickSort(v, std::less<T>());
}