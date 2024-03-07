class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode *start = head;
        while(start) {
            count++;
            start = start -> next;
        }
        count /= 2;
        start = head;
        ListNode *ans;
        while(count--) {
            start = start -> next;
            ans = start;
        }
        return ans;
    }
};