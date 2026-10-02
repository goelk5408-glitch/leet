class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = new ListNode();
        ListNode* l3 = head;

        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry != 0) {

            int val1 = 0;
            int val2 = 0;

            if (l1 != NULL) {
                val1 = l1->val;
            }

            if (l2 != NULL) {
                val2 = l2->val;
            }

            l3->val = (val1 + val2 + carry) % 10;
            carry = (val1 + val2 + carry) / 10;

            if (l1 != NULL) {
                l1 = l1->next;
            }

            if (l2 != NULL) {
                l2 = l2->next;
            }

            if (l1 != NULL || l2 != NULL || carry != 0) {
                l3->next = new ListNode();
                l3 = l3->next;
            }
        }

        return head;
    }
};