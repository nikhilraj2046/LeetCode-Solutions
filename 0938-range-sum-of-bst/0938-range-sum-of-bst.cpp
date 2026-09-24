/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// class Solution {
// public:
//     void inorder(TreeNode*root,vector<int>&arr){
//         if(root==nullptr) return ;
//         inorder(root->left,arr);
//         arr.push_back(root->val);
//         inorder(root->right,arr);
      
//     }
//     int rangeSumBST(TreeNode* root, int low, int high) {
//         // if(root==nullptr) return 0;
//         vector<int>arr;
//         inorder(root,arr);
//         int n=arr.size();
//         int sum=0;vector<int>ans;
//         for(int i=0;i<n;i++){
//             if(low<=arr[i] && arr[i]<=high){
//                 ans.push_back(arr[i]);
//             }
//         }
//         for(int i=0;i<ans.size();i++){
//             sum+=ans[i];
//         }
//         return sum;
//     }
// }; 
class Solution {
public:
    void inorder(TreeNode* root, int low, int high, int &sum) {
        if (root == nullptr)
            return;
        inorder(root->left, low, high, sum);
        if (root->val >= low && root->val <= high)
            sum += root->val;
        inorder(root->right, low, high, sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        inorder(root, low, high, sum);
        return sum;
    }
};