#include <cstdio>
#include <cstdlib>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode* result = NULL;
        // 挨个复制
        copy(pHead);
        result = pHead -> next;
        // 分开
        split(pHead);
        return result;
    }

    // 挨个复制
    RandomListNode* copy(RandomListNode* pHead){
        RandomListNode* nxt = nullptr, *h = pHead;
        while (pHead != nullptr)
        {
            /* code */
            nxt = pHead -> next;
            pHead -> next =  createNewNode(pHead);
            pHead = nxt;
        }

        pHead = h;
        // 现在才开始连接random
        while (pHead != nullptr)
        {
            /* code */
            nxt = pHead -> next;
            nxt -> random = pHead -> random -> next;
            pHead = nxt -> next;
        }
        
        return h;
    }

    RandomListNode* createNewNode(RandomListNode* pHead) {
        RandomListNode* tmp = new RandomListNode(pHead->label);
        tmp->next = pHead->next;
        return tmp;
    }

    void split(RandomListNode* pHead){
        // 恢复成原有的next指针
        while (pHead != nullptr)
        {
            /* code */
            RandomListNode* nxt = pHead -> next;
            pHead -> next = nxt -> next;
            pHead = nxt -> next;
            if (pHead != nullptr) {
                nxt -> next = pHead -> next;
            }
        }
    }
};

