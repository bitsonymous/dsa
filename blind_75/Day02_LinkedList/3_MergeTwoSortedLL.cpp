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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* curr = ans;
        while(list1!=NULL and list2!=NULL){
            int val1 = list1->val;
            int val2 = list2->val;
            if( val1 <= val2){
                curr->next = list1;
                list1 = list1->next;
            }else{
                curr->next = list2;
                list2 = list2->next;
            }
            curr=curr->next;
        }

        while(list1!=NULL){
            curr->next = list1;
            list1 = list1->next;
            curr=curr->next;
        }
        while(list2!=NULL){
            curr->next = list2;
            list2 = list2->next;
            curr=curr->next;

        }
        return ans->next;
    }
};