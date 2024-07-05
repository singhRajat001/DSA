

// ******************************************************************************************************************************

// APPROACH --> 1
// Go to the right most first and for a node connect the left part to right part and store the node for future right part

TC--> O(N)  SC --> O(N)
class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;

    }
};

// *******************************************************************************************************************************

// *******************************************************************************************************************************

// APPROACH 2
// using Morris Traversal

TC --> O(N) && SC --> O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while(curr){
            if(curr->left){
                TreeNode* prev = curr->left;
                while(prev->right) prev = prev->right;

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
        
    }
};

