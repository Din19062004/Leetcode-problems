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
    void insertAtHead(ListNode *&head, int value) {
        ListNode *newNode = new ListNode(value);
        newNode->next = head;
        head = newNode;
    }

    void freeList(ListNode *&head) {
        ListNode *current = head;
        
        while(current != nullptr) {
            ListNode *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    ListNode* removeNodes(ListNode* head) {
        stack<int> s;
        ListNode *temp = head;
        //Push all values into stack. They will be stored in reversed order in comparison with initial order
        while(temp != nullptr) {
            s.push(temp->val);
            temp = temp->next;
        }
        
        //The rightmost value will never have a greater value to the right side of it.
        //Store the rightmost value in the return list.
        ListNode *returnHead = nullptr;
        insertAtHead(returnHead, s.top());
        int max = s.top();
        s.pop();

        while(!s.empty()) {
            if(s.top() < max) {
                s.pop();
            }
            else {
                //There is no greater value to the right of current value. Store it in return list.
                max = s.top();
                insertAtHead(returnHead, s.top());
                s.pop();
            }
        } 
        return returnHead; 
        freeList(returnHead);
    }
};
