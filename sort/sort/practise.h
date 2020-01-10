#pragma once


#include <cmath>

// 练习

/**
 * 2.1.12
 * 令希尔排序打印出递增序列的每个元素所带来的的比较次数和数组大小的比值。
 * 编写一个测试用例对随机Double数组进行希尔排序，验证该值是一个小常数，
 * 数组大小按照10的幂次递增，不小于100.
 * 
 * 统计比较次数这个需要在原有排序的基础上增加额外的代码，最好弄个类，重载一下"<"运算符
 */
void frandom(std::vector<double> &v, size_t size);
void practise_2_1_12();

