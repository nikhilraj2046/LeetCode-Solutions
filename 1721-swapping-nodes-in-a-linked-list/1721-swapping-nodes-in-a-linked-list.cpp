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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*temp=head;
        vector<int>ans;
        while(temp){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int n=ans.size();
        int i=0,j=n-1,cnt=0;
        swap(ans[k-1],ans[n-k]);
        ListNode*head1=new ListNode(ans[0]);
        ListNode*t=head1;
        for(int i=1;i<n;i++){
            ListNode*temp=new ListNode(ans[i]);
            t->next=temp;
            t=t->next;
        }
        return head1;
    }
};