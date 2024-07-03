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
