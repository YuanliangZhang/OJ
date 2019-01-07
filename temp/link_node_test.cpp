//============================================================================
// Name        : online_oj_nowcoder.cpp
// Author      : zyl
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(NULL) {
      }
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (nullptr == l1)
        return l2;
    if (nullptr == l2)
        return l1;
    ListNode *sum = nullptr, *head;
    sum = new ListNode(0);
    head = sum;
    ListNode *temp = nullptr;
    sum = new ListNode(0);
    int up_to = 0, one_sum;
    while ((nullptr != l1) && (nullptr != l2))
    {
        one_sum = l1->val + l2->val + up_to;
        if (one_sum > 9)
        {
            up_to = 1;
        }
        else
        {
            up_to = 0;
        }
        temp = new ListNode(one_sum);
        sum->next = temp;
        sum = sum->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (nullptr != l1)
    {
        temp = new ListNode(l1->val + up_to);
        sum->next = temp;
        sum = sum->next;
        l1 = l1->next;
    }
    while (nullptr != l2)
    {
        temp = new ListNode(l2->val + up_to);
        sum->next = temp;
        sum = sum->next;
        l2 = l2->next;
    }
    return head->next;
}

int main() {
    ListNode * l1, *l2, *res;
    ListNode * head, *tail, *temp;
    head = new ListNode(0);
    tail = head;
    vector<int> vec = {2,4,3};
    for (int i=0; i < vec.size(); i++)
    {
        temp = new ListNode(vec[i]);
        tail -> next = temp;
        tail = temp;
    }
    l1 = head->next;
    ListNode * head, *tail, *temp;
    head = new ListNode(0);
    tail = head;
    vector<int> vec = {5,6,4};
    for (int i=0; i < vec.size(); i++)
    {
        temp = new ListNode(vec[i]);
        tail -> next = temp;
        tail = temp;
    }
    l2 = head->next;
    res = addTwoNumbers(l1, l2);
    cout << res->val;
	return 0;
}
