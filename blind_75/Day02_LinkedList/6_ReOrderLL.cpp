class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head == NULL or head->next == NULL) return head;

        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }

    void reorderList(ListNode* head) {
        if(head == NULL or head->next == NULL) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL and fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }


        ListNode* second = reverse(slow->next);
        slow->next = NULL;

        ListNode* first = head;
        while(second != NULL){
            ListNode* next1 = first->next;
            ListNode* next2 = second->next;

            first->next = second;
            second->next = next1;

            first = next1;
            second = next2;
        }
    }
};
