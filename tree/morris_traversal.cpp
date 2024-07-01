
TC -> O(N) && SC -> O(1)
class Solution {
public:
// ***************************************
    // PREORDER MORRIS TRAVERSAL
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right != NULL && prev->right != curr){ prev = prev->right;}

                if(prev->right == NULL){
                    // connect this right most node of left subtree to curr and move left
                    prev->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    // we have already visited
                    // break that thread
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }

// ********************************************

// ********************************************
// INORDER MORRIS TRAVERSAL
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right != NULL && prev->right != curr){ prev = prev->right;}

                if(prev->right == NULL){
                    // connect this right most node of left subtree to curr and move left
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    // we have already visited
                    // break that thread
                    prev->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
// ******************************************
};
