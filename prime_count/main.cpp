/*
 * 题目：给定一个数字，统计小于等于该数的素数数量
 * 解体思路：
 *　１．　由２－n，实际上只需要遍历由2-sqrt(n)即可，因为剩余部分均是相反乘法
 * 2.　若已知某个数是素数，那么在给定范围内，其倍数则不可能是素数．比如２是素数，则2*2，2*3，2*4...等等均不是素数
 * 3.　于是可以用两个循环，对每一個数进行判断．
 * 4.　主体还是判断哪些不是素数
*/

#include <iostream>
#include <cmath>
using namespace std;

int primeCount(const int& number);

int main(int argc, char** argv) {

    int n = 9;
    int count = primeCount(n);
    cout << "input = " << n << endl;
    cout << "count = " << count << endl;

    n = 99;
    count = primeCount(n);
    cout << "input2 = " << n << endl;
    cout << "count2 = " << count << endl;

    return 0;
}

int primeCount(const int& number) {
    int count = 0;
    if (number == 0 || number == 1) {
        return 0;
    }
    else {
        // 初始化
        bool* isPrim = new bool[number];
        for (int i = 0; i < number; ++i)
            isPrim[i] = true;

        // 主函数查找素数
        for (int i = 2; i * i < number; ++i) {
            if (isPrim[i]) {
                for (int j = i * i; j < number; j += i) {
                    isPrim[j] = false;
                }
            }
        }

        // 计数
        for (int i = 2; i < number; ++i) {
            if (isPrim[i]) {
                ++count;
            }
        }
    }
    return count;
}