#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* origin = head;
        ListNode* forward = head, *curNode = head, *lastNode = nullptr;
        while (n > 0)
        {
            /* code */
            forward = forward->next;
            n--;
        }
        while (forward != nullptr)
        {
            /* code */
            lastNode = curNode;
            curNode = curNode ->next;
            forward = forward ->next;
        }
        if(curNode == origin){
        // 有可能删到了头节点这一本体
            return head->next;
        }else
        {
            /* code */
            lastNode->next = curNode->next;
            delete curNode;
            curNode = nullptr;
            return origin;
        }
        
        
        
    }
};