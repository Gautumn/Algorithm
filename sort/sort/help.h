#pragma once
/// Help function
/// @{
template <typename Iter, typename Comp>
bool isSorted(Iter begin, Iter end, Comp comp) {
    for (Iter i = begin + 1; i != end; i++) {
        if (comp(*i, *(i - 1))) return false;
    }
    return true;
}

template <typename Iter>
bool isSorted(Iter begin, Iter end) {
    return isSorted(begin, end, std::less<decltype(*begin)>());
}

template <typename Iter>
void showSorted(Iter begin, Iter end) {
    for (Iter i = begin; i != end; i++)
        std::cout << *i << " ";
    std::cout << '\n';
}

