//***************************************************************************
// 1st Approach

class Solution {
public:

// Calculate the max height for each node
TC-> O(N)
    int findMax(TreeNode* &root){
        if(root == NULL) return 0;
        if(!root->left && !root->right) return 1;

        int left = 0;
        if(root->left) left = 1 + findMax(root->left);
        int right = 0;
        if(root->right) right = 1 + findMax(root->right);
        return max(left, right);
    }

// For a particular node, finding the height of left and right subtree and add them
TC->o(N)
    void solve(TreeNode* &root, int &maxi){
        if(!root) return;

        int leftSubtree = findMax(root->left); // height of left subtree
        int rightSubtree = findMax(root->right); // height of right subtree

        maxi = max(maxi, leftSubtree + rightSubtree);

        solve(root->left, maxi); // calling the solve func for left node, it is possible ki left subtree se max diameter aajaye
        solve(root->right, maxi);// same for this also
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        solve(root, maxi);
        return maxi;
    }
};

overall time complexity is O(N^2) and space complexity is O(height of tree)

// *******************************************************************************


// *******************************************************************************
2nd approach
// we simultaneously calculate the height and check for max diameter
public:
    int solve(TreeNode* &root, int &maxi){
        if(root == NULL) return 0;
  
        int leftT = solve(root->left, maxi);
        int rightT = solve(root->right, maxi);

        maxi = max(maxi, leftT + rightT);

        return max(leftT, rightT) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        solve(root, maxi);
        return maxi;
    }
};
TC->O(N) and SC->O(N)
// ******************************************************************************
