
// ******************************************************************************************************************************************************

TC -> O(N) SC -> O(height of tree) 

// Depth first search
class Solution {
public:
    int solve(TreeNode* &root, int &maxi){
        if(!root) return 0;

        int l = solve(root->left, maxi);
        int r = solve(root->right, maxi);

        int both_best = l + r + root->val; // it is path including left part max Sum , right part max Sum  and root val --> jo ki ek complete path hai isme kuch bhi add ni kr skte kuki wo path ni hoga phir
        int one_best = max(l, r) + root->val; // either left or right part + root will give max sum aur ise hum return kr skte hai kuki ye path till now ek skewed path hoga
        int node_itself = root->val; // node itself cn be the max Sum 

        maxi = max(maxi, max(both_best, (max(one_best, node_itself))));
        return max(one_best, node_itself); // not including the both_best
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;

        int ans = solve(root, maxi);
        return maxi;
    }
};
