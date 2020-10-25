#include<bits/stdc++.h>

using namespace std;

typedef struct st{
    int data;
    st *next;
} Node;

Node *newNode(int data)
{
    Node *new_node = (Node*) malloc(sizeof(Node));

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

Node *push(int data, Node *head)
{
    Node *new_node = newNode(data);
    new_node->next = head;
    head = new_node;

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

bool isCycle(Node *head)
{
   if(head == NULL)
     return false;

    Node *fast = head->next;
    Node *slow = head;

    while(fast != NULL && fast->next != NULL && slow != NULL)
    {
       if(fast == slow)
          return true;

          fast = fast->next->next;
          slow = slow->next;
    }

    return false;
}

int main()
{

   Node *head = NULL;

  head = newNode(5);

  head = push(10,head);
  head = push(15,head);
  head = push(20,head);
  head = push(30,head);

  printLinkList(head);

    return 0;
}
