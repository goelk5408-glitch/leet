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
    bool isPalindrome(ListNode* head) { 
        int count=1; 
        ListNode*s=head;
        ListNode*temp=head; 
        while(temp->next!=NULL){ 
            temp=temp->next; 
            count++; 
 
        } 
         
            ListNode*tem=head; 
        for(int i=1;i<=count/2;i++){ 
            tem=tem->next; 
        } 
        ListNode*prev=NULL; 
        ListNode*nex=tem->next; 
        ListNode*curr=tem; 
        while(curr!=NULL){ 
            nex=curr->next;
            curr->next=prev; 
            prev=curr; 
            curr=nex; 
        } 
         
         while(prev!=NULL){
            if (prev->val!=s->val){
                return false;
            }
            prev=prev->next;
            s=s->next;
         }
              return true;  } 
}; 