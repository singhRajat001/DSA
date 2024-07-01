#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// *******************************

// CREATION OF TREE
node *buildTree(node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter the data for left of " << data << ": " << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for right of " << data << ": " << endl;
    root->right = buildTree(root->right);
}

node *buildFromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter the data for left child of " << temp->data << ": " << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout << "Enter the data for right child of " << temp->data << ": " << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
    return root;
}

// **************************

// **************************
void levelOrder(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            node *temp = q.front();
            q.pop();
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        cout << endl;
    }
}
// ********************

// ********************

// DFS TRAVERSAL
void preOrder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(node *root)
{
    if (root == NULL)
        return;

    preOrder(root->left);
    cout << root->data << " ";
    preOrder(root->right);
}
void postOrder(node *root)
{
    if (root == NULL)
        return;

    preOrder(root->left);
    preOrder(root->right);
    cout << root->data << " ";
}
// ***************************


int main(){
    node *root = NULL;


    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    cout << endl;

    // root = buildFromLevelOrder(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    cout << "Level Order Traversal" << endl;
    levelOrder(root);
    cout << endl;

    cout << endl;
    cout << "DFS TRAVERSAL" << endl;
    cout << "Preorder" << endl;
    preOrder(root);
    cout << endl;
    cout << "Inorder" << endl;
    inOrder(root);
    cout << endl;
    cout << "Postorder" << endl;
    postOrder(root);
}