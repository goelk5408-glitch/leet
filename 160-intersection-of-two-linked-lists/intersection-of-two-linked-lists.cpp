/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*a=headA;
        ListNode*b=headB;
    
        unordered_map<ListNode*,int>mpp;
        while(a!=NULL){
            mpp.insert({a,1});
            a=a->next;
        }

        while(b!=NULL){
            if(mpp.find(b)!=mpp.end()){
                return b;
                
            }
            else {
                b=b->next;
            }

        }

   return NULL; }
};