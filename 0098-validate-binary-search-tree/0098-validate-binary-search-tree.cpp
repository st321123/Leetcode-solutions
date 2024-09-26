/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool solve(TreeNode *root, long long int lB,long long int uB)
    {
        if(root == NULL)
        return true;

        if(root->val>lB && root->val <uB)
        {
            bool left = solve(root->left, lB, root->val);
            bool right = solve(root->right , root->val, uB);

            
            return (left && right);
        }

        else
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        long long int lB= -4294967296;
        long long int uB= 4294967296;
        bool ans = solve(root, lB, uB);

        return ans;
    }
};