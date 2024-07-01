// BOTTOM VIEW OF BINARY TREE
// ************************************************************

class Solution {
  public:
  
    // VERTICAL LINE TRAVERSAL (LINE CONCEPT
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        // if(root == NULL) return ans;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        map<int, int> mp;
        
        while(!q.empty()){
            Node* temp = q.front().first;
            int line = q.front().second;
            q.pop();
            
            mp[line] = temp->data;
            if(temp->left) q.push({temp->left, line - 1});
            if(temp->right) q.push({temp->right, line + 1});
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
        
    }
};
// TC --> O(N) SC--> O(N + ~N) for queue + map
// *****************************************************************
