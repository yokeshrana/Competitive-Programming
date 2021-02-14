#include <bits/stdc++.h>
using namespace std;
void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

void BFS(vector<int> *adj, vector<bool> &visited, int source, int dest, vector<int> &distance, vector<int> &path)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto y : adj[x])
        {
            if (!visited[y])
            {
                q.push(y);
                distance[y] = distance[x] + 1;
                path[y] = x;
                if (y == dest)
                    return;
            }
        }
    }
}

void printShortestDistance(vector<int> *adj, int source, int dest, int noOfvertices)
{
    vector<bool> visited(noOfvertices, false);
    vector<int> distance(noOfvertices, 0);
    vector<int> path(noOfvertices, -1);
    BFS(adj, visited, source, dest, distance, path);
    cout << distance[dest] << endl;

    //Construct path
    vector<int> paths;
    int crawl = dest;
    paths.push_back(crawl);
    while (path[crawl] != -1)
    {
        paths.push_back(path[crawl]);
        crawl = path[crawl];
    }
    reverse(paths.begin(), paths.end());
    for (auto x : paths)
        cout << x << " ";
}
int main()
{
    int noOfvertices = 8;
    vector<int> adj[noOfvertices];
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 2);
    add_edge(adj, 3, 4);
    add_edge(adj, 3, 7);
    add_edge(adj, 4, 5);
    add_edge(adj, 4, 6);
    add_edge(adj, 4, 7);
    add_edge(adj, 5, 6);
    add_edge(adj, 6, 7);
    int source = 0, dest = 7;
    printShortestDistance(adj, source, dest, noOfvertices);
    cout << endl;

    return 0;
}