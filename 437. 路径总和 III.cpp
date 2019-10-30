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
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        
        return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);  // 问题分解
    }
    
    // 以root节点开始的路径总数
    int helper(TreeNode* root, int sum)
    {
        if (root == NULL)
            return 0;
        
        int res = 0;
        if (root->val == sum)
            res++;
        
        res += helper(root->left, sum - root->val);
        res += helper(root->right, sum - root->val);
        
        return res;
    }
};