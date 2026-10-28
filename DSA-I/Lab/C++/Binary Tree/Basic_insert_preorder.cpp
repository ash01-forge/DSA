#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->right = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(9);
    root->right->left->right = new Node(10);
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;
    return 0;
}