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
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* k=NULL;
        while(fast && fast->next){
            k=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow==head){
            return;
        }
        if(k){
            k->next=NULL;
        }
        ListNode* pre=NULL;
        while(slow){
            ListNode* tmp=slow->next;
            slow->next=pre;
            pre=slow;
            slow=tmp;
        }
        fast=head;
        ListNode* q=NULL;
        while(fast && pre){
            if(q){
                q->next=fast;
            }
            ListNode* tmp=fast->next;
            fast->next=pre;
            q=pre;
            pre=pre->next;
            fast=tmp;
        }
    }
};
