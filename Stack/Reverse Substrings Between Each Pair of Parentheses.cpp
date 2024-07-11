
// TC--> O(N*N) one N for traversing whole the string and other N to reverse substring for worst case && SC --> O(N)
class Solution {
public:
    string reverseParentheses(string s) {
        stack<pair<char, int>> st;
        int i = 0;
        while(i < s.length()){
            if(s[i] == '('){
                // storing the index of '(' 
                st.push({'(', i});
            }
            else if(s[i] == ')'){
              // whenever i found ')' reverse from the index just after the '(' which is present at the top of stack
                int start = st.top().second + 1;
                reverse(s.begin() + start, s.begin() + i); // till index i from start index -- > reversed
                st.pop();
            }
            i++;
        }

        string ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '(' && s[i] != ')') ans += s[i];
        }
        return ans;
    }
};





// ***********************************************************************************************************************************************
// My approach

ALSO TC --> O(N^2) && SC --> O(N + N) for stack + temp both 
class Solution {
public:
    string reverseParentheses(string s) {
        stack<pair<char, int>> st;
      
        // storing the s string in temp and if (, ) found store them as #
        string temp = s;
        for(int i = 0; i < temp.length(); i++){
            if(temp[i] == '(' || temp[i] == ')') temp[i] = '#';
        }
        int i = 0;
        while(i < s.length()){
            if(s[i] == '('){
                st.push({'(', i});
            }
            else if(s[i] == ')'){
              
                int start = st.top().second + 1;
                int len = i - start;
                string x = temp.substr(start, len);
                reverse(x.begin(), x.end()); //reverse the substring
                for(int j = start; j < i; j++){
                    temp[j] = x[j - start]; // putting back the reverse substring to their postion
                }
                st.pop();
            }
            i++;
        }

        string ans;
        for(int i = 0; i < temp.size(); i++){
            if(temp[i] != '#') ans += temp[i];
        }
        return ans;
    }
}; 
