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
    int hcf(int a,int b){
        while(a!=0){
            int tmp=b%a;
            b=a;
            a=tmp;
        }
        return b;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ptr=head;
        while(ptr->next){
            int a=ptr->val;
            int b=ptr->next->val;
            if(a>b) swap(a,b);
            int result=hcf(a,b);
            ptr->next=new ListNode(result,ptr->next);
            ptr=ptr->next->next;
        }
        return head;
    }
};