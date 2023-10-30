
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int t, n, m, k;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		int vis[51][51] = {};
		int board[51][51] = {};

		cin >>m >>n >> k;

		queue<pair<int, int>> Q;

		while (k--)
		{
			int i, j;
			cin >> i >> j;
			board[j][i] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (board[i][j] != 1 || vis[i][j] == 1) continue;
				cnt++;
				queue<pair<int, int>> q;
				vis[i][j] = 1;

				q.push({ i,j });

				while (!q.empty())
				{
 					auto cur = q.front(); q.pop();
					vis[cur.first][cur.second] = 1;

					for (int dir = 0; dir < 4; ++dir)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] == 1 || board[nx][ny] != 1) continue;

						vis[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}

			}
		}
		cout << cnt << '\n';
	}
	return 0;
}