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
    ListNode* removeNodes(ListNode* head) {
        stack<int>st;
        ListNode*temp=head;
        while(temp){
            while(!st.empty() && st.top()<temp->val){
                st.pop();
            }
            st.push(temp->val);
            temp=temp->next;
        }
       ListNode* head1  = nullptr;
        while (!st.empty()) {
        ListNode*temp = new ListNode(st.top());
        temp->next = head1;
        head1=temp;
        st.pop();
    }
return head1;
    }
};