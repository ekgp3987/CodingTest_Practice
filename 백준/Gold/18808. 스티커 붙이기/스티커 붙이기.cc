
#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int board[42][42];
int sticker[12][12];
int sn, sm;

int res = 0;
void rott()
{
	int tmp[12][12];

	for (int i = 0; i < sn; ++i)
	{
		for (int j = 0; j < sm; ++j)
		{
			tmp[i][j] = sticker[i][j];
		}
	}

	for (int i = 0; i < sm; ++i)
	{
		for (int j = 0; j < sn; ++j)
		{
			sticker[i][j] = tmp[sn - 1 - j][i];
		}
	}
	int temp = sm;
	sm = sn;
	sn = temp;
}

bool attach(int x, int y)
{
	for (int i = 0; i < sn; ++i)
	{
		for (int j = 0; j < sm; ++j)
		{
			// 노트북에 이미 붙어있고, 스티커부분이 1이었다면. 붙여야하는데 못붙인다. 
			if (board[i + x][j + y] && sticker[i][j]) return false; 
		}
	}

	// 스티커 붙이기.
	for (int i = 0; i < sn; ++i)
	{
		for (int j = 0; j < sm; ++j)
		{
			if(sticker[i][j])
				board[i+x][j+y] = 1;
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int ii = 0; ii < k; ++ii)
	{
		// 붙일 스티커
		cin >> sn >> sm;
		for (int i = 0; i < sn; ++i)
		{
			for (int j = 0; j < sm; ++j)
			{
				cin >> sticker[i][j];
			}
		}

		// 4번 돌리면서 계속 시도. 
		// 성공하면 탈출 
		bool isAttached = false;

		for (int dir = 0; dir < 4; ++dir)
		{
			isAttached = false;

			for (int i = 0; i <= n - sn; ++i)
			{
				if (isAttached) break;
				for (int j = 0; j <= m - sm; ++j)
				{
					if (attach(i, j))
					{
						isAttached = true;
						break;
					}
				}
			}

			if (isAttached) break;

			rott();
		}
	}
	
	
	// 스티커 붙은 칸의 수 출력
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (board[i][j] == 1) res++;

	cout << res;
}