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
        ListNode* new_head = new ListNode();
        ListNode* curr = new_head;
        
        
        int carry = 0;
        
        //run if 2 list has not reach the last node
        while(l1 != NULL || l2 != NULL){
            
            //check if last element in the list
            int data1 = (l1 != NULL) ? l1->val : 0;
            int data2 = (l2 != NULL) ? l2->val : 0;
            
            
            //perform sum
            int sum = data1 + data2 + carry;
            //since carry is integer, this will return either 1 or 0 for carry out
            //ex: 7/10 = 0;
            carry = sum / 10;
            int last_digit = sum % 10;
            
            //put sum result into next list
            ListNode* new_node = new ListNode(last_digit);
            curr->next = new_node;
            curr = new_node;
            
            if(l1 != NULL){
                l1 = l1->next;
            }
            if(l2 != NULL){
                l2 = l2->next;
            }
        }
        
        //any remain carry out will get add at the end of the list.
        if(carry > 0){
            ListNode* new_node = new ListNode(carry);
            curr->next = new_node;
            curr = curr->next;
        }
        
        return new_head->next;
    }
};