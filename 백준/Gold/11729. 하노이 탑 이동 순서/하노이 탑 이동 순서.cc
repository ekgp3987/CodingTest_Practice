
#include <bits/stdc++.h>

using namespace std;

// 정의 : 원판 n개를 기둥 1에서 3으로 옮기는 방법을 출력하는 함수
// => hanoi(k-1)을 부른다고 재귀 성립 x
// 재정의 : 원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력하는 함수
// base condition : n=1일때, a에서 b로 옮긴다. 
/* 
재귀식
1. n-1개의 원판을 a에서 기둥 6-a-b로 옮긴다. a도 b도 아닌 기둥.
2. n번 원판을 a에서 b로 옮긴다.
3. n-1개의 원판을 기둥 6-a-b에서 기둥 b로 옮긴다. 
*/

void hanoi(int a, int b, int n)
{
	if (n == 1)
	{
		cout << a << ' ' << b << '\n';
		return;
	}

	hanoi(a, 6 - a - b, n - 1);
	cout << a << ' ' << b << '\n';
	hanoi(6 - a - b, b, n - 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);             

	int k;
	cin >> k;
	//cout << pow(2,k) -1 << '\n';
	cout << (1<<k) - 1 << '\n';
	hanoi(1,3,k);

	return 0;
}