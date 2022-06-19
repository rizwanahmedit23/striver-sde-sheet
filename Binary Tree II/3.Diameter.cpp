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
#include <utility>
class Solution {
public:
    pair<int,int> diameterOfBinaryTreeHelper(TreeNode* root){
        if(root == NULL){
            pair<int,int> ans;
            ans.first = 0;
            ans.second = 0;
            return ans;
        }
        pair<int,int> leftAns = diameterOfBinaryTreeHelper(root->left);
        pair<int,int> rightAns = diameterOfBinaryTreeHelper(root->right);
        int lh = leftAns.first;
        int rh = rightAns.first;
        int ld = leftAns.second;
        int rd = rightAns.second;
        
        int height = max(lh, rh) + 1;
        pair<int,int> ans;
        ans.first = height;
        ans.second = max(lh+rh, max(ld, rd));
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
       pair<int,int> ans = diameterOfBinaryTreeHelper(root); 
        return ans.second;
    }
};
