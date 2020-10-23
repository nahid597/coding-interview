#include<bits/stdc++.h>

using namespace std;

stack<int>st;

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

void reverLinkListMN(node *head, int m, int n)
{
    node *current_node = head;
    node *start_node = head;

    int cnt = 0;

    while(current_node != NULL)
    {
        cnt++;
        if(cnt >= m & cnt <= n)
        {
            st.push(current_node->data);
        }
        current_node = current_node->next;
    }

    cnt = 0;

    while(start_node != NULL)
    {
        cnt++;
        if(cnt >= m & cnt <= n)
        {
           cout << st.top() << " -> ";
           st.pop();
        }
        else
        {
            cout << start_node->data << " -> ";
        }
        start_node = start_node->next;
    }


}

void traverse(node *head)
{
    node *current_node = head;

    while(current_node != NULL)
    {
        cout << current_node->data << " -> ";
        current_node = current_node->next;
    }

    cout << endl;

}


int main()
{
    node *head = NULL;

    int m, n;
    cin >> m >> n;

    head = insertNodeatFirst(head,3);
     head = insertNodeatFirst(head, 2);
      head = insertNodeatFirst(head, 1);
      head = insertNodeatLast(head, 4);
      head = insertNodeatLast(head, 5);
     // head = insertNodeatFixedPosition(head, head->next->next, 50);

    cout << "before reverse" << endl;
    traverse(head);

    cout << "after reverse" <<endl;
    reverLinkListMN(head, m, n);


    return 0;
}


