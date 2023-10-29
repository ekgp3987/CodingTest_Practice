
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int n, m;

string board[1002];
int dist1[1002][1002]; // fire
int dist2[1002][1002]; // J

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> board[i];
		fill(dist1[i], dist1[i] + m, -1);
		fill(dist2[i], dist2[i] + m, -1);
	}
	

	queue<pair<int, int>> Q1;
	queue<pair<int, int>> Q2;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'F') 
			{
				Q1.push({ i,j });
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'J')
			{
				Q2.push({ i,j });
				dist2[i][j] = 0;
			}
		}
	}

	while (!Q1.empty())
	{
		auto cur = Q1.front(); Q1.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;

			dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
			Q1.push({ nx,ny });
		}
	}

	while (!Q2.empty())
	{
		auto cur = Q2.front(); Q2.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				// end point
				cout << dist2[cur.first][cur.second] + 1;
				return 0;
			}

			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue;
			//  불의 전파시간을 조건에 추가(dist1[nx][ny] 가 -1이 아니면 불이 방문했다는 뜻

			dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
			Q2.push({ nx, ny });

		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}