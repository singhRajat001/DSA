LINK --> https://leetcode.com/problems/maximum-width-of-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 // using bfs or level order
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()){
            int n = q.size();
            int mini = q.front().second; // subtract from each element of a level to avoid overflow

            int l, r;
            for(int i = 0; i < n; i++){
                long long ind = q.front().second - mini;
                TreeNode* temp = q.front().first;
                q.pop();
                if(i == 0) l = ind;
                if(i == n - 1) r = ind;
                if(temp->left) q.push({temp->left, 2 * ind + 1});
                if(temp->right) q.push({temp->right, 2 * ind + 2});
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
