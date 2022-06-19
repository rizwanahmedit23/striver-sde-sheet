TreeNode<int>* buildTree(vector<int>& postorder, vector<int>& inorder, int postS, int postE, int inS, int inE) {
    // Write your code here
    if(postS>postE || inS>inE)    return NULL;
    int lpostS = postS;
    int linS = inS;
    int linE;
    int rootData = postorder[postE];
    int i;
    for(i=inS; inorder[i]!=rootData;i++){
        
    }
    linE = i-1;
    int lpostE = (linE - linS) + lpostS;
    int rinS = linE+2;
    int rinE = inE;
    int rpostS = lpostE + 1;
    int rpostE = postE - 1;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    root->left = buildTree(postorder, inorder, lpostS , lpostE, linS, linE);
    root->right = buildTree(postorder, inorder, rpostS , rpostE, rinS, rinE);
    return root;  
}
