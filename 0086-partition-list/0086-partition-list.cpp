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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode*dummy1=new ListNode(-1);
        ListNode*dummy2=new ListNode(-1);
        ListNode*small=dummy1;
        ListNode*large=dummy2;
        ListNode*temp=head;
        while(temp){
            if(temp->val<x){
                small->next=temp;
                small=small->next;
            }
            else{
                large->next=temp;
                large=large->next;
            }
            temp=temp->next;
        }
        large->next=nullptr;
        small->next=dummy2->next;
        return dummy1->next;
    }
};