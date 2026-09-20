/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode*temp=head1;
        unordered_map<ListNode*,int>mp;
        while(temp){
            mp[temp]=1;
            temp=temp->next;
        }
        ListNode*temp1=head2;
        while(temp1){
            if(mp.find(temp1)!=mp.end()){
                return temp1;
            }
            temp1=temp1->next;
        }
        return nullptr;
    }

};