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
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
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
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;
    return 0;
}