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
public:
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder,int preS, int preE, int inS, int inE){
        // Write your code here
        if(preS > preE || inS > inE)	return NULL;
        int lpreS = preS+1;
        int linS = inS + 0;
        int linE;
        int rootData = preorder[preS]; 
        int i=inS;
        while(inorder[i]!=rootData){
            i++;
        }
        linE = i-1;
        int lpreE = lpreS + (linE - linS);
        TreeNode* root = new TreeNode(preorder[preS]);
        int lprel = lpreS + lpreE;
        int linl = linS + linE;
        root->left = buildTree(preorder, inorder, lpreS, lpreE, linS, linE);
        int rinS = linE + 2;
        int rpreS = lpreE + 1; 
        int rpreE = preE;
        int rinE = rpreE;//inE
        root->right = buildTree(preorder, inorder, rpreS, rpreE, rinS, rinE);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preLength = preorder.size();
        int inLength = inorder.size();
        return buildTree(preorder, inorder, 0, preLength-1, 0, inLength-1);
    }
};
