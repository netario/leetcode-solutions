/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    class Cmp {
    public:
        int operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> q;
        for (int i = 0; i < lists.size(); ++ i)
            if (lists[i]) q.push(lists[i]);
        ListNode dummy(0), *tail = &dummy;
        while (!q.empty()){
            ListNode *tmp = new ListNode(q.top()->val);
            tail->next = tmp;
            tmp = q.top()->next;
            q.pop();
            if (tmp) q.push(tmp);
            tail = tail->next;
        }
        return dummy.next;
    }
};