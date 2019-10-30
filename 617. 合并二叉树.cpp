/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
	递归
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL)		//一个为空时返回另一个
            return t2;
        
        if (t2 == NULL)
            return t1;
        
        t1->val += t2->val;	//两个都不为空时相加
        t1->left = mergeTrees(t1->left, t2->left);	//左节点右节点递归
        t1->right = mergeTrees(t1->right, t2->right);
        
        return t1;
    }
};