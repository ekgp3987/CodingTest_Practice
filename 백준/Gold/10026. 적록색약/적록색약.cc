
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int vis[102][102];
string board[102];

int n;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main()
{
	cin >> n;

	for(int i=0; i<n; ++i)
		cin >> board[i];
	
	int RGBcnt=0;
	int R_Bcnt=0;

	// 적록색약인 아닌 경우
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			queue<pair<int, int>> Q;

			if (vis[i][j]) continue;

			RGBcnt++;
			Q.push({ i,j });
			vis[i][j] = 1;

			char color = board[i][j];

			while (!Q.empty())
			{
				auto cur = Q.front(); Q.pop();

				for (int dir = 0; dir < 4; ++dir)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis[nx][ny] || color!=board[nx][ny]) continue;

					vis[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}

		}
	}

	//  Green -> Red, init
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (board[i][j] == 'G')
				board[i][j] = 'R';

			vis[i][j] = 0;
		}
	}


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			queue<pair<int, int>> Q;

			if (vis[i][j]) continue;

			R_Bcnt++;
			Q.push({ i,j });
			vis[i][j] = 1;
			char color = board[i][j];
			while (!Q.empty())
			{
				auto cur = Q.front(); Q.pop();

				for (int dir = 0; dir < 4; ++dir)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis[nx][ny] || color != board[nx][ny]) continue;

					vis[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}

		}
	}

	cout << RGBcnt  << " " << R_Bcnt;
	return 0;
}