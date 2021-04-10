#include<bits/stdc++.h>
using namespace std;

vector<int> low_reach;
vector<int> in_time;
vector<bool> visited;
vector<int> parent;
set<int> res;
int t = 0;

void insert_edge(vector<int> adjacency[], int u, int v)
{
	adjacency[u].push_back(v);
	adjacency[v].push_back(u);
}

void print_list(vector<int> g[], int v)
{
    cout << "Adjacency List : " << '\n';
    for(int i = 0; i < v; ++i)
    {
        cout << "Vertex " << i << " : ";
        for(int j = 0; j < g[i].size(); ++j)
        {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n' << '\n';
}

void articulation_point(vector<int> g[], int v)
{
    visited[v] = true;
    low_reach[v] = in_time[v] = ++t;
    //cout << v << '\n';

    for (int i = 0; i < g[v].size(); ++i)
    {

       int u = g[v][i];
        if(!visited[u])
        {
            parent[u] = v;
            articulation_point(g, u);

            if(parent[v] == -1)
            {
                if(i >= 1)
                {
                    //cout << v << ' ' << u << '\n';
                    res.insert(v);
                }
            }
            else if(low_reach[u] >= in_time[v])
            {
                //cout << v << ' ' << u << '\n';
                res.insert(v);
            }

            low_reach[v] = min(low_reach[v], low_reach[u]);
        }
        else if(u != parent[v])
        {
            low_reach[v] = min(low_reach[v], in_time[u]);
        }

    }
}

int main()
{
    int vx, e;

    cout << "Enter number of vertices and edges of Graph : " << '\n';
    cin >> vx >> e;

    vector<int> g[vx];
    int u, v;

    cout << "Enter the edges of Graph : " << '\n';
    for(int i = 0; i < e; ++i)
    {
        cin >> u >> v;
        insert_edge(g, u, v);
    }

    in_time.assign(vx, -1);
    low_reach.assign(vx, -1);
    parent.assign(vx, -1);
    visited.assign(vx, false);

    //cout << in_time.size() << ' ' << low_reach.size() << ' ' << parent.size() << ' ' << visited.size() << '\n';
    print_list(g, vx);
    articulation_point(g, 0);

    cout << "Articulation Points : " << '\n';
    set<int> ::iterator i;
    for(i = res.begin(); i != res.end(); ++i)
    {
        cout << *i << ' ';
    }
}
