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
int cameras=0;
int dfs(TreeNode*root){
    //Null node considered covered
    if(root==NULL) return 2;
    int left=dfs(root->left);
    int right=dfs(root->right);
    //if any child is not covered
    if(left==0 || right==0){
        cameras++;
        return 1; //Camera placed here
    }
    // if any child has a camera
    if(left==1 || right==1) return 2; // current node is covered
    //both chidren are coverd
    return 0;  /// current node has not coverd
}
    int minCameraCover(TreeNode* root) {
        // if root is not covered placed camersa at root
        if(dfs(root)==0) cameras++;
        return cameras;
        
    }
};