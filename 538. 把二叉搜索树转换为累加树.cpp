/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//https://leetcode-cn.com/problems/convert-bst-to-greater-tree/solution/java-dfsni-zhong-xu-di-gui-bian-li-jian-ji-ji-bai-/
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root != NULL)
        {
            helper(root, 0);
        }
        
        return root;
    }
    
    int helper(TreeNode* root, int sum)
    {
        if (root == NULL)
            return sum;
        
        sum = helper(root->right, sum);
        root->val += sum;
        sum = helper(root->left, root->val);
        
        return sum;
    }
};