// LEFT & RIGHT VIEW OF BINARY TREE
// ***********************************************
// using Level Order
vector<int> leftView(Node *root)
{
   // Your code here
    vector<int> ans;
    if(root == NULL) return ans;
    queue<Node* > q;
    q.push(root);
    
    while(!q.empty()){
        int n = q.size();

        for(int i = 0; i < n; i++){
            Node* temp = q.front();
            q.pop();
            if(i == 0) ans.push_back(temp->data); //for right view i == n - 1
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
    }
    return ans;
}
TC--> O(N) && SC =~ O(N) {O(N / 2)}
//***************************************************

// **************************************************
using DFS
for left view, (root, left, right) (Preorder)
for right view, (root, right, left) 
void solve(Node *&root, vector<int> &ans, int level){
    if(root == NULL) return;
    
    if(level == ans.size()) ans.push_back(root->data);
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}
vector<int> leftView(Node *root)
{
   // Your code here
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}
TC--> O(N) && SC --> O(H) H->height of binary tree
// *****************************************************
