// TC-> O(N) and SC-> recursive stack space will be O(log n) for balanced binary tree whereas O(N) in case of skewed tree
// ************************************************************************************************************************************************************

class Solution {
public:
// Here we just used max depth of BT code with some modification
// if the solve function return -1 means that there is atleast one subtree which is unbalanced otherwise other than -1 means the whole tree is balanced
    int solve(TreeNode* &root){
        if (!root) return 0;

        int leftHeight = solve(root->left);
        // If the left subtree is unbalance, return -1, we don't need to check other tree one subtree is unbalanaced
        if (leftHeight == -1) return -1;

        int rightHeight = solve(root->right);
        // If the right subtree is unbalance, return -1 we don't need to check other tree one subtree is unbalanaced
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1) return -1; // condition of checking height balanced binary tree
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(solve(root) != -1) return 1;
        return 0;
    }
};


// ***************************************************************************************************************************************************************
