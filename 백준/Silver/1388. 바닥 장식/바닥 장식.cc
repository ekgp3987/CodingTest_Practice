
#include <iostream>

using namespace std;

char visited[50][50] = {};
int N, M;

bool dfs(int x, int y, char c)
{
    if (x <= -1 || x >= N || y <= -1 || y >= M || visited[x][y] == 'O')
        return false;

    if (c == '-' && c == visited[x][y])
    {
        visited[x][y] = 'O';
        dfs(x, y - 1, c); 
        dfs(x, y + 1, c);

        return true;
    }
    else if (c == '|' && c == visited[x][y])
    {
        visited[x][y] = 'O';
        dfs(x - 1, y, c);
        dfs(x + 1, y, c);

        return true;
    }

    return false;
}
int main()
{
    int cnt = 0;

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        string s;
        cin >> s;

        for (int j = 0; j < M; ++j)
        {
            visited[i][j] = s[j];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (dfs(i, j, visited[i][j])) ++cnt;
        }
    }

    cout << cnt;

    return 0;
}
