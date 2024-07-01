LINK -- > https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths

class Solution {
  public:
  void solve(Node* &root, vector<vector<int>> &ans, vector<int> &sol){
      if(root == NULL) return; // it does not guarantee leaf node may be left child is null but not right one
      if(root->left == NULL && root->right == NULL){ condition for leaf node
          sol.push_back(root->data);
          ans.push_back(sol);
          sol.pop_back();
          return;
      }
      
      // preOrder
      sol.push_back(root->data);
      solve(root->left, ans, sol);
      solve(root->right, ans, sol);
      sol.pop_back();
      
  }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<int>sol;
        vector<vector<int>> ans;
        solve(root, ans, sol);

        return ans;
    }
};
