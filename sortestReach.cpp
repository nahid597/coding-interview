#include<bits/stdc++.h>

using namespace std;

vector<int>adj[100];
int visited[100];
int dist[100];
int pred[100];

bool bfs(int st,int des, int n)
{
    queue<int>q;

    for(int i = 0; i < n + 1; i++)
    {
        visited[i] = 0;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    q.push(st);
    visited[st] = 1;
    dist[st] = 0;

    while(!q.empty())
    {
        int t = q.front();
        //cout << t << endl;
        q.pop();

        for(int i = 0; i < adj[t].size(); i++)
        {
            if(visited[adj[t][i]] == 0)
            {
               int p = adj[t][i];
                q.push(p);
                visited[p] = 1;
                dist[p] = dist[t] + 1;
                pred[p] = t;

              if(p == des)
                 return true;

            }
        }
    }

    return false;
}

void shortpath(int st, int des, int n)
{
   if(bfs(st, des, n) == false)
     cout << "No destination match";
   else
   {
       cout << "destination length " << dist[des] << endl;

       cout << des << " ";
       while(pred[des] != -1)
       {
          cout << pred[des] << " ";
          des = pred[des];
       }

   }
}


int main()
{
   int a, b, n;

   cout << pred[0] << pred[1] << endl;

   cout << "how many nodes" << endl;

   cin >> n;

   for(int i = 0; i < n; i++)
   {
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
   }

   int s, d;

   cout << "enter source" << endl;
   cin >> s;

   cout << "enter des" << endl;
   cin >> d;

   shortpath(s,d, n);



    return 0;
}
