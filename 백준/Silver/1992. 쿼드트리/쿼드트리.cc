#include <bits/stdc++.h>

using namespace std;


int N;
string board[65];

int now = 0;
int check(int x, int y, int n)
{
	for(int i=x; i<x+n; i++)
		for (int j = y; j < y + n; j++)
		{
			if (board[x][y] -'0' != board[i][j] - '0') return false;
		}
	now = board[x][y] - '0';
	return true;
}

void zip(int x, int y, int n)
{
	if (check(x, y, n))
	{
		cout << now;
		return;
	}

	cout << "(";
	int next = n / 2;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			zip(x+ i* next, y+j*next, next);
		}
	}
	cout << ")";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	 
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> board[i];

	zip(0, 0, N);

	return 0;
}