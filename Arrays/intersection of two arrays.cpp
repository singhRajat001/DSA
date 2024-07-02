LINK--> https://leetcode.com/problems/intersection-of-two-arrays-ii/

// first soln using map
// ********************************************************************
  // TC--> O(NlogN) + O(M) && SC --> O(N) for map
class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        map<int,int>mp;

        vector<int>ans;
        for(int i = 0; i < a.size(); i++){
            mp[a[i]]++;
        }
        for(int i = 0; i < b.size(); i++){
            if (mp[b[i]] > 0){
                mp[b[i]]--; 
                ans.push_back(b[i]);
            }
        }
        return ans;
    }
};
// ******************************************************************
//Another solution is using sort and two pointers
 // TC --> O(min(n, m)) + O(nlogn) + O(mlogm) SC --> O(1)
class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0, j = 0;

        int m = a.size();
        int n = b.size();

        vector<int> ans;
        while(i < m && j < n){
            if(a[i] == b[j]){
                ans.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i] > b[j]) j++;
            else i++;
        }
        return ans;
    }
};
