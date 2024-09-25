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
   bool solve(TreeNode* root, map<int, int> &mp, int lB,int uB)
   {
        if(root == NULL)
        return true;

        if(root->val >= lB && root->val <= uB)
        {
           
            mp[root->val] += 1;
            bool left = solve(root->left, mp, lB, root->val);
            bool right = solve(root->right, mp, root->val, uB);
        }
        else
        return false;

        return true;
   }
        
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        map<int, int > mp;
        int lB = INT_MIN;
        int uB = INT_MAX;
        bool res = solve( root, mp, lB, uB);
        if(!res)
          return ans;
       
       map<int, int> :: iterator itr = mp.begin();
       int maxi = 0;
       while(itr != mp.end())
       {
        int b = itr->second ;
        
        maxi = max(maxi,b );
        itr++;
       }
       itr = mp.begin();
        
       while(itr != mp.end())
       {
        int a = itr->second;
        if(a == maxi)
        {
            int b = itr->first;
              ans.push_back(itr->first);
        }
      
        itr++;
       }
       return ans;
    }
};