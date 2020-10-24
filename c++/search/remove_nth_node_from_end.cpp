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
        if (head->next == NULL) {
            return NULL;
        }
        
        ListNode *start = head;
        ListNode *before = head;
        
        head = head->next;
        int cnt = 1;
        
        while (cnt != n) {
            head = head->next;
            ++cnt;
        }
        
        if (head == NULL) {
            return start->next;
        }
        
        while (head->next != NULL) {
            head = head->next;
            before = before->next;
        }
        
        before->next = before->next->next;
        
        return start;
    }
};
