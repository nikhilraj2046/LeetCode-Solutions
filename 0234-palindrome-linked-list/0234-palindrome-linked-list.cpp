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
    private:
     ListNode*reverse(ListNode*head){
        if(head==NULL || head->next==NULL) return head;
         ListNode*newhead=reverse(head->next);
         ListNode*front=head->next;
         front->next=head;
         head->next=nullptr;
         return newhead;
     }
public:
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*temp=reverse(slow->next);
        ListNode*first=head;
        ListNode*second=temp;
        while(second){
            if(first->val!=second->val){
                reverse(temp);
                return false;
            }
            first=first->next;
            second=second->next;

        }
        reverse(temp);
        return true;
    }
};