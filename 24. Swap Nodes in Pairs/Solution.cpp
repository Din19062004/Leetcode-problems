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
    void insertAtTail(ListNode *& head, int val) {
        ListNode *newNode = new ListNode(val);
        if(head == nullptr) {
            head = newNode;
            return;
        }
        ListNode *temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        queue<int> q;
        ListNode *temp = head;
        while(temp != nullptr) {
            if(temp->next != nullptr) {
                q.push(temp->next->val);
            }
            q.push(temp->val); 
            temp = (temp->next == nullptr) ? nullptr : temp->next->next;
        }
        ListNode *newHead = nullptr;
        while(!q.empty()) {
            int top = q.front();
            insertAtTail(newHead, top);
            q.pop();
        }
        return newHead;
    }
};
