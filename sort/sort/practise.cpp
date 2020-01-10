#include "pch.h"
#include <vector>
#include <random>
#include <iostream>

#include "insert.h"
#include "practise.h"

void frandom(std::vector<double> &v, size_t size) {
    static std::default_random_engine e;
    static std::uniform_real_distribution<double> u(0, 1000);
    for (size_t i = 0; i < size; i++) {
        v.push_back(u(e));
    }
}

static int fcompCount = 0;
bool fcomp (const double &l, const double &r) {
    fcompCount++;
    return l < r;
}

void getShellCompCount(const int &n, int &count) {
    std::vector<double> vp;
    frandom(vp, n);
    fcompCount = 0;
    shellSort(vp.begin(), vp.end(), fcomp);
    count = fcompCount;
}


void practise_2_1_12() {

    int count = 0;
    // 100个
    getShellCompCount(100, count);
    std::cout << "size: " << 100 << " compare: " << fcompCount << '\n'; // 742
    // 1000个
    getShellCompCount(1000, count);
    std::cout << "size: " << 1000 << " compare: " << fcompCount << '\n'; // 14520
    // 10000个
    getShellCompCount(10000, count);
    std::cout << "size: " << 10000 << " compare: " << fcompCount << '\n'; // 233224
    // 1000000个
    getShellCompCount(1000000, count);
    std::cout << "size: " << 1000000 << " compare: " << fcompCount << '\n'; // 64505994

    // 100000000个(1亿）
    // getShellCompCount(100000000, count);
    // std::cout << "size: " << 100000000 << " compare: " << fcompCount << '\n';
}
