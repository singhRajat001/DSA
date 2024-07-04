
TC -> O(NlogN) and SC-> O(N)
// ******************************************************************************************************************************************

  
class Solution {
public:
// Preorder is Root, left, right
// inorder is left, root, right
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd, map<int, int> &mp){
        if(preStart > preEnd || inStart > inEnd) return NULL; // if the pointer crosses

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val]; // finding the position of root in inorder map
        int numLeft = inRoot - inStart; // how many are left of root in inorder

        root->left = solve(preorder, inorder, preStart + 1, preStart + numLeft, inStart, inRoot - 1, mp);
        // preStart + 1, preStart + numLeft --> preorder of left part of subtree 
        // inStart, inRoot - 1 --> inorder of left part of subtree 
        root->right = solve(preorder, inorder, preStart + numLeft + 1, preEnd, inRoot + 1, inEnd, mp);
        // preStart + numLeft + 1 --> preorder of right part of subtree 
        // inRoot + 1, inEnd --> inorder of right part of subtree 
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int, int> inMap;

        for(int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i; // storing the preorder values index in the map to find the postion of the value in the inorder array

        return solve(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inMap);
    }
};
