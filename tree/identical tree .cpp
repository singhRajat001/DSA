
// Simple DFS TRAVERSAL TC->O(N) SC->O(height of tree) of recursion stack space
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if(both are null) then 1st condition will be satisfied no need to go 2nd if
        // if(one of them is null) means they are not same 
        if(p == NULL && q == NULL) return true;
        // if(p == NULL || q == NULL) return false; for both true above case will execute
        return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
