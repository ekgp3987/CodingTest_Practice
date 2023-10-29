
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second

int arr[1000][1000] = {};

bool vis[1000][1000];
int n, m; // 행의 수, 열의 수

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	int mx =0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (arr[i][j] == 0 || vis[i][j])continue;
			cnt++;

			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({ i,j }); // start point

			int area = 0;
			while (!Q.empty())
			{
				area++;
				pair<int, int> cur = Q.front(); Q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || arr[nx][ny] != 1) continue;

					vis[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}

			mx = max(area, mx);
		}
	}

	cout << cnt << '\n';
	cout <<  mx;

	return 0;
}