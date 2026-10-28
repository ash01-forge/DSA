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
bool Search(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    return Search(root->left, key) || Search(root->right, key);
}
int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int key;
    cout << "Enter the value of key" << endl;
    cin >> key;
    if (Search(root, key))
    {
        cout << "Found" << endl;
    }
    else
        cout << "Not Found" << endl;
    return 0;
}