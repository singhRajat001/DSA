Link--> https://www.naukri.com/code360/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
Preorder Inorder Postorder in one traversal

// for preorder it's root left right means 1st visit of node
// for inorder it's left root right means 2nd visit of node
// for postorder it's left right root means 3rd visit of node
TC -- > O(3*N) && SC -- > O(3 * N)
vector<vector<int>> getTreeTraversal(TreeNode *root){
        vector<vector<int>> ans(3);
  
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
  
        while(!s.empty()){
                auto it = s.top();
                s.pop();
                if(it.second == 1){ // preorder
                        ans[1].push_back(it.first->data);
                        int x = it.second;
                        x++;
                        s.push({it.first, x});
                        if(it.first->left) s.push({it.first->left, 1});
                }
                else if(it.second == 2){ // inorder
                        ans[0].push_back(it.first->data);
                        int x = it.second;
                        x++;
                        s.push({it.first, x});
                        if(it.first->right) s.push({it.first->right, 1});
                }
                else if(it.second == 3){ // postorder
                        ans[2].push_back(it.first->data);
                }
        }
        return ans;
}
