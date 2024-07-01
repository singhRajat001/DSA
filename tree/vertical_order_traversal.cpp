LINK--> https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/


// *******************************************************************
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      
        map<int, map<int, multiset<int>>> mp; 
        // map<line, map<level, root->val>> mp
      
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while(!q.empty()) {
            TreeNode* temp = q.front().first;
            int line = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            
            mp[line][level].insert(temp->val);
            
            if(temp->left) q.push({temp->left, {line - 1, level + 1}});
            if(temp->right) q.push({temp->right, {line + 1, level + 1}});
        }
        
        vector<vector<int>> ans;
        for(auto it: mp) { 
            vector<int> v; 
            for(auto i: it.second) { // it contains the elements of all the levels of a particular vertical line
                v.insert(v.end(), i.second.begin(), i.second.end());
            }
            ans.push_back(v);  
        }
        return ans;
    }
};
// *******************************************************************
