#include <cstdlib>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr) return pHead;
        // 每次保存下下一位
        ListNode* curNode = pHead, *lastNode = nullptr;
        while (curNode->next != nullptr)
        {
            /* code */
            ListNode* tmp = curNode->next;
            curNode -> next = lastNode;
            lastNode = curNode;
            curNode = tmp;
        }
        curNode -> next = lastNode;
        return curNode;
        
    }
};