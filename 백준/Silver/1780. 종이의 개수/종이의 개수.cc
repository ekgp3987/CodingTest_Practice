
#include <bits/stdc++.h>

using namespace std;


int N;
int arr[2200][2200];
int cnt[3]; // -1, 0, 1 로 채워진 종이 갯수
// cnt[0] 이 -1, cnt[1] 이 0, cnt[2] 이 1

// 함수 : (x,y) 부터 n길이까지의 내부가 다르면 9등분 해서 다시 (x,y) 내부 판별
// 

bool check(int x, int y, int n)
{
	for(int i=x; i<x+n; i++)
		for (int j = y; j < y + n; j++)
		{
			if (arr[x][y] != arr[i][j]) return false;
		}
	return true;
}
void paper(int x, int y, int n)
{
	if (check(x, y, n))
	{
		cnt[arr[x][y] + 1] += 1;
		return;
	}

	int next = n / 3;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			paper(x + i * next,  y + j * next, next);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	 
	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> arr[i][j];

	paper(0, 0, N);

	for (int i = 0; i < 3; ++i) cout << cnt[i] << "\n";
	return 0;
}