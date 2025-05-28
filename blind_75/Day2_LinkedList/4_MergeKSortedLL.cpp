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
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* ans = new ListNode();
        ListNode *head = ans; 
        while(list1!=NULL and list2!=NULL){
            if(list1->val<list2->val){
                ans->next = list1;
                list1=list1->next;
            }else{
                ans->next = list2;
                list2=list2->next;
            }
            ans = ans->next;
        }

        while(list1!=NULL){
            ans->next = list1;
            list1=list1->next;
            ans = ans->next;
        }
        while(list2!=NULL){
            ans->next = list2;
            list2=list2->next;
            ans = ans->next;
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;
        for(auto it : lists){
            ListNode* newList = it;
            ans = merge(ans, newList);
        }
        return ans;
    }
};