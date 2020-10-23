#include<bits/stdc++.h>

using namespace std;

vector<int>adj[100];
int visited[100];
int recstack[100];

bool isCycle(int at, int p)
{
   //cout << "nahid" << endl;

         visited[at] = 1;

        //cout << at << " ";

        for(int i = 0; i < adj[at].size(); i++)
        {

              if(visited[adj[at][i]] == 0) {
                return isCycle(adj[at][i], at);
              }
              else {
                if(adj[at][i] != p)
                   return true;
           }
        }
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
        adj[b].push_back(a);

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
        }

        if(isCycle(node[i], -1))
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



