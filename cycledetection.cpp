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

bool cycleDetection(node *head)
{
    node *current_node = head;

    node *cycleNode = NULL;

    ///using extra memory
   /* unordered_set<node*>uset;

    while(current_node != NULL)
    {
        if(uset.find(current_node) != uset.end())
          return true;

          uset.insert(current_node);

        current_node = current_node->next;
    }*/

    /// using floyd cycle detection

    node *slow = head;
    node *fast = head;

    bool flag = false;

    while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow)
        {
            flag = true;
            break;
        }
    }

    node *start_node = head;
    node *same_node = fast;

    while(start_node != same_node)
    {
      start_node = start_node->next;
      same_node = same_node->next;
    }

    if(flag)
    {
        cout << same_node->data << endl;
    }

   // cout << "fas " << fast->data << " " << slow->data << endl;

    return flag;

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

node *makecycyle(node *head)
{
    node *current_node = head;

    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    //cout << "ca "<< current_node->data << endl;
    current_node->next = head->next->next;

    return head;

}


int main()
{
    node *head = NULL;

    head = insertNodeatFirst(head, 3);
     head = insertNodeatFirst(head, 2);
      head = insertNodeatFirst(head, 1);
      head = insertNodeatLast(head, 20);
      head = insertNodeatLast(head, 10);
      head = insertNodeatFixedPosition(head, head->next->next, 30);

    cout << "before delete" << endl;
    traverse(head);

   // head = deleteNode(head, head);
   // head = deleteNode(head, head->next);

    //cout << "after delete" << endl;
    //traverse(head);

    head = makecycyle(head);

    bool ans = cycleDetection(head);
    if(ans)
        cout << "cycle find" << endl;
    else
        cout << "cycle not find" << endl;
    return 0;
}



