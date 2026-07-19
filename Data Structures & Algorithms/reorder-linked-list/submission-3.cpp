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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
            if(fast->next){
                fast=fast->next;
            }
        }
        ListNode* pre=NULL;
        ListNode* tmp=slow->next;
        slow->next=NULL;
        while(tmp){
            ListNode* ptr=tmp->next;
            tmp->next=pre;
            pre=tmp;
            tmp=ptr;
        }
        ListNode* a=head;
        ListNode* b=fast;
        while(a && b){
            ListNode* ptr1=a->next;
            ListNode* ptr2=b->next;
            a->next=b;
            b->next=ptr1;
            a=ptr1;
            b=ptr2;
        }
        return;
    }
};
