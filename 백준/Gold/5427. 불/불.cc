
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int t, w, h;

int dx[4] = { 0, 0, 1,-1 };
int dy[4] = { 1, -1, 0,0 };

int board[1002][1002];
int dist1[1002][1002]; // fire
int dist2[1002][1002]; // person

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);             

	cin >> t;
	while (t--)
	{
		cin >> h >> w;

		bool bEscape = false;

		queue<pair<int, int>> Q1;
		queue<pair<int, int>> Q2;

		for (int i = 0; i < w; ++i)
		{
			fill(dist1[i], dist1[i] + h, 0);
			fill(dist2[i], dist2[i] + h, 0);
		}

		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				char c;
				cin >> c;
				if (c == '#')
				{
					board[i][j] = -1;
				}
				else
				{
					if (c == '*')
					{
						Q1.push({ i,j });
						dist1[i][j] = 1;
					}
					else if (c == '@')
					{
						Q2.push({ i,j });
						dist2[i][j] = 1;
					}

					board[i][j] = 0;
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
			
				if (nx < 0 || nx >= w || ny < 0 || ny >= h)
					continue;
				if (board[nx][ny] ==-1)
					continue;
				if(dist1[nx][ny])
					continue;
				
				Q1.push({ nx, ny });
				dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
			}
		}

		while (!Q2.empty() && (!bEscape))
		{
			auto cur = Q2.front(); Q2.pop();

			for (int dir = 0; dir < 4; ++dir)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || nx >= w || ny < 0 || ny >= h)
				{
					cout << dist2[cur.first][cur.second] << '\n';
					bEscape = true;
					break;
				}

				if (board[nx][ny] == -1) continue;
				if(dist2[nx][ny]) continue;
				// 불이 옮겨진 칸, 불이 붙으려는 칸 이동 x
				// 갈곳의 불보다 현재 나의 위치 +1 한게 더 작아야함(빨리 왔다) 
				if (dist1[nx][ny] !=0 && dist1[nx][ny] <= dist2[cur.first][cur.second]+1) 
					continue;
	

				Q2.push({ nx, ny });
				dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
			}
		}

		if (!bEscape) cout << "IMPOSSIBLE" << '\n';
	}




	return 0;
}