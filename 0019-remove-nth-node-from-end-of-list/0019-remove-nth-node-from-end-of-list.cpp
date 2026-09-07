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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr)
            return nullptr;
        ListNode* temp = head;
        int cnt = 0;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        int size = (cnt - n) + 1;

        

        if (size == 1)
            return head->next;
            
        int pos = size - 1;
        temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};