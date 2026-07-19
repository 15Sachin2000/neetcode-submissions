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
   struct cmp{
     bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
     }
   };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(ListNode* l:lists){
            pq.push(l);
        }
        ListNode* tmp=new ListNode(-1);
        ListNode* ptr=tmp;
        while(!pq.empty()){
            ListNode* p=pq.top();
            cout<<p->val<<" ";
            pq.pop();
            ptr->next=p;
            ptr=ptr->next;
            if(p->next){
                pq.push(p->next);
            }
        }
        return tmp->next;
    }
};
