Simulation -- do as it is what the question is asked to do so

class Solution {
public:

    // TC --> O(N * N) as while loop is taking N time and each time a element is erased which is taking N time to remove it....
    // SC --> O(N)
    int findTheWinner(int n, int k) {

        vector<int> arr;
        for(int i = 1; i <= n; i++) arr.push_back(i);
        int i = 0;
        while(arr.size() > 1){
            int ind = (i + k - 1) % arr.size();
            arr.erase(arr.begin() + ind);
            // cout << arr.size() << " ";
            i = ind;
        }
        return arr[0];
    }
};
