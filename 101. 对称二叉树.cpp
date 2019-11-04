/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {         
        return helper(root, root);
    }
    
    bool helper(TreeNode* t1, TreeNode* t2)
    {
        if (t1 == NULL && t2 == NULL)	//先判两个都为空
            return true;
        if (t1 == NULL || t2 == NULL)	//再判其中一个为空，这里已经不可能两个都为空了
            return false;
        
        return (t1->val == t2->val) && 
			helper(t1->left, t2->right) && 
			helper(t1->right, t2->left);
    }
};