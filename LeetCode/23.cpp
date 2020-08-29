#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        ListNode** curNodes = (ListNode**)malloc(sizeof(ListNode*)*size);
        for(int i = 0; i< size; i++){
            curNodes[i] = lists[i];
        }
        ListNode* newList = nullptr, *head = nullptr;
        bool stillLeft = true;

        while (stillLeft)
        {
            /* code */
            stillLeft = false;
            ListNode* minNode = nullptr;
            int minInd = -1;
            for(int i =0; i< size; i++){
                if(curNodes[i] != nullptr){
                    if(minNode == nullptr){
                        minNode = curNodes[i];
                        minInd = i;
                    }
                    else if(curNodes[i]->val < minNode->val){
                        minNode = curNodes[i];
                        minInd = i;
                    }else
                    {
                        /* code */
                        stillLeft = true;
                    }
                    
                }
            }
            if(minInd >= 0){
                curNodes[minInd] = curNodes[minInd]->next;
                if (curNodes[minInd] != nullptr){
                    stillLeft = true;
                }
            }
            if(newList == nullptr){
                newList = minNode;
                head = newList;
            }else
            {
                /* code */
                newList->next = minNode;
                newList = newList->next;
            }
            
        }
        return head;
    }
};