
#include <iostream>
#include <queue>

using namespace std;


int N, M, V;

bool map[1001][1001];
bool visited[1001] = {};
queue<int> q;

// 정점 번호는 1번부터 N번까지이다.
void dfs(int V)
{
    visited[V] = true;
    cout << V << " ";

    for (int i = 1; i <= N; ++i)
    {
        if (map[V][i] && !visited[i])
            dfs(i);
    }
}

void bfs(int V)
{
    q.push(V);
    visited[V] = true;
    cout << V << " ";

    while(!q.empty())
    {
        V = q.front();
        q.pop();

        for (int i = 1; i <= N; ++i)
        {
            if (map[V][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
                cout << i << " ";
            }
        }
    }
}


int main()
{
    cin >> N >> M >> V;

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        map[a][b] = true;
        map[b][a] = true;
    }

    dfs(V);

    // clear
    for (int i = 0; i < 1001; ++i)
    {
        visited[i] = false;
    }
    cout << '\n';

    bfs(V);

    return 0;
}
