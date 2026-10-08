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

        if (list1 == NULL && list2 != NULL)
            return list2;
        if (list2 == NULL && list1 != NULL)
            return list1;
        if (list1 == NULL && list2 == NULL)
            return NULL;

        ListNode* a = list1;
        ListNode* b = list2;
        if (a->val > b->val) {
            ListNode* temp = a;
            a = b;
            b = temp;
        }

        ListNode* head = a;

        while (a->next != NULL&&b!=NULL ) {

            if (a->next->val > b->val) {
                ListNode* next = a->next;

                a->next = b;
                b = next;
            }

            a = a->next;
        }
         if (b != NULL) {
            a->next = b;
        }

       

        return head;
    }
};