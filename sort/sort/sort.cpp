// a4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

#include "help.h"
#include "insert.h"
#include "practise.h"






int main()
{

    std::vector<int> insertTest1{ 2, 3, 5, 1, 4, 3, 4 };
    insertSort(insertTest1.begin(), insertTest1.end());
    showSorted(insertTest1.begin(), insertTest1.end());
    if (isSorted(insertTest1.begin(), insertTest1.end())) {
        std::cout << "insertTest1 passed \n";
    } else {
        std::cout << "insertTest1 failed \n";
    }


    std::vector<int> selectTest1{ 2, 3, 5, 1, 4, 3, 4 };
    selectSort(selectTest1.begin(), selectTest1.end());
    showSorted(selectTest1.begin(), selectTest1.end());
    if (isSorted(selectTest1.begin(), selectTest1.end())) {
        std::cout << "selectTest1 passed \n";
    } else {
        std::cout << "selectTest1 failed \n";
    }

    std::vector<int> shellTest1{ 2, 3, 5, 1, 4, 3, 4 };
    shellSort(shellTest1.begin(), shellTest1.end());
    showSorted(shellTest1.begin(), shellTest1.end());
    if (isSorted(shellTest1.begin(), shellTest1.end())) {
        std::cout << "shellTest1 passed \n";
    } else {
        std::cout << "shellTest1 failed \n";
    }

    std::vector<double> shellTest2;
    frandom(shellTest2, 10);
    shellSort(shellTest2.begin(), shellTest2.end());

    auto ub1 = upperBound(insertTest1.begin(), insertTest1.end(), 5);
    if (ub1 != insertTest1.end())
        std::cout << "ub1: " << *ub1 << std::endl;

    auto lb1 = lowerBound(insertTest1.begin(), insertTest1.end(), 5);
    if (lb1 != insertTest1.end())
        std::cout << "lb1: " << *lb1 << std::endl;

    practise_2_1_12();

    std::cout << "Hello World!\n";

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
