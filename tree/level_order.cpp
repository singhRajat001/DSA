class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            // whatever present on the current queue take its size and iterates to all node of level
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                // check whether left or right children present or not
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);    
                temp.push_back(node -> val);
            }
            ans.push_back(temp);
        
        }
        return ans;
    }
};
TC->O(N) && SC->O(N)
