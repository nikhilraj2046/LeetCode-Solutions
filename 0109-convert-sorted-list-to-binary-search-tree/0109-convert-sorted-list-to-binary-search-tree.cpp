/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        //Base cas
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return new TreeNode(head->val);
        //Finding middle node
        ListNode*prev=nullptr;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        //Break list into two parts;
        prev->next=nullptr;
        //slow become middle node
        TreeNode*newNode=new TreeNode(slow->val);
        //left half
        newNode->left=sortedListToBST(head);
        //right half
        newNode->right=sortedListToBST(slow->next);
        return newNode;
    }
};