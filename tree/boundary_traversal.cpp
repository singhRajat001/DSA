// BOUNDARY TRAVERSAL

TC -> O(N + N + N) SC -> O(H (right)) height of right most nodes
  
->Do traversal for left node excluding leaf nodes
->Do traversal for leaf node
->Do traversal for right most node excluding leaf nodes

// ***************************************************************************************************
class Solution {
public:

    bool isLeaf(Node* root){ // to check whether its a leaf node or not
        if(!root->left && !root->right) return 1; // its a leaf node
        return 0;
    }
    void addLeft(Node* root, vector<int> &ans){ // add leftNode without root
        Node *node = root->left;
        
        while(node){
            if(!isLeaf(node)) ans.push_back(node->data);
            if(node->left) node = node->left;
            else node = node->right; // if left node no exists then move to right
        }
    }
    
    void addLeaf(Node* root, vector<int> &ans){ // to add leaf
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        if(root->left) addLeaf(root->left, ans);
        if(root->right) addLeaf(root->right, ans);
    }
    
    void addRight(Node* root, vector<int> &ans){ // add right node without root
        Node *node = root->right;
        stack<int> s;
        
        while(node){
            if(!isLeaf(node)) s.push(node->data);
            if(node->right) node = node->right;
            else node = node->left; // if right node no exists then move to left
        } 
        
        while(s.size() > 0){
            ans.push_back(s.top());
            s.pop();
        }
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(!root) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        
        addLeft(root, ans); // Left node
        addLeaf(root, ans); // leaf node
        addRight(root, ans); // right most node
        return ans;
    }
};

