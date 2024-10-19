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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *temp = head;

        int count = 0;
        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }

        int movingTimes = k % count;

        for(int i = 1; i <= movingTimes; i++) {
            temp = head;
            while(temp->next->next != nullptr) {
                temp = temp->next;
            }
            ListNode *lastNode = temp->next;
            lastNode->next = head;
            head = lastNode;
            temp->next = nullptr;
        }
        return head;
    }
};
