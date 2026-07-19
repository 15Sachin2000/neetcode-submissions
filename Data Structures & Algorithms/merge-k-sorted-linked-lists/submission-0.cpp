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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int minIndex=-1;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                if(minIndex==-1){
                    minIndex=i;
                }else{
                    if(lists[minIndex]->val>lists[i]->val){
                        minIndex=i;
                    }
                }
            }
        }
        if(minIndex==-1){
            return NULL;
        }
        ListNode* tmp=lists[minIndex];
        lists[minIndex]=tmp->next;
        tmp->next=mergeKLists(lists);
        return tmp;
    }
};
