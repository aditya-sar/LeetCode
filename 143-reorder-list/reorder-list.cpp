class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode *> v;
        ListNode *ptr = head;
        while(ptr) {
            v.push_back(ptr);
            ptr = ptr -> next;
        }        
        int left = 0, right = v.size()-1;
        while(left < right) {
            v[left++] -> next = v[right];
            if(left == right) {
                break;
            }
            v[right--] -> next = v[left];
        }
        v[left] -> next = NULL;
    }
};