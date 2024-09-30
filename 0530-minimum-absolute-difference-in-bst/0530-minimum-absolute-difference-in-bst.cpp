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
     void solve(TreeNode *root, int &prev, int &next, int &ans)
    {
        if(root == NULL)        
            return ;
            solve(root->left,prev,next,ans );
            if(prev == INT_MAX)
            {
                prev = root->val;
                next = root->val;
            }
            else
            {
                next = root->val;
                int res = abs(next - prev );
                if(res < ans)
                    ans = res;
                prev = next;
                
            }
         
            
            solve(root->right, prev,next,ans); 
         
        
    }
      
    
public:
    int getMinimumDifference(TreeNode* root) {
        
        int prev = INT_MAX;
        int next = INT_MAX;
        int ans = INT_MAX;
        
        solve(root,prev,next,ans);
        
     
        
        return ans;
    }
};