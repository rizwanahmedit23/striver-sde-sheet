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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//if root is NULL, return NULL.
        if(root == NULL)    return NULL;
        
//root is equal to p or q, return root.
        if(root == p || root == q)  return root;
        TreeNode* a = lowestCommonAncestor(root->left, p, q);
        TreeNode* b = lowestCommonAncestor(root->right, p, q);
    

// If handles 2 cases, a==NULL && b==NULL and a==NULL && b!=NULL
        if(a == NULL)   return b; 
// If a!=NULL && b==NULL
        else if(b == NULL)  return a;
// If a!=NULL && b!=NULL
        else return root;
        
    }
};
