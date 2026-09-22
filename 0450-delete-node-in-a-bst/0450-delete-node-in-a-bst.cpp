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
    // TreeNode* search(TreeNode* root, int &tar){
    //     if(!root)   return NULL;
    //     if(root->val == tar)    return root;
    //     else if(root->val > tar)    root = search(root->left, tar);
    //     else   root = search(root->right, tar);
    //     return root;
    // }

    int maxVal(TreeNode* root){
        if(!root->right)   return root->val;
        return  maxVal(root->right);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return NULL;

        if(key == root->val){
            if(!root->left && !root->right) return nullptr;
            else if(!root->left && root->right) return root->right;
            else if(root->left && !root->right) return root->left;
            else{
                int maxi = maxVal(root->left);
                root->val = maxi;
                root->left = deleteNode(root->left, maxi);
            }
        }
        else if(key > root->val)    root->right = deleteNode(root->right, key);
        else if(key < root->val)    root->left = deleteNode(root->left, key);

        return root;
    }
};