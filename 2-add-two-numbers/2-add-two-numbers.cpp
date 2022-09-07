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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode *head = new ListNode(), *headClone;
        headClone = head;
        
        int sum = l1->val + l2->val;
        if (sum > 9) {
            carry = true;
            headClone->val = sum%10;
        } else {
            headClone->val = sum;
        }
        l1 = l1->next;
        l2 = l2->next;
        
        while (l1 && l2) {
            ListNode *tmp = new ListNode();
            sum = l1->val + l2->val;
            if (carry) {
                sum++;
                carry = false;
            }
            if (sum > 9) {
                carry = true;
                tmp->val = sum%10;
            } else {
                tmp->val = sum;
            }
            headClone->next = tmp;
            headClone = headClone->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if (!l1) {
            l1 = l2;
        }
        
        while (l1) {
            ListNode *tmp = new ListNode();
            sum = l1->val;
            if (carry) {
                sum++;
                carry = false;
            }
            if (sum > 9) {
                carry = true;
                tmp->val = sum%10;
            } else {
                tmp->val = sum;
            }
            headClone->next = tmp;
            headClone = headClone->next;
            l1 = l1->next;
        }
        if (carry) {
            ListNode *tmp = new ListNode();
            tmp->val = 1;
            headClone->next = tmp;
        }
        return head;
    }
};