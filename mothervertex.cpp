#include<bits/stdc++.h>

using namespace std;

int visited[100];

vector<int>adj[100];


void bfs(int s, int n)
{
  for(int i = 0; i <= n; i++)
    visited[i] = 0;

  int cnt = 0;

    queue<int>Q;

    visited[s] = 1;
    Q.push(s);

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        cnt++;

        //cout << u << " -> ";

        for(int i = 0; i < adj[u].size(); i++)
        {
           if(visited[adj[u][i]] == 0)
           {
              int v = adj[u][i];

              visited[v] = 1;
              Q.push(v);
           }
        }
    }

    if(cnt == n)
    {
        cout << s << endl;
    }

}

int main()
{
    int n, a, b;

    cout << "Enter number of nodes: " << endl;
    cin >> n;


    int node[10000] = {0}, st[1000] = {0},  k = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
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

        adj[a].push_back(b);
    }

   // bfs();

   cout << " enter start node " << endl;

   for(int i = 0; i < k; i++)
   {
       bfs(node[i], k);
   }

   cout << endl;




    return 0;
}
