#include<bits/stdc++.h>

using namespace std;

vector<int>adj[100];
int visited[100];

void dfs(int at)
{
   //cout << "nahid" << endl;
    visited[at] = 1;

    cout << at << " ";

    for(int i = 0; i < adj[at].size(); i++)
    {
       if(visited[adj[at][i]] == 0)
       {
           dfs(adj[at][i]);
       }
    }

}

int main()
{

    int n;
   cout << "Enter numer of edges ";
   cin >> n;

   int a, b;

   for(int i = 0; i < n; i++)
   {
      cin >> a >> b;
      adj[a].push_back(b);
   }

   int s;

   cout << "enter start node ";
   cin >> s;

   dfs(s);


    return 0;
}
