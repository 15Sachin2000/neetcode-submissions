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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==0 || !head || !head->next) return head;
        int count=0;
        ListNode* curr=head;
        while(curr){
            count++;
            curr=curr->next;
        }
        if(count<k){
            return head;
        }
        curr=head;
        ListNode* pre=NULL;
        count=k; 
        while(count--){
            ListNode* tmp=curr->next;
            curr->next=pre;
            pre=curr;
            curr=tmp;
        }
        head->next=reverseKGroup(curr,k);
        return pre;
    }
};
