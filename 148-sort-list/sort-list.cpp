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
    ListNode*middle(ListNode*head){
        ListNode*slow=head;
        ListNode*fast=head->next;
        while (fast!=NULL&&fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode*merge(ListNode* a,ListNode* b) {
        ListNode temp(0);
        ListNode*tail=&temp;
     while (a!=NULL&&b!=NULL) {
            if (a->val<= b->val) {
           tail->next=a;
                a=a->next;
            } else {
                tail->next = b;
                b=b->next; }
            tail=tail->next;
        }
        tail->next=(a!=NULL)?a:b;
        return temp.next;}
    ListNode* sortlist(ListNode* head) {
        if (head==NULL||head->next==NULL) {
            return head;
        }
        ListNode*mid=middle(head);
        ListNode*right=mid->next;
        mid->next=NULL;
        ListNode*leftSorted=sortlist(head);
        ListNode*rightSorted=sortlist(right);
        return merge(leftSorted,rightSorted);
    }
public:
    ListNode* sortList(ListNode* head) {
        return sortlist(head);
    }
};
