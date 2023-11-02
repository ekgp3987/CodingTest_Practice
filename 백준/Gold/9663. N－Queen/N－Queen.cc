
#include <bits/stdc++.h>

using namespace std;


int cnt = 0;
int n;

bool isused1[40]; // col
bool isused2[40]; // 우상향 대각선
bool isused3[40]; // 우하향 대각선

void func(int cur)
{
	if (cur == n)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		// (cur,i)
		if (isused1[i] || isused2[i+cur] || isused3[cur - i + n - 1])
			continue;

		isused1[i] = true;
		isused2[i + cur] = true;  // (x+y)
		isused3[cur - i + n - 1] = true; // x-y 인덱스를 음수로 보내지 않기 위해 n-1 추가.

		func(cur + 1);

		isused1[i] = false;
		isused2[i + cur] = false;
		isused3[cur - i + n - 1] = false;
	}
}
int main()
{
	// 퀸은 어디 둘 수 있을까?
	// 대각선으로만 둘 수 있으니 각 '행'에 퀸 한개씩만 놓으면 된다.
	// '열'은 y좌표가 일치하는지를 확인한다.
	// '대각선'은 
	//  x+y가 같으면 같은 좌측 하단, 우측 상단을 잇는 대각선에 위치
	//  x-y가 같으면 같은 좌측 상단, 우측 하단을 잇는 대각선에 위치 

	// 시간 절약
	// 각 대각선과 열의 점유상태를 나타낼 isused변수를 두면 시간을 절약할 수 있다.

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	func(0);

	cout << cnt;
}