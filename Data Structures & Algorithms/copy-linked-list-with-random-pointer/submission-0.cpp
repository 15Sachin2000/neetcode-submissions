/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* solve(Node* head,unordered_map<Node*,Node*> &mp){
        if(!head) return NULL;
        if(mp.find(head)!=mp.end()){
            return mp[head];
        }
        Node* ans=new Node(head->val);
        mp[head]=ans;
        ans->random=solve(head->random,mp);
        ans->next=solve(head->next,mp);
        return ans;
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        return solve(head,mp);
    }
};
