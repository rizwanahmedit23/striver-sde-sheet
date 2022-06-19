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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)	return vector<vector<int>>();
        
        vector<vector<int>> ans;int i=0;
        stack<TreeNode *> pendingNodes;
        pendingNodes.push(root);
        bool check = false;
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            vector<TreeNode*> temp;
            vector<int> row;
            for(int i=0;i<size;i++){
                TreeNode *front = pendingNodes.top();
                pendingNodes.pop();
                row.push_back(front->val);
                if(check == false){
                    if(front -> left!= NULL)	temp.push_back(front->left);
                    if(front -> right!= NULL)	temp.push_back(front->right);
                }
                else{
                    if(front -> right!= NULL)	temp.push_back(front->right);
                    if(front -> left!= NULL)	temp.push_back(front->left);                
                }
            }
            i++;
            for(int i=0;i<temp.size();i++){
                pendingNodes.push(temp[i]);
            }
            ans.push_back(row);
            check = !check;
        }
        return ans;
    }
};
