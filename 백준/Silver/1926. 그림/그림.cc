#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[505][505];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> n >> m;

	queue<pair<int, int>> q;
	queue<pair<int, int>> q2;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
			if (board[i][j])
				q.push({ i,j });
		}
	}

	if (q.empty())
	{
		cout << 0 << '\n' << 0;
		return 0;
	}

	int cnt = 0;
	int maxwidth = 0;
	while (!q.empty())
	{
		auto curq = q.front(); q.pop();
		if (board[curq.first][curq.second] == 1)
		{
			cnt++;
			q2.push(curq);
		}

		int width =1;
		while (!q2.empty())
		{
			auto curq2 = q2.front(); q2.pop();
			
			for (int dir = 0; dir < 4; ++dir)
			{
				int nx = curq2.first + dx[dir];
				int ny = curq2.second + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (nx == curq.first && ny == curq.second) continue;
				if (board[nx][ny] !=1) continue;

				q2.push({ nx,ny });
				width++;
				board[nx][ny] = board[curq2.first][curq2.second] + 1;
			}
	
		}
		maxwidth = max(maxwidth, width);
	}

	cout << cnt << '\n' << maxwidth;
	return 0;
}