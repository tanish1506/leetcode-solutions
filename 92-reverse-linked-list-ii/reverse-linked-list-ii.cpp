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
    ListNode* reverse(ListNode* head, ListNode* after){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = after;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* lft = dummy;
        ListNode* rgt = dummy;
        for(int i=1;i<left;i++){
            lft = lft->next;
        }
        for(int i=1;i<=right;i++){
            rgt = rgt->next;
        }
        ListNode* prev = lft;
        ListNode* after = rgt->next;
        lft = lft->next;
        rgt->next = NULL;

        prev->next = reverse(lft , after);


        return dummy->next;



        // ListNode* prev = dummy;
        // for(int i=1;i<left;i++){
        //     prev = prev->next;
        // }
        // ListNode* curr = prev->next;
        // for(int i=0;i<right-left;i++){
        //     ListNode* temp = curr->next;
        //     curr->next = temp->next;
        //     temp->next = prev->next;
        //     prev->next = temp;
        // }
        // return dummy->next;
    }
};