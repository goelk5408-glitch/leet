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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
    return head;
        ListNode*curr=head;
        int size=1;
        while(curr->next!=NULL){
            curr=curr->next;
            size++;
        }
        
        
         k=   k%size;
        
        curr->next=head;
        ListNode*x=head;
        ListNode*newhead;
        for(int i =1;i<size-k;i++){
            x=x->next;

        }
        newhead=x->next;
        x->next=NULL;
            
        
        
   return newhead; }
};