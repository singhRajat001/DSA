
TC -> O(N) and SC-> O(N) worst case
class Solution {
public:
    bool solve(TreeNode* &root, long mini, long maxi){
        if(!root) return 1;

        if(root->val > mini && root->val < maxi) return solve(root->left, mini, root->val) && solve(root->right, root->val, maxi);
        return 0;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};
