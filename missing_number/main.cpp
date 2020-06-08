/**
 * 题目：寻找消失的元素
 * 给定一个包含0，１，２，．．．，n中的n个数的序列，找出０，．．n中没有出现在序列中的那个数
 * 解题思路：
 * １．　用等差数列求解，但是会有整型溢出的危险；
 * 2.　先排序，后用哈希表进行查找
 * 3.　用异或操作，一个数异或自己等于0，一个数和０异或等于自身
 * 
 * 题目：寻找缺失和重复的元素
 * 给定一个长度为Ｎ的数组，其中本来装着[1,N]这Ｎ个元素，但是现在出现了一些错误，数组中一个元素出现了重复，同时导致另一个元素缺失．
 * 请找出数组中的重复元素和缺失元素的值
 * 解题思路：
 * １．　利用数组映射的方法
*/

#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums);

vector<int> findErrorNumber(vector<int>& nums);

int main(int argc, char** argv) {

    vector<int> nums = {1, 0, 2, 4};
    int miss = missingNumber(nums);
    cout << "miss is : " << miss << endl;

    vector<int> nums2 = {1, 2, 5, 4, 6, 5};
    cout << "input is : ";
    for (int i = 0; i < nums2.size(); i++) 
        cout << nums2[i] << ", ";
    cout << endl;

    vector<int> result = findErrorNumber(nums2);
    cout << "found the repeated number and right number should be : ";
    for (int i = 0; i < result.size(); ++i) 
        cout << result[i] << ", ";
    cout << endl;

    return 0;
}

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int res = n;
    for (int i = 0; i < n; ++i) {
        res ^= nums[i] ^ i;
    }

    return res;
}

// 输入元素是[1,N]
// 索引是[0, N-1]
vector<int> findErrorNumber(vector<int>& nums) {
    if (nums.empty()) return vector<int>();

    vector<int> dup;
    // 遍历需要全部做完，因为后续需要统计错误的元素是哪个
    for (int i = 0; i < nums.size(); ++i) {
        // 取出索引
        int index = abs(nums[i]) - 1;
        // 找到重复元素
        if (nums[index] < 0) {
            dup.push_back(abs(nums[i]));
        }
        else {
            // 改成负号只是为了做标记
            nums[index] *= -1;
        }
    }

    // 找到错误元素
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) {
            // 数值是索引+1
            dup.push_back(i + 1);
        }
    }

    return dup;
}