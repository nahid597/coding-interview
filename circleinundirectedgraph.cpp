#include<bits/stdc++.h>

using namespace std;

vector<int>adj[100];

int visited[100];

bool isCycle(int s, int p)
{
    //if(visited[s]) return;

   // if(visited[s] == 0)
    //{
         visited[s] = 1;
        //recstack[s] = 1;

       // cout << s << endl;

        for(int i = 0; i < adj[s].size(); i++)
        {
            if(visited[adj[s][i]] == 0)
            {
               if( isCycle(adj[s][i], s))
               {
                  return true;
               }
            }

            else if(p != adj[s][i])
                return true;
        }

    //}
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

    bool flag = flag;

    for(int i = 0; i < 100; i++)
    {
        visited[i] = 0;
    }

    for(int i = 0; i < k; i++)
    {
        if(visited[node[i]] == 0)
        {
            if(isCycle(node[i], -1))
            {
               flag = true;
               break;
            }
        }
    }

    if(flag)
      cout << "circle found " << endl;
    else
      cout << "circle not found" << endl;



    return 0;
}


