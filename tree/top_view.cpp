//TOP VIEW IN BINARY TREE
// **************************************************
class Solution
{
    public:    
    vector<int> topView(Node *root)
    {
        //Your code here
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            Node *temp = q.front().first;
            int line = q.front().second;
            q.pop();
            
            if(mp.count(line) == 0){
                mp[line] = temp->data;
            }
            if(temp->left) q.push({temp->left, line - 1});
            if(temp->right) q.push({temp->right, line + 1});
        }
        vector<int> ans;
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
// ******************************************************
