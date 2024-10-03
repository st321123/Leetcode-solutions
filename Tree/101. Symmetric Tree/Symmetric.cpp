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
    bool trave(TreeNode* p,TreeNode* q)
    {
       if( p == NULL && q== NULL)
        return true;

         if(p != NULL && q != NULL )
        {
            if (p->val == q->val)
            {
                bool a = trave(p->left, q->right);
                bool b = trave(p->right, q->left);

                return (a &&b);

            }
            else
            return false;
            
        }
           

        return false;
        
    }
      
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode *p = root;
        TreeNode *q = root;
       bool res = trave(p,q);
   

        return res;
    }
};
