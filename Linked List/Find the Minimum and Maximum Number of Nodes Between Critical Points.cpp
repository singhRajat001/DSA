TC --> O(N) SC-> O(N / 3) (not exactly N/ 3) because we are taking consecutive 3 element to find local maxima and local minima 

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        int i = 1;
        while(curr){
            ListNode* nextNode = curr->next;
            if(prev && nextNode){
                if(prev->val < curr-> val && curr->val > nextNode->val){
                    // local maxima
                    ans.push_back(i);
                }
                else if(prev->val > curr-> val && curr->val < nextNode->val){
                    // local minima
                    ans.push_back(i);
                }
            }
            prev = curr;
            curr = nextNode;
            i++;
        }

        if(ans.size() == 0 || ans.size() == 1) return {-1, -1};
        
        int mini = INT_MAX;
        int n = ans.size() - 1;
        int maxi = ans[n] - ans[0]; // max diff will be last - first as ans is sorted
        for(int i = 0; i < n; i++){
            mini = min(mini, ans[i + 1] - ans[i]); // min diff will be the minimum of all adjacent diff
        }
        return {mini, maxi};
    }
};
