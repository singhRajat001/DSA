// The order which come earlier have to wait to finish the last ordered item; whole point lie on it..
TC --> O(N) SC --> (1)
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& nums) {
        int finish = 0;
        long long gap = 0;
        int n = nums.size();

        int start = nums[0][0];
        int time = nums[0][1];
        int lateStart = start;
        // cout <<  "lateStart : " << lateStart <<endl;
        finish = (start + time);

        gap += (finish - start);
        // cout << "gap : " << gap << endl;
        for(int i = 1; i < n; i++){
            start = nums[i][0];
            time = nums[i][1];
            int lateStart = max(start, finish);
            // cout << lateStart << " ";
            // cout << "lateStart : " << lateStart <<endl;
            finish = (lateStart + time);

            gap += (finish - start);
            // cout << "gap : " << gap << endl;
            // cout << gap << " ";
        }

        double ans = (double)gap / (double) n;

        return ans;
    }
};
