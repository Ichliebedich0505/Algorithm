#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        while (q.size() > 0)
        {
            /* code */
            TreeNode* curNode = q.front();
            q.pop();
            res.push_back(curNode->val);
            if(curNode->left!=nullptr){
                q.push(curNode->left);
            }
            if(curNode->right!=nullptr){
                q.push(curNode->right);
            }
        }
        return res;
    }
};
int main(){

}