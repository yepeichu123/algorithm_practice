/*
 * 题目：
 * 传送带上的第i个包裹的重量为weights[i]．每一天，我们都会按给出重量的顺序
 * 往传送带上装在包裹，我们装在的重量不会超过船的最大运输重量．
 * 返回能在Ｄ天内将传送带上的所有包裹送达的船的最低运载能力
 * 解题思路：
 * 类似于吃香蕉那一题，只不过将香蕉换成货物，并且每天可以运输至少一堆货物．
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int shipWithinDays(vector<int>& weights, int D);

bool canFinish(vector<int>& weights, int D, int cap);

int main(int argc, char** argv) {

    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int D = 5;
    cout << "output = " << shipWithinDays(input, D) << endl;
    return 0;
}

int shipWithinDays(vector<int>& weights, int D) {
    if (weights.size() == 0) {
        return 0;
    }

    int left = weights[weights.size() - 1];
    int right = 0;
    for (int i = 0; i < weights.size(); ++i)
        right += weights[i];

    cout << "min cap : " << left << ", max cap : " << right << endl;

    right = right + 1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        cout << "left = " << left << ", right = " << right << ", mid = " << mid << endl;
        if (canFinish(weights, D, mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}

bool canFinish(vector<int>& weights, int D, int cap) {
    int i = 0;
    for (int day = 0; day < D; ++day) {
        int maxCap = cap;
        while ( (maxCap -= weights[i]) >= 0) {
            ++i;
            if (i == weights.size()) {
                return true;
            }
        }
    }
    return false;
}