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
    
    struct cmp {

        bool operator()(ListNode* a, ListNode* b){

            return a->val > b->val;
        }
    };


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for(int i=0;i<lists.size();i++){
         
         if(lists[i]!=NULL)
         pq.push(lists[i]);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!pq.empty()){

            ListNode* curr = pq.top();

            pq.pop();
            if(curr->next!=NULL)
            pq.push(curr->next);

            temp->next = curr;
            temp = temp->next;
        }

        return dummy->next;

        
    }
};