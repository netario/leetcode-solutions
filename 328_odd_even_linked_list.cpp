/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || ! head->next) return head;
        ListNode *ptr1 = head, *ptr2 = head->next;
        while (ptr2 && ptr2->next){
            ListNode *tmp = ptr2->next;
            ptr2->next = tmp->next;
            tmp->next = ptr1->next;
            ptr1->next = tmp;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return head;
    }
};