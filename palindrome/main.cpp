/**
 * 题目：判断链表是否为回文链表
 * 
*/

#include <iostream>
#include <string>
using namespace std;

struct ListNode {
    ListNode(int value, ListNode* node): val(value), next(node) {

    }
    int val;
    ListNode* next;
};

// 判断序列是否为回文序列
bool isPalindrome(const string& str);

// 翻转链表
void traverse(ListNode* head);

int A(int a, int b = 0);

int main(int argc, char** argv) {
    
    string str = "abac";
    bool check = isPalindrome(str);
    cout << "check is " << check << endl;

    int a = 1, b = 2;
    A(a);
    A(a, b);

    return 0;
}

// 判断序列是否为回文序列
bool isPalindrome(const string& str) {
    if (str.length() == 0) return false;

    int n = str.length();
    int left = 0, right = n - 1;
    while(left < right) {
        if (str[left] == str[right]) {
            ++left;
            --right;
        }
        else {
            return false;
        }
    }
    return true;
}

// 翻转链表
void traverse(ListNode* head) {
    ListNode *pre, *cur, *nxt;
    pre = nullptr;
    cur = nxt = head;
    while (cur != nullptr) {
        nxt = cur->next;
        cur->next = pre;

        pre = cur;
        cur = nxt;
    }

    head = pre;
}

int A(int a, int b) {
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}