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

   ListNode* sort(vector<ListNode*>& lists, int l, int r){

     if(l==r) return lists[l];

     int mid = (l+r)/2;

     ListNode* left = sort(lists, l, mid);
     ListNode* right = sort(lists, mid+1, r);

     return merge(left, right);
   }

   ListNode* merge(ListNode* head1, ListNode* head2){

      ListNode* dummy = new ListNode(-1);
      ListNode* temp = dummy;
      ListNode* curr1 = head1;
      ListNode* curr2 = head2;

      while(curr1!=NULL && curr2!=NULL){

         if(curr1->val <= curr2->val){

            ListNode* future = curr1->next;

            temp->next = curr1;
            temp = temp->next;

            curr1 = future;
         }
         else {
            ListNode* future = curr2->next;

            temp->next = curr2;
            temp = temp->next;

            curr2 = future;
         }
      }

      while(curr1!=NULL){
        ListNode* future = curr1->next;
        temp->next = curr1;
        temp = temp->next;
        curr1 = future;
      }

      while(curr2!=NULL){
        ListNode* future = curr2->next;
        temp->next = curr2;
        temp = temp->next;
        curr2 = future;
      }

      ListNode* head = dummy->next;
      delete dummy;

      return head;
   }



    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0) return NULL;
        
        return sort(lists, 0, lists.size()-1);
    }
};