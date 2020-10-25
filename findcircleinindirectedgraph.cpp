
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>adj[100];

int vis[100];

bool circleUtil(int v, int parent)
{
    vis[v] = 1;

    for(int i  = 0; i < adj[v].size(); i++)
    {
        if(vis[adj[v][i]] == 0)
        {
            if(circleUtil(adj[v][i], v))
                return true;
        }

        else if(adj[v][i] != parent)
          return true;
    }

    return false;
}

bool circle(int v)
{
    for(int i = 0; i < 100; i++)
    {
        vis[i] = 0;
    }

    if(circleUtil(v,-1))
        return true;

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

    for(int i = 0; i < k; i++)
    {
        if(vis[node[i]] == 0)
            if(circleUtil(node[i], -1))
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
