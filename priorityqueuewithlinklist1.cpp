#include<bits/stdc++.h>

using namespace std;

typedef struct st{
    int data;
    int pri;
    st *next;
} Node;

Node *newNode(int data, int pri)
{
    Node *new_node = new Node();

    if(new_node == NULL)
    {
        cout << "Node can not create" << endl;
        exit(1);
    }

    new_node->next = NULL;
    new_node->data = data;
    new_node->pri = pri;

    return new_node;
}

Node *insertNode(Node *root, int data, int pri)
{
    Node *new_node = newNode(data, pri);
    Node *current_node = root;

    if(root == NULL)
    {
        return new_node;
    }

    if(root->pri > pri)
    {
        new_node->next = root;
        root = new_node;
    }
    else
    {
        while(current_node->next != NULL && current_node->next->pri < pri)
        {
            current_node = current_node->next;
        }

        new_node->next = current_node->next;
        current_node->next = new_node;


    }

    return root;

}

Node *pop(Node *root)
{
    Node *temp = root;

    root = root->next;

    free(temp);
   // return root->data;
   return root;
}

int top(Node *root)
{
    return root->data;
}

void traverse(Node *head)
{
  Node *current_node = head;

    while(current_node != NULL)
    {
        cout << current_node->data << " ";
        current_node = current_node->next;
    }
}

int main()
{

    Node *root = newNode(5,2);

    root = insertNode(root, 10,1);
   root = insertNode(root, 20,3);

    traverse(root);

    cout << "\nAfter pop " << endl;

    root = pop(root);
    root = pop(root);

    traverse(root);
   // traverse(root);



    return 0;
}
