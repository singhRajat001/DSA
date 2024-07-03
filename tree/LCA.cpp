

// Approach 1
// Find the path from root to given nodes and after that match each nodes from two path until they unmatches or one or both vector out of bound
class Solution {
public:
    bool solve(TreeNode* &root, TreeNode* &p, vector<TreeNode* > &ans){
        if(root == NULL) return false;

        ans.push_back(root);
        if(root == p){
            return true;
        }
        if(solve(root->left, p, ans) || solve(root->right, p, ans)) return true;
        ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode* > ans1;
        vector<TreeNode* > ans2;

        bool x = solve(root, p, ans1);
        bool y = solve(root, q, ans2);
        
        int i = 0;
        int j = 0;

        TreeNode* ans = ans1[0];
        while(i < ans1.size() && j < ans2.size()){
            if(ans1[i] == ans2[j]){
                ans = ans1[i];
                i++;
                j++;
            }
            else break;
        }
        
        return ans;
        
    }
};
