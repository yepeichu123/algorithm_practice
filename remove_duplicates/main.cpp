/*
 * 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度
 * 不要使用额外的空间，你必须在原地修改输入数组并在使用O(1)额外空间的条件下完成
 * 
 * 解题思路：
 * 可以考虑使用快慢指针，快指针前方探路，慢指针后面慢慢判断条件
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    ListNode(int value, ListNode* node): val(value), next(node) {}
    int val;
    ListNode* next;
};

int removeDuplicates(vector<int>& nums);

int removeDuplicates(ListNode** head);

int main(int argc, char** argv) {

    // 数组
    vector<int> nums = {1, 1, 2};
    int n = removeDuplicates(nums);
    cout << "n = " << n << endl;
    cout << "nums : ";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ", ";
    }
    cout << endl;

    vector<int> nums2 = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    n = removeDuplicates(nums2);
    cout << "n = " << n << endl;
    cout << "nums2 : ";
    for (int i = 0; i < nums2.size(); ++i) {
        cout << nums2[i] << ", ";
    }
    cout << endl;

    // 链表
    ListNode* head = new ListNode(1, nullptr);
    ListNode* second = new ListNode(1, nullptr);
    ListNode* last = new ListNode(2, nullptr);
    head->next = second;
    second->next = last;
    n = removeDuplicates(&head);
    cout << "n = " << n << endl;
    ListNode* trace = head;
    cout << "num3 = ";
    while(trace != nullptr) {
        cout << trace->val << ", ";
        trace = trace->next;
    }
    cout << endl;

    delete head;
    delete second;
    delete last;

    return 0;
}

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    int fast = 1, low = 0;
    while (fast < n) {
        if (nums[low] != nums[fast]) {
            ++low;
            nums[low] = nums[fast];
        }
        ++fast;
    }

    return low + 1;
}

int removeDuplicates(ListNode** head) {
    if (*head == nullptr) return 0;
    int count = 1;
    ListNode* slow = *head;
    ListNode* fast = (*head)->next;
    // 实际操作中，这种方法存在内存泄露的问题．
    while (fast != nullptr) {
        if (slow->val != fast->val) {
            slow->next = fast;
            ++count;
        }
        fast = fast->next;
    }
    return count;
}