class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // If there is only one node, deleting the middle
        // means returning an empty list.
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is the middle node
        prev->next = slow->next;
        delete slow;

        return head;
    }
};