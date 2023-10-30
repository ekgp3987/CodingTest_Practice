
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int dx[8] = { 1,  2, 2, 1, -1,-2,-2,-1 };
int dy[8] = { -2, -1,1, 2, 2,  1,-1,-2 };

int dist[302][302];

int n, s, m;

int i, j;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);                  

	int t;
	cin >> t;

	while (t--)
	{
		cin >> n;

		for (int i =0; i < n; ++i)
		{
			fill(dist[i], dist[i] + n, -1);
		}

		queue<pair<int, int>> Q;

		cin >> i >> j; // start

		Q.push({ i,j });
		dist[i][j] = 0;

		cin >> i >> j; // goal


		while (!Q.empty())
		{
			auto cur = Q.front(); Q.pop();

			for (int dir = 0; dir < 8; ++dir)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) 
					continue;
				if (dist[nx][ny] != -1) 
					continue;
				
				Q.push({ nx, ny });
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
			}
		}

		cout << dist[i][j] << '\n';
	}


	return 0;
}