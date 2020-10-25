#include<bits/stdc++.h>

using namespace std;

typedef struct st {
    int key;
    struct st *left, *right;
} Node;

Node *newNode(int key)
{
    //Node *new_node = (Node*) malloc(sizeof(Node));

    Node *new_node = new Node();

    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

Node *Insert(Node *root, int key)
{
    if(root == NULL)
    {
       return newNode(key);
    }

    if(key < root->key)
    {
       root->left = Insert(root->left, key);
    }
    else{
       root->right = Insert(root->right, key);
    }

    return root;
}

Node *minValueNode(Node *root)
{

    Node *current = root;

    while(current && current->left != NULL)
    {
    //cout << "nahid" << endl;
        current = current->left;
    }

    return current;
}

Node *deleteData(Node *root, int key)
{
    if(root == NULL)
      return root;

    if(key < root->key)
    {
        root->left = deleteData(root->left, key);
    }
    else if(key > root->key)
    {
       root->right = deleteData(root->right, key);
    }
    else
    {
        if(root->left == NULL)
        {
            Node *temp;
            temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL)
        {
            Node *temp;
            temp = root->left;
            free(root);
            return temp;
        }

        Node *minValue = minValueNode(root->right);
        root->key = minValue->key;

        root->right = deleteData(root->right, minValue->key);

    }

    return root;
}

void inOrder(Node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    root = Insert(root, 5);

    root = Insert(root, 15);
    root = Insert(root, 2);
    root = Insert(root, 10);
    root = Insert(root, 1);
    root = Insert(root, 100);
    root = Insert(root, 50);

    cout << "before delete " << endl;
    inOrder(root);

     Node *Min = minValueNode(root);

    cout << "min " << Min->key << endl;

    root = deleteData(root, 5);
    cout << "after delete " << endl;
    inOrder(root);

    return 0;
}
