#include<iostream>

using namespace std;

struct node {
   int data;
   node *next;
};

node *newNode(int data) {
   node *new_node = (node*) malloc(sizeof(node));
   new_node->data = data;
   new_node->next = NULL;
   return new_node;
}

node *inInFirst(node *head, int data) {
    node *new_node = newNode(data);
     if(head == NULL) {
       return new_node;
    }
    new_node->next = head;
    head = new_node;
    return head;
}

node *inInLast(node *head, int data) {
    node *new_node = newNode(data);
     node *current_node = head;
     while(current_node->next != NULL) {
        current_node = current_node->next;
     }

     current_node->next = new_node;

         return head;
}

node *inInFixPos(node *head, node *find_node, int data) {
    node *new_node = newNode(data);
     node *current_node = head;
     while( current_node != NULL && current_node != find_node) {
        current_node = current_node->next;
     }

     new_node->next = current_node->next;
     current_node->next = new_node;

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

node *deleteNode(node *head, node *Node) {
    if(head == Node) {
       head = head->next;
       free(Node);
       return head;
    }
    node *current_node = head;
    while(current_node->next != Node)
    {
        current_node = current_node->next;
    }

    if(current_node ==  NULL) {
       cout << "given node not found" << endl;
       return head;
    }

    current_node->next = Node->next;
    free(Node);

    return head;

}


int main()
{
    node *head = NULL;
    head = inInFirst(head, 5);
    head = inInFirst(head, 29);
    head = inInLast(head, 30);
    head = inInLast(head, 40);
    head = inInFixPos(head, head, 100);
    cout << "before delete" << endl;
    traverse(head);

    head = deleteNode(head, head);
    head = deleteNode(head, head->next);

    cout << "after delete" << endl;
    traverse(head);;
    return 0;
}
