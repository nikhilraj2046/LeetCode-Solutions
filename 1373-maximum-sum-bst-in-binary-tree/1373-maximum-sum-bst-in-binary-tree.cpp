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
    struct info{
        bool isBST;
        int mini;
        int maxi;
        int sum;
    }; 
    int maxsum=0;
    private:
    info solve(TreeNode*Node){
        if(Node==nullptr) return {true,INT_MAX,INT_MIN,0};
        info left=solve(Node->left);
        info right=solve(Node->right);
        if(left.isBST && right.isBST && left.maxi<Node->val && Node->val<right.mini){
            int total=left.sum+right.sum+Node->val;
            maxsum=max(maxsum,total);
            return {
                true, 
                min(Node->val, left.mini), 
                max(Node->val, right.maxi), 
                total
            };
        }
        else{
            return {false,0,0,0};
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        maxsum=0;
        solve(root);
        return maxsum;
    }
    
};