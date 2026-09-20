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
    ListNode*findNthNode(ListNode*temp,int k){
        int cnt=1;
        while(temp){
            if(cnt==k) return temp;
            cnt++;
            temp=temp->next;

        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
          if (!head || !head->next || k == 0) {
            return head;
        }
        int len=1;
        ListNode* tail=head;
        while(tail->next){
            len++;
            tail=tail->next;
        }
        k=k%len;
        if(k==0) return head;
        tail->next=head;
        ListNode*newlastnode=findNthNode(head,len-k);
        head=newlastnode->next;
        newlastnode->next=nullptr;
        return head;
    }
};