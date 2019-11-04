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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
                   
    int dfs(TreeNode* root, int &sum)
    {
        if (root == NULL)
            return 0;
        
        int left = dfs(root->left, sum);
        int right = dfs(root->right, sum);
        sum = max(left + right, sum);		// 某节点最大直径 = 左树高度 + 右树高度
        
        return max(left, right) + 1;		// 需要返回树的高度，以供使用
    }
};