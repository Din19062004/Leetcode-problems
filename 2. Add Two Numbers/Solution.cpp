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
    void insertAtTail(ListNode *&head, int value) {
        ListNode *newNode = new ListNode(value);
        //Edege case: When the list is Null
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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2;
        ListNode *result = nullptr;

        int carry = 0, sum;
        //Add each digit
        while(temp1 != nullptr && temp2 != nullptr) {
            sum = temp1->val + temp2->val + carry;
            if(sum >= 10) {
                carry = sum / 10;
                sum = sum % 10;
            }
            else {
                carry = 0;
            }
            insertAtTail(result, sum);
            temp1 = temp1->next;
            temp2 = temp2->next;       
        }
        //If l1 is still remaining
        while(temp1 != nullptr) {
            sum = temp1->val + carry;
            if(sum >= 10) {
                carry = sum / 10;
                sum = sum % 10;
            }
            else {
                carry = 0;
            }
            insertAtTail(result, sum);
            temp1 = temp1->next;
        }
        //If l2 is still remaining
        while(temp2 != nullptr) {
            sum = temp2->val + carry;
            if(sum >= 10) { 
                carry = sum / 10;
                sum = sum % 10;
            }
            else {
                carry = 0;
            }
            insertAtTail(result, sum);
            temp2 = temp2->next;
        }
        //If final result has more digits then l1 and l2
        if(carry == 1) {
            insertAtTail(result, 1);
        }
        return result;
    }
};
