#include <queue>
#include <iostream>

using namespace std;

int N, M;
int graph[201][201] = {}; // 200까지여서 +1

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int moveCnt = 0;


int bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });

    while (!q.empty())
    {
        int qX = q.front().first;
        int qY = q.front().second;
        q.pop();

        // 상하좌우로 확인
        for (int i = 0; i < 4; ++i)
        {
            int nX = qX + dx[i];
            int nY = qY + dy[i];

            // 공간 밖, 괴물(0) 무시
            if (nX < 0 || nX >= N || nY < 0 || nY >= M || graph[nX][nY] == 0)
                continue;

            if (graph[nX][nY] == 1)
            {
                // 이전값 +1
                graph[nX][nY] = graph[qX][qY] + 1;
                q.push({ nX,nY });
            }
        }
    }

    return graph[N - 1][M - 1];
}


int main()
{
    cin >> N >> M;

    // 숫자 한줄을 문자열로 받고 자르기. 
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            graph[i][j] = s[j] - '0';
        }
    }

    cout << bfs(0, 0) << '\n';
    return 0;
}