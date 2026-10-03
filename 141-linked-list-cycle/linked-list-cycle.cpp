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
    bool hasCycle(ListNode *head) {
        ListNode*a=head;
        unordered_set<ListNode*>st;
        while(a!=NULL){
         st.insert(a);
         if(st.find(a->next)!=st.end()){
            return true;
         }
         else {
            a=a->next;
         }
        }

        
   return false; }
};