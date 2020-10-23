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

bool palindrome(node *head)
{
    stack<int>st;
    node *current_node = head;

    while(current_node != NULL)
    {
        st.push(current_node->data);
        current_node = current_node->next;
    }

    current_node = head;

    bool pal = true;

    while(current_node != NULL)
    {
        //cout << current_node->data << " = " << st.t
        if(current_node->data != st.top())
        {
           pal = false;
           break;
        }

         st.pop();
        current_node = current_node->next;
    }

    return pal;

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


int main()
{
    node *head = NULL;

    head = insertNodeatFirst(head, 3);
     head = insertNodeatFirst(head, 2);
      head = insertNodeatFirst(head, 1);
      head = insertNodeatLast(head, 2);
      head = insertNodeatLast(head, 1);
      head = insertNodeatFixedPosition(head, head->next->next, 3);

    cout << "before delete" << endl;
    traverse(head);

   // head = deleteNode(head, head);
   // head = deleteNode(head, head->next);

    //cout << "after delete" << endl;
    //traverse(head);

    bool ans = palindrome(head);
    if(ans)
        cout << "palindrome" << endl;
    else
        cout << "not palindrome" << endl;
    return 0;
}


