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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*a=list1;
        ListNode*b=list2;
        ListNode*dummy=new ListNode(-1);
        ListNode*temp=dummy;
        if(a==nullptr) return b;
        if(b==nullptr) return a;
        while(a!=nullptr && b!=nullptr){
        if(a->val>b->val){
        temp->next=b;
        b=b->next;
       
       }
       else{
        temp->next=a;
        a=a->next;
       }
         temp=temp->next;
        }
        if(a){
            temp->next=a;
        }
        else temp->next=b;
        ListNode*res=dummy->next;
        delete dummy;
        return res;
    }
};