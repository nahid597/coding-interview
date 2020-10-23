#include<bits/stdc++.h>

using namespace std;

vector<int>adj[100];
int visited[100];


int bfs(int s) {
    visited[s] = 1;
    queue<int>q;
    q.push(s);
    int cnt = 0;
    while(!q.empty()) {
        int t = q.front();
        q.pop();

        cnt++;

        for(int i = 0; i < adj[t].size(); i++) {
            if(visited[adj[t][i]] == 0) {
                visited[adj[t][i]] = 1;
                q.push(adj[t][i]);
            }
        }
    }

    return cnt;
}

int main() {

   int n, a, b;

    cout << "enter number of node" << endl;

    cin >> n;

    int node[100] = {0}, st[100] = {0}, k = 0;

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

    int s;

    for(int i = 0; i < k; i++)
    {
      s = bfs(node[i]);

      if(s == k)
      {
        cout << node[i] <<  " is a mother vertex " << endl;
        break;
      }
    }
    return 0;
}
