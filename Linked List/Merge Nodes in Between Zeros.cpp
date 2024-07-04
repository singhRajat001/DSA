class Solution {
public:

    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        // 0 -> 3 -> 1-> 0 -> 4 -> 5 -> 2 -> 0
        //      ^
        //      |
        //    temp
        ListNode* ans = new ListNode(-1);

        //    ans => -1 -> X
        //            ^
        //            |
        //          tail

        ListNode* tail = ans;

        int sol = 0;

        while(temp){
            if(temp->val == 0){
                ListNode* node = new ListNode(sol);
                tail->next = node;
                tail = node;
                sol = 0;
            }
            else sol += temp->val;
            temp = temp->next;
        }


        //     -1 -> 4 -> 11 -> X
        //      ^          ^
        //      |          |
            // ans    //    tail
        return ans->next;
    }
};
