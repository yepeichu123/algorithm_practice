/*
 * 给定Ｎ堆香蕉，第i堆香蕉有piles[i]根香蕉，警卫已经离开，将在Ｈ小时后回来．柯柯可以决定她吃香蕉的速度Ｋ（根／小时），
 * 每个小时，她将会选择一堆香蕉，从中吃掉Ｋ根．如果这堆香蕉少于Ｋ根，她将吃掉这堆的所有香蕉，然后这一小时内不会吃更多的香蕉．
 * 求柯柯可以在Ｈ小时内吃掉所有香蕉的最小速度Ｋ． 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minEatingSpeed(vector<int>& piles, const int& H);

int minEatingSpeedOpt(vector<int>& piles, const int& H);

int getMax(vector<int>& piles);

bool canFinsh(vector<int>& piles, const int& H, int i);

int main(int argc, char** argv) {

    vector<int> piles = {3, 6, 7, 11};
    int H = 8;
    cout << "test1 : Min_eating speed is : " << minEatingSpeed(piles, H) << endl;

    vector<int> piles2 = {30, 11, 23, 4, 20};
    H = 5;
    cout << "test2 : Min_eating speed is : " << minEatingSpeedOpt(piles2, H) << endl;
    return 0;
}

int minEatingSpeed(vector<int>& piles, const int& H) {
    if (piles.size() == 0) {
        return 0;
    }
    int max_speed = getMax(piles);

    for (int i = 1; i <= max_speed; ++i) {
        if (canFinsh(piles, H, i)) {
            return i;
        }
    }
}

int minEatingSpeedOpt(vector<int>& piles, const int& H) {
    if (piles.size() == 0) {
        return 0;
    }
    int max_speed = getMax(piles);

    int left = 1, right = max_speed + 1;

    while(left < right) {
        int mid = left + (right - left) / 2;
        if (canFinsh(piles, H, mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

int getMax(vector<int>& piles) {
    return *max_element(piles.begin(), piles.end());
}

bool canFinsh(vector<int>& piles, const int& H, int i) {
    int hour = 0;
    for (int num : piles) {
        hour += num / i + (num % i > 0 ? 1 : 0);
    }
    return hour <= H;
}