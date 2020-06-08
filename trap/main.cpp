/*
 * 接雨水问题:
 * 给定n个非负整数表示每个宽度为１的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
 * 输入：［0 1 0 2 1 0 1 3 2 1 2 1]
 * 输出：6
 * 解题思路：
 * 暴力法对每一个位置，计算其左右两边最高的柱子，按最低的柱子－当前位置下的高度，得到雨水数量．
 * 备忘录法是对上述暴力法的一个优化，避免重复计算．
 * 双向指针法通过将备忘录法进行简化，不存储dp列表，直接比较左右两边高度，取最小值即可．
*/


#include <iostream>
#include <vector>
using namespace std;

int trapBF(vector<int>& height);

int trapDP(vector<int>& height);

int trapPointer(vector<int>& height);

int main(int argc, char** argv) {

    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int output = trapBF(height);
    cout << "output = " << output << endl;
    output = trapDP(height);
    cout << "output2 = " << output << endl;
    output = trapPointer(height);
    cout << "output3 = " << output << endl;

    return 0;
}

int trapBF(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        int l_max = 0, r_max = 0;
        // find the max height on the left
        for (int j = i; j >= 0; --j) {
            l_max = max(l_max, height[j]);
        }
        // find the max heigh on the right
        for (int j = i; j < n; ++j) {
            r_max = max(r_max, height[j]);
        }
        ans += min(l_max, r_max) - height[i];
    }

    return ans;
}

int trapDP(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    int  ans = 0;

    vector<int> l_max(n), r_max(n);
    l_max[0] = height[0];
    r_max[n-1] = height[n-1];
    for (int i = 1; i < n; ++i) {
        l_max[i] = max(l_max[i-1], height[i]);
    } 
    for (int i = n -2; i >= 0; --i) {
        r_max[i] = max(r_max[i+1], height[i]);
    }

    for (int i = 1; i < n - 1; ++i) {
        ans += min(r_max[i], l_max[i]) - height[i];
    }

    return ans;
}

int trapPointer(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    int  ans = 0;

    int l_max, r_max;
    l_max = height[0];
    r_max = height[n-1];
    int left = 0, right = n -1;
    while (left <= right) {
        l_max = max(height[left], l_max);
        r_max = max(height[right], r_max);
        if (l_max < r_max) {
            ans += l_max - height[left];
            ++left;
        }
        else {
            ans += r_max - height[right];
            --right;
        }
    }

    return ans;
}