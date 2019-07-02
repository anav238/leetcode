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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode *l1A, *l2A;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            int sum = l1 -> val + l2 -> val + carry;
            l1 -> val = sum % 10;
            carry = sum / 10;
            l1A = l1;
            l2A = l2;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        if (l1 == NULL && l2 == NULL) {
            if (carry) {
                ListNode* newNode = new ListNode(1);
                l1A->next = newNode;
            }
        }
        else if (l1 == NULL) {
            l1A -> next = l2;
            while (l2 != NULL && carry) {
                int sum = l2 -> val + 1;
                l2 -> val = sum % 10;
                carry = sum / 10;
                l2A = l2;
                l2 = l2 -> next;
            }
            if (carry) {
                ListNode* newNode = new ListNode(1);
                l2A->next = newNode;
            }
        }
        else if (l2 == NULL) {
            while (l1 != NULL && carry) {
                int sum = l1 -> val + 1;
                l1 -> val = sum % 10;
                carry = sum / 10;
                l1A = l1;
                l1 = l1 -> next;
            }
            if (carry) {
                ListNode* newNode = new ListNode(1);
                l1A->next = newNode;
            }
        }
        return head;
    }
};