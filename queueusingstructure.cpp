#include<bits/stdc++.h>

using namespace std;

 typedef struct st {
    int data;
    struct st *left, *right;
} Node;

Node *newNode(int data)
{
   // Node *new_node = (Node*) malloc(sizeof(Node));
   Node *new_node = new Node();

   new_node->data = data;
   new_node->left = NULL;
   new_node->right = NULL;

   return new_node;
}

Node *insertNode(Node *root, int data)
{

    Node *new_node = newNode(data);

    if(root == NULL)
    {
        return new_node;
    }

    if(root->data > data)
    {
        root->left = insertNode(root->left, data);
    }

    else
    {
        root->right = insertNode(root->right, data);
    }

    return root;

}

Node *minValue(Node *root)
{
    Node *current = root;

    while(current && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

Node *deleteNode(Node *root, int data)
{
    if(root == NULL)
    {
        return root;
    }

    if(data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }

    else if(data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if(root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }

         else if(root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        else{

           Node *minval = minValue(root->right);
           root->data = minval->data;
           root->right = deleteNode(root->right, minval->data);
        }

    }

    return root;

}

void inOrder(Node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->data << endl;
        inOrder(root->right);
    }
}

void maxwidth(Node *root)
{
   if(root == NULL)
      cout << 0 << endl;

    queue<Node*>Q;

    Q.push(root);

    while(!Q.empty())
    {

        int s = Q.size();
        cout << s << endl;

        while(s--)
        {
            Node *top = Q.front();
            Q.pop();

            if(top->left != NULL)
            {
                Q.push(top->left);
            }
             if(top->right != NULL)
            {
                Q.push(top->right);
            }
        }

    }
}

int main()
{

    Node *arg = NULL;

    arg = insertNode(arg, 10);
    arg = insertNode(arg, 15);
    arg = insertNode(arg, 2);
    arg = insertNode(arg, 12);
    arg = insertNode(arg, 22);
    arg = insertNode(arg, 26);
    arg = insertNode(arg, 1);
    arg = insertNode(arg, 5);


    maxwidth(arg);

    cout << "before delete" << endl;
    inOrder(arg);

    arg = deleteNode(arg, 22);
    arg = deleteNode(arg, 5);
    arg = deleteNode(arg, 1);

    cout << "before delete" << endl;
    inOrder(arg);


    return 0;
}
