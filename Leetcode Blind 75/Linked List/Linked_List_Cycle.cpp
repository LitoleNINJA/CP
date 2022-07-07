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
    bool hasCycle(ListNode *head) {
        ListNode *head1 = head;
        ListNode *head2 = head;
        if (head == NULL)
            return false;
        while (head1 != NULL && head1->next != NULL)
        {
            head1 = head1->next->next;
            head2 = head2->next;
            if (head1 == head2)
                return true;
        }
        return false;
    }
};