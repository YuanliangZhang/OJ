//https://leetcode.com/problems/add-two-numbers/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
  public:
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
        int up_to = 0, one_sum;
        while ((nullptr != l1) && (nullptr != l2))
        {
            one_sum = l1->val + l2->val + up_to;
            if (one_sum >= 10)
            {
                up_to = 1;
                one_sum -= 10;
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
        if (nullptr == l1 && nullptr == l2)
        {
            if (1 == up_to)
            {
                temp = new ListNode(1);
                sum->next = temp;
                sum = sum->next; 
                up_to = 0;   
            }
        }
        else
        {
            if (nullptr == l2)
            {
                one_sum = l1->val + up_to;
                if (one_sum >= 10)
                {
                    up_to = 1;
                    one_sum -= 10;
                }
                else
                {
                    up_to = 0;
                }
                temp = new ListNode(one_sum);
                sum->next = temp;
                sum = sum->next;
                l1 = l1->next;
            }
            else if (nullptr == l1)
            {
                one_sum = l2->val + up_to;
                if (one_sum >= 10)
                {
                    up_to = 1;
                    one_sum -= 10;
                }
                else
                {
                    up_to = 0;
                }
                temp = new ListNode(one_sum);
                sum->next = temp;
                sum = sum->next;
                l2 = l2->next;
            }
        }
        while (nullptr != l1)
        {
            one_sum = l1->val + up_to;
            if (one_sum >= 10)
            {
                up_to = 1;
                one_sum -= 10;
            }
            else
            {
                up_to = 0;
            }           
            temp = new ListNode(one_sum);
            sum->next = temp;
            sum = sum->next;
            l1 = l1->next;
        }
        while (nullptr != l2)
        {
            one_sum = l2->val + up_to;
            if (one_sum >= 10)
            {
                up_to = 1;
                one_sum -= 10;
            }
            else
            {
                up_to = 0;
            }    
            temp = new ListNode(one_sum);
            sum->next = temp;
            sum = sum->next;
            l2 = l2->next;
        }
        if (1 == up_to)
        {
            temp = new ListNode(1);
            sum->next = temp;
            sum = sum->next;
        }
        return head->next;
    }
};