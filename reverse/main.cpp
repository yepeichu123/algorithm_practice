/*
 *  反转链表 
*/


#include <iostream>
using namespace std;

struct ListNode{
    ListNode(int value, ListNode* node): val(value), next(node) {}

    int val;
    ListNode* next;
};

// 翻转整个链表
ListNode* reverse(ListNode* a);

// 翻转指定区间[ａ,b)的链表
ListNode* reverse(ListNode* a, ListNode* b);

// 翻转链表，每隔k个节点翻转一次
ListNode* reverseKGroup(ListNode* head, int k);


int main(int argc, char** argv) {

    ListNode *head = new ListNode(1, nullptr);
    ListNode *second = new ListNode(2, nullptr);
    ListNode *third = new ListNode(3, nullptr);
    ListNode *fourth = new ListNode(4, nullptr);
    ListNode *fifth = new ListNode(5, nullptr);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    cout << "before reversing, we have : " << endl;
    ListNode *a;
    a = head;
    while (a != nullptr) {
        cout << a->val << ", ";
        a = a->next;
    }
    cout << endl;

    cout << "after reversing, we have : " << endl;
    ListNode *newHead = reverseKGroup(head, 3);
    a = newHead;
    while (a != nullptr) {
        cout << a->val << ", ";
        a = a->next;
    }
    cout << endl;

    cout << "deleting..." << endl;
    int count = 1;
    a = newHead;
    while (a != nullptr) {
        cout << "delete pointer " << count << "..." << endl;
        ListNode *temp = a->next;
        delete a;

        a = temp;
        ++count;
    }

    return 0;
}

// 翻转整个链表
ListNode* reverse(ListNode* a) {
    ListNode *pre, *cur, *nxt;
    pre = nullptr;
    cur = nxt = a;
    while(cur != nullptr) {
        nxt = cur->next;
        cur->next = pre;

        pre = cur;
        cur = nxt;
    }

    return pre;
}

// 翻转指定区间[ａ,b)的链表
ListNode* reverse(ListNode* a, ListNode* b) {
    ListNode *pre, *cur, *nxt;
    pre = nullptr;
    cur = nxt = a;
    while(cur != b) {
        nxt = cur->next;
        cur->next = pre;

        pre = cur;
        cur = nxt;
    }

    return pre;
}

// 翻转链表，每隔k个节点翻转一次
ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr) return nullptr;

    ListNode *a, *b;
    a = b = head;
    for (int i = 0; i < k; ++i) {
        if (b == nullptr) return head;
        b = b->next;
    }

    ListNode* newHead = reverse(a, b);
    a->next = reverseKGroup(b, k);
    return newHead;
}