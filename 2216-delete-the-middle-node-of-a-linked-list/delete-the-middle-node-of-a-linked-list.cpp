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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return NULL;
        }
        int count=1;
        ListNode*a=head;
        while(a->next!=NULL){
            a=a->next;
            count++;
        }

        ListNode*temp=head;
       for(int i =1;i<count/2;i++){
        temp=temp->next;
       }
       if (temp->next->next!=NULL)
       {
        temp->next=temp->next->next;
       }
       else temp->next=NULL;
        
   return head; }
};