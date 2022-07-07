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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode **temp = &head, *temp1 = head;
        for (int i = 1; i < n; i++)
            temp1 = temp1->next;
        while (temp1->next != NULL)
        {
            temp = &((*temp)->next);
            temp1 = temp1->next;
        }
        *temp = (*temp)->next;
        return head;
    }
};