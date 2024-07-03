class Solution {
public:

    int solve(TreeNode* &root){
        if(root == NULL) return 0; // if the tree is empty
        if(root->left == NULL && root->right == NULL){ // leaf node
            return 1;
        }
        int left = 0;
        if(root->left) left = 1 + solve(root->left);
        int right = 0;
        if(root->right) right = 1 + solve(root->right);

        return max(left, right);
    }
    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};

// ***************************************************************************
class Solution {
public:

    int solve(TreeNode* &root, int &maxi){
        if(root == NULL) return 0;

        int left = solve(root->left, maxi);
        int right = solve(root->right, maxi);
        return max(left, right) + 1;
    }
    int maxDepth(TreeNode* root) {
        int maxi = 0;
        return solve(root, maxi);
    }
};
