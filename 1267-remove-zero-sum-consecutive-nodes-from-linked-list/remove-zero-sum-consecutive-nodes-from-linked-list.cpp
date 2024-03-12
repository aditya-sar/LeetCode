class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode *> mp;
        ListNode *nullNode = new ListNode(NULL);
        nullNode -> next = head;
        int sum = 0;
        mp[sum] = nullNode;
        while(head) {
            sum += head -> val;
            if(mp.find(sum) != mp.end()) {
                ListNode *removeNode = mp[sum] -> next;
                int count = sum;
                while(removeNode != head) {
                    count += removeNode -> val;
                    mp.erase(count);
                    removeNode = removeNode -> next;
                }
                mp[sum] -> next = head -> next;
            }
            else {
                mp[sum] = head;
            }
            head = head -> next;
        }
        return nullNode -> next;
    }
};