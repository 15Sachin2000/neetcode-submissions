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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        int count=1;
        ListNode* tmp=head;
        ListNode* pre=NULL;
        ListNode* firstPre=NULL;
        ListNode* first=NULL;
        ListNode* second=NULL;
        while(tmp){
            if(count==left){
                firstPre=pre;
                first=tmp;
            }
            if(count==right){
                second=tmp;
                if(firstPre){
                    firstPre->next=tmp;
                }
                first->next=tmp->next;
            }
            ListNode* ptr=tmp->next;
            if(count>=left && count<=right){
                tmp->next=pre;
            }
            count++;
            pre=tmp;
            tmp=ptr;
        }
        if(!firstPre) return second;
        return head;
    }
};