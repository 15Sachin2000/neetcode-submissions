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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr=head;
        ListNode* tmp=head;
        while(n-- && tmp){
            tmp=tmp->next;
        }
        ListNode* pre=NULL;
        while(tmp){
            tmp=tmp->next;
            pre=ptr;
            ptr=ptr->next;
        }
        if(pre==NULL){
            return head->next;
        }
        pre->next=ptr->next;
        return head;
    }
};
