#include <bits/stdc++.h>

// 1、用二维指针存储返回信息
// 2、不能直接生成空的二维指针来存储一维指针地址，，这个道理很简单
// 3、按照中序遍历的风格只需在两个递归调用中间有操作即可。
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr){
            return nullptr;;;;;
        }
        TreeNode* pLastNode = nullptr;
        core(pRootOfTree, &pLastNode);
        TreeNode* p = nullptr;
        for(p = pRootOfTree; p->left != nullptr; p = p->left){

        }
        return p;
        
    }

    void core(TreeNode* pRootOfTree, TreeNode** pLastNode){
        if (pRootOfTree == nullptr) {
            
            return;
        }

        if (pRootOfTree->left != nullptr){
            // 返回左边最后一个
            core(pRootOfTree->left, pLastNode);
        }

        pRootOfTree -> left = *pLastNode;
        if (*pLastNode != nullptr) {
            (*pLastNode) -> right = pRootOfTree;
        }
        

        // 返回右边第一个
        *pLastNode = pRootOfTree;
        
        if (pRootOfTree->right != nullptr) {
            core(pRootOfTree->right, pLastNode);
        }
    }
};

int main() {

}