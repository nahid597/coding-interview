#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
};

node *newNode(int data)
{
   node *newNode =  (node*)malloc(sizeof(node));
   newNode->data = data;
   newNode->next = NULL;

   return newNode;
}

node *insertNodeatFirst(node *head, int data)
{
    node *new_node = newNode(data);
    if(head == NULL)
      return new_node;

    new_node->next = head;
    head = new_node;

    return head;
}

node *insertNodeatLast(node *head, int data)
{
    node *new_node = newNode(data);

   node *current_node = head;

   while(current_node->next != NULL)
   {
      current_node = current_node->next;
   }

   current_node->next = new_node;


    return head;
}


node *insertNodeatFixedPosition(node *head, node *Node, int data)
{
    node *new_node = newNode(data);

   node *current_node = head;

   while(current_node != NULL && current_node != Node )
   {
      current_node = current_node->next;
   }

   if(current_node == NULL)
   {
      cout << "given node not found" << endl;
      return head;
   }

   new_node->next = current_node->next;
   current_node->next = new_node;

    return head;
}

node *deleteNode(node *head, node *Node)
{
    /// 1st node delete
    if(head == Node)
    {
       head = head->next;
       free(Node);
       return head;
    }

    node *current_node = head;

    while(current_node->next != Node && current_node != NULL)
    {
        current_node = current_node->next;
    }

    if(current_node == NULL)
   {
      cout << "given node not found" << endl;
      return head;
   }

   current_node->next = Node->next;
   free(Node);

   return head;

}

void traverse(node *head)
{
    node *current_node = head;

    while(current_node != NULL)
    {
        cout << current_node->data << endl;
        current_node = current_node->next;
    }
}

node *middle(node *head)
{
    node *fast_node = head;
    node *slow_node = head;

    while(fast_node->next != NULL)
    {
        fast_node = fast_node->next->next;
        slow_node = slow_node->next;
    }

    head = deleteNode(head, slow_node);

    return head;
}


int main()
{
    node *head = NULL;

      head = insertNodeatFirst(head, 15);
      head = insertNodeatFirst(head, 25);
      head = insertNodeatFirst(head, 5);
      head = insertNodeatLast(head, 100);
     // head = insertNodeatLast(head, 100);
      head = insertNodeatFixedPosition(head, head->next->next, 50);

    cout << "before delete" << endl;
    traverse(head);

    cout << "after delete middle" << endl;
    head = middle(head);
    traverse(head);


    return 0;
}


