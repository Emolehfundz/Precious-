// Dijkstra, Dijkstra.
// UVa ID: 10806
// Verdict: Accepted
// Submission Date: 2017-10-05
// UVa Run Time: 0.000s
//
// 版权所有（C）2017，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

const int MAXV = 110, MAXE = 20100, INF = 0x3fffffff;

struct arc { int u, v, capacity, residual, cost, next; } arcs[MAXE];

int idx, source, sink, dist[MAXV], head[MAXV], parent[MAXV], visited[MAXV];
int n, m, fee, flow;

bool spfa()
{
    for (int i = 0; i <= MAXV; i++)
        dist[i] = INF, parent[i] = -1, visited[i] = 0;

    dist[source] = 0, visited[source] = 1;
    queue<int> q; q.push(source);

    while (!q.empty())
    {
        int u = q.front(); q.pop(); visited[u] = 0;
        for (int i = head[u]; ~i; i = arcs[i].next)
        {
            arc e = arcs[i];
            if (e.residual > 0 && dist[e.v] > dist[u] + e.cost)
            {
                dist[e.v] = dist[u] + e.cost;
                parent[e.v] = i;
                if (!visited[e.v])
                {
                    q.push(e.v);
                    visited[e.v] = 1;
                }
            }
        }
    }

    return dist[sink] < INF;
}

void addArc(int u, int v, int capacity, int cost)
{
    arcs[idx] = (arc){u, v, capacity, capacity, cost, head[u]};
    head[u] = idx++;
    arcs[idx] = (arc){v, u, capacity, 0, -cost, head[v]};
    head[v] = idx++;
}

void mcmf()
{
    fee = flow = 0;
    while (spfa())
    {
        int delta = INF;
        for (int i = parent[sink]; ~i; i = parent[arcs[i].u])
            delta = min(delta, arcs[i].residual);
        flow += delta, fee += delta * dist[sink];
        for (int i = parent[sink]; ~i; i = parent[arcs[i].u])
        {
            arcs[i].residual -= delta;
            arcs[i ^ 1].residual += delta;
        }
    }
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int u, v, t, d, k;

    while (cin >> n, n > 0)
    {
        cin >> m;

        idx = 0, source = 0, sink = n;
        memset(head, -1, sizeof head);

        for (int i = 1; i <= m; i++)
        {
            cin >> u >> v >> t;
            addArc(u, v, 1, t);
            addArc(v, u, 1, t);
        }
        addArc(0, 1, 2, 0);

        mcmf();
        
        if (flow < 2) cout << "Back to jail\n";
        else cout << fee << '\n';
    }
    
    return 0;
}
