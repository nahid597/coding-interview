#include<bits/stdc++.h>

using namespace std;

vector<int>adj[100];
int visited[100];
int recstack[100];

bool isCycle(int at)
{
   //cout << "nahid" << endl;

         visited[at] = 1;
         recstack[at] = 1;

        //cout << at << " ";

        for(int i = 0; i < adj[at].size(); i++)
        {
           if(recstack[adj[at][i]] == 0) {
              if(visited[adj[at][i]] == 0) {
                return isCycle(adj[at][i]);
              }
           }
           else {
              return true;
           }
        }

        recstack[at] = 1;
        return false;

   }

int main()
{

    int n;

    cout << "enter how may numbrs of node " << endl;
    cin >> n;

    int node[1000] = {0}, st[10000] = {0};

    int a, b, k = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;

        adj[a].push_back(b);

        if(st[a] == 0)
        {
           node[k++] = a;
           st[a] = 1;
        }

        if(st[b] == 0)
        {
           node[k++] = b;
           st[b] = 1;
        }
    }

    bool flag = false;



    for(int i = 0; i < k; i++)
    {
        for(int i = 0; i < 100; i++)
        {
            visited[i] = 0;
            recstack[i] = 0;
        }

        if(isCycle(node[i]))
        {
           flag = true;
           break;
        }
    }

    if(flag)
      cout << "circle found " << endl;
    else
      cout << "circle not found" << endl;



    return 0;
}


