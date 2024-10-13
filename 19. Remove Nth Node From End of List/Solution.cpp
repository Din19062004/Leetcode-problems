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
        int cntNodes = 0;
        ListNode *temp = head;
        while(temp != nullptr) {
            cntNodes++;
            temp = temp->next;
        }
        int delPosition = cntNodes - n;
        if(delPosition == 0) {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }
        
        temp = head;
        for(int i = 1; i < delPosition; i++) {
            temp = temp->next;
        }
        ListNode *delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
        return head;
    }
};
