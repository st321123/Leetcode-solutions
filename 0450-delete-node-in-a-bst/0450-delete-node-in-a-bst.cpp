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
   TreeNode * maxN(TreeNode *root)
    {
        if(root->right == NULL)
        return root;

       return  maxN(root->right);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
        return NULL;
        if(root->val == key)
        {

            if(root->left == NULL && root->right == NULL)
            {
                TreeNode * newNode = root;
                // cout<<"Leaf ";
                delete(newNode);
                return NULL;
            }
            else if(root->left == NULL)
            {
                // cout<<"LEft is null"<<root->val;
                TreeNode *childSub = root->right;
                delete(root);
                return childSub;

            }
             else if(root->right == NULL)
            {
                // cout<<"Right is NULL"<<root->val;
                TreeNode *childSub = root->left;
                delete(root);
                return childSub;

            }
            else
            {
                
                TreeNode * newNo = maxN(root->left);                
                root->val= newNo->val;
                root->left = deleteNode(root->left, newNo->val); 
                return root;
                
            }
        }
        else if(root->val >key )
        {
            root->left = deleteNode(root->left, key);
        }
        else
        root->right = deleteNode(root->right, key);

        return root;
    }
};