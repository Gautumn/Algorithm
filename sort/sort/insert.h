#pragma once
/**
 * ����Ƕ��ֲ��ҷ�����Ϊ�ڲ��������ʱ���õ��˶��ֲ��ҷ����ҵ�����㣬�����Լ�ʵ��һ��
 * std::upper_bound(begin, end, val):
 *      �ҵ���һ����val��ģ�>val)��bound��Ϊ���߽磬����
 *      ���ֲ��ҵ�ǰ�����Ѿ��ź���
 *      ���û���ҵ����ͷ���end
 * std::lower_bound(begin, end, val):
 *      �ҵ���һ������valС�ģ�>=val)
 *      ǰ�����Ѿ��ź���
 *      ���û���ҵ�������end
 * std::binary_search
 *
 */
template <typename Iter, typename T, typename Comp>
Iter upperBound(Iter begin, Iter end, const T& val, Comp comp) {
    Iter it;
    typename std::iterator_traits<Iter>::difference_type count, step;
    count = std::distance(begin, end);
    while (count > 0) {
        it = begin; step = count / 2; std::advance(it, step);
        if (!comp(val, *it)) {
            begin = ++it; count -= step + 1;
        } else
            count = step;
    }
    return begin;
}

template <typename Iter, typename T>
Iter upperBound(Iter begin, Iter end, const T& val) {
    return upperBound(begin, end, val, std::less<std::iterator_traits<Iter>::value_type>());
}

template <typename Iter, typename T, typename Comp>
Iter lowerBound(Iter begin, Iter end, const T& val, Comp comp) {
    Iter it;
    typename std::iterator_traits<Iter>::difference_type count, step;
    count = std::distance(begin, end);
    while (count > 0) {
        it = begin, step = count / 2; std::advance(it, step);
        if (comp(*it, val)) {
            begin = ++it; count -= step + 1;
        } else
            count = step;
    }
    return begin;
}

template <typename Iter, typename T>
Iter lowerBound(Iter begin, Iter end, const T& val) {
    return lowerBound(begin, end, val, std::less<std::iterator_traits<Iter>::value_type>());
}

template <typename Iter, typename T, typename Comp>
bool binarySearch(Iter begin, Iter end, const T& val, Comp comp) {
    begin = lowerBound(begin, end, val, comp);
    return (begin != end && !(*begin > val));
}


template <typename Iter, typename T>
bool binarySearch(Iter begin, Iter end, const T& val) {
    begin = lowerBound(begin, end, val);
    return (begin != end && !(*begin > val));
}



/// @}



/// ѡ������
/// @{
template <typename Iter, typename Comp>
void selectSort(Iter begin, Iter end, Comp comp) {
    for (Iter i = begin; i != end; i++) {
        Iter min = i;
        for (Iter j = i + 1; j != end; j++) {
            if (comp(*j, *min)) min = j;
        }
        if (min != i)
            std::swap(*i, *min);
    }
}

template <typename Iter>
void selectSort(Iter begin, Iter end) {
    selectSort(begin, end, std::less<decltype(*begin)>());
}
/// @}




/// ��������
/// @{

/// ���ݲ���Ķ����д�ĵ�һ��
template <typename Iter, typename Comp>
void insertSortNormal(Iter begin, Iter end, Comp comp) {
    if (begin == end) return;

    for (Iter cur = begin + 1; cur != end; cur++) {
        for (Iter p = cur; p > begin && comp(*p, *(p - 1)); p--)
            std::swap(*p, *(p - 1));
    }
}


/// ��������ܹ���֮ǰ�ķ�����Ч�ļ���copy�Ĵ��������ý������ø��ǣ������ǱȽϵĴ�����û�м��٣����ǴӺ���ǰ�Ƚϣ�
template <typename Iter, typename Comp>
void insertSortCover(Iter begin, Iter end, Comp comp) {
    if (begin == end) return;

    for (Iter cur = begin + 1; cur != end; cur++) {
        Iter p;
        for (p = cur; p > begin && comp(*cur, *(p - 1)); p--);
        if (cur != p) {
            auto tmp = std::move(*cur);
            std::copy_backward(p, cur, cur + 1);
            *p = std::move(tmp);
        }
    }
}


/// ���ֲ��롪���ö��ֲ��ң��ҵ�����в��롣�����֮ǰ�Ǹ����ԭ����ʹ���˶��ֲ�������λ
template <typename Iter, typename Comp>
void insertSortBinary(Iter begin, Iter end, Comp comp) {
    for (Iter cur = begin + 1; cur != end; cur++) {
        Iter p = std::upper_bound(begin, cur, *cur);
        if (p != cur) {
            auto tmp = std::move(*cur);
            std::copy_backward(p, cur, cur + 1);
            *p = std::move(tmp);
        }
    }
}


template <typename Iter>
void insertSort(Iter begin, Iter end) {
    insertSortBinary(begin, end, std::less<decltype(*begin)>());
}

template <typename Iter, typename Comp>
void insertSort(Iter begin, Iter end, Comp comp) {
    insertSortBinary(begin, end, comp);
}
/// @}

/// ϣ������
/// Ϊɶ�о�ϣ����STL����� :(
/// @{
template <typename Iter, typename Comp>
void shellSort(Iter begin, Iter end, Comp comp) {
    if (begin == end) return;

    typename std::iterator_traits<Iter>::difference_type size, gap;
    size = std::distance(begin, end);
    std::cout << "shell sort size: " << size << '\n';
    gap = 1;
    while (gap < size / 3) gap = gap * 3 + 1;
    while (gap > 0) {
        for (Iter i = begin + gap; i != end; i++) {
            for (Iter j = i; j >= (begin + gap) && comp(*j, *(j - gap)); j -= gap)
                std::swap(*j, *(j - gap));
        }
        gap /= 3;
    }
}

template <typename Iter>
void shellSort(Iter begin, Iter end) {
    shellSort(begin, end, std::less<decltype(*begin)>());
}

/// @}


