//https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution
{
  public:
    ListNode *ReverseList(ListNode *pHead)
    {
        ListNode *loop=pHead, *now=pHead, *pre=nullptr;
        while(loop)
        {
            now = loop;
            loop = now->next;
            now->next = pre;
            pre = now;
        }
        return now;

    }
};