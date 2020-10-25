#include<bits/stdc++.h>

using namespace std;

typedef struct st{
    int data;
    struct st *next;
} Node;

Node *newNode(int data, Node *next )
{
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = next;

    return new_node;
}

Node *insertinfirst(Node *head, int data)
{
    Node *new_node = newNode(data, NULL);
    new_node->next = head;
    head = new_node;

    return head;
}

Node *insertinLast(Node *head, int data)
{
    Node *new_node = newNode(data, NULL);

    if(head == NULL)
    return new_node;

    Node *current_node = head;

    while(current_node != NULL)
    {
        if(current_node->next == NULL)
          break;
        current_node = current_node->next;
    }
    current_node->next = new_node;

    return head;
}

Node *insertatanyposition(Node *head, Node *node, int data)
{
    Node *new_node = newNode(data, NULL);

    Node *current_node = head;

    while(current_node != NULL)
    {
        if(current_node == node)
          break;
        current_node = current_node->next;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;

    return head;
}

void printLinkList(Node *head)
{
    Node *current_node = head;

    while(current_node != NULL)
    {
        cout << current_node->data << " ";
        current_node = current_node->next;
    }
}

Node *deleteNode(Node *head, Node *node)
{
    if(head == node)
    {
        head = node->next;
        free(node);
        return head;
    }

    Node *current_node = head;

    while(current_node != NULL)
    {
        if(current_node->next == node)
        break;

        current_node = current_node->next;
    }

    current_node->next = node->next;
    free(node);

    return head;

}

int main()
{

  Node *head = NULL;

  head = newNode(5, head);
  head = insertinLast(head, 50);

  head = insertinfirst(head, 10);
  head = insertinfirst(head, 20);
  head = insertatanyposition(head, head->next->next, 100);

  cout << "before delete " << endl;
  printLinkList(head);

  deleteNode(head, head->next->next);

cout << "after delete " << endl;
  printLinkList(head);



    return 0;
}
