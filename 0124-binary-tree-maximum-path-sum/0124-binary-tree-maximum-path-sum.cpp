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
    int max_s=INT_MIN;
    private:
    int solve(TreeNode*node){
        if(node==nullptr) return 0;
        int left=max(0,solve(node->left));
        int right=max(0,solve(node->right));
        int total=node->val+left+right;
        max_s=max(max_s,total);
        return node->val+max(left,right);

    }
public:
    int maxPathSum(TreeNode* root) {
       max_s=INT_MIN;   
        solve(root);
        return max_s;
    }
};