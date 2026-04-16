#include <iostream>
#include <vector>

using namespace std;

//Max number stipluated in the problem is 10k
vector<int> adj[100001];
bool visited[100001];


void dfs(int s) 
{
  visited[s] = true;
  for (int u : adj[s]) 
  {
    if (!visited[u]) 
    {
        dfs(u);
    }
  }
}

int main() {

    //Reading in the number of cities and roads
    int n, m;
    cin >> n >> m;

    // Building the adjacency list for the graph
    for (int i = 0; i < m; i++) 
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //Seeing if element repeats and then putting first thing in defs
    vector<int> reps;
    for (int i = 1; i <= n; i++) 
    {
        if (!visited[i]) 
        {
            reps.push_back(i);
            dfs(i);
        }
    }

    cout << reps.size() - 1 << endl;

    //Printing the pairs of cities that we will be connecting
    for (int i = 0; i < reps.size() - 1; i++) 
    {
        cout << reps[i] << " " << reps[i + 1] << endl;
    }

    return 0;
}