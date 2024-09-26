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
    void solve(TreeNode *root,int k, int &c, int &ans)
    {
        if(root == NULL)
        return ;

        
        solve(root->left,k,c,ans);
        c = c+1;
        if(c == k )
        {
            ans = root->val;
            return ;
        }
        solve(root->right,k,c,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        
        int count = 0;
        int ans = 0;
        solve(root, k,count,ans);

        return ans;
    }
};