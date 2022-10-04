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
    void reorderList(ListNode* head) {
        ListNode* tmp = head;
        vector<int> list;
        while(tmp) {
            list.push_back(tmp->val);
            tmp = tmp->next;
        }
    
        int start = 0, end = list.size() - 1;
        tmp = head;
        while (tmp) {
            tmp->val = list[start++];
            tmp = tmp->next;
            if(tmp){
                tmp->val = list[end--];
                tmp = tmp->next;   
            }
        }
    }
};