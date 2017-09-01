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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        bool ret = true;
        ListNode *slow = head, *fast = head->next;
        while (fast->next){
            slow = slow->next;
            fast = fast->next;
            if (fast->next) fast = fast->next;
        }
        ListNode *mid = slow, *p = slow, *q = slow->next, *tmp = head;
        p->next = NULL;
        while (q != NULL){
            tmp = q;
            q = q->next;
            tmp->next = p;
            p = tmp;
        }
        slow = head;
        while (fast != mid){
            if (slow->val != fast->val){
                ret = false;
                break;
            }
            slow = slow->next;
            fast = fast->next;
        }
        p = fast;
        q = fast->next;
        /*
        while (true){
            ListNode* tmp = q;
            q = q->next;
            tmp->next = p;
            p = tmp;
            if (p == mid) break;
        }
        */
        return ret;
    }
};