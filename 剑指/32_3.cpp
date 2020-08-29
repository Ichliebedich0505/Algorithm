#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    vector<vector<int>> Print(TreeNode* pRoot) {
        if (pRoot == nullptr) return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;
        stack<int> s;
        q.push(pRoot);
        int level=0, toBePrinted=1, nextToBePrinted = 0;
        while (q.size() > 0)
        {
            /* code */
            TreeNode* curNode = q.front();
            q.pop();
            if(level % 2 == 0){
                if(level >= res.size()){
                    res.push_back({curNode->val});
                }else
                {
                    /* code */
                    res[level].push_back(curNode->val);
                }
            }
            else {
                s.push(curNode->val);
            }
            
            toBePrinted--;
            if(curNode->left!=nullptr){
                q.push(curNode->left);
                nextToBePrinted ++;
            }
            if(curNode->right!=nullptr){
                q.push(curNode->right);
                nextToBePrinted ++;
            }
            // 本层打印完了
            if(toBePrinted == 0){
                if (level % 2 == 1){
                    res.push_back({});
                    while (!s.empty())
                    {
                        /* code */
                        res[level].push_back(s.top());
                        s.pop();
                    }
                }
                level ++;
                toBePrinted = nextToBePrinted;
                nextToBePrinted = 0;
                
                
            }
        }
        return res;
    }
};
int main(){

}

