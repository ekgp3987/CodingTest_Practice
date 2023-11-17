#include <bits/stdc++.h>

using namespace std;

int n, k;

int money[15];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int answer = 0;

	cin >> n >> k;

	for (int i = 0; i < n; ++i) cin >> money[i];
	for (int i = n - 1; i >= 0; --i)
	{
		answer += k / money[i]; // 해당 금액으로 몇번 나눠지는지. 더한다.
		k%= money[i]; // 그만큼 사용했으니 나머지가 남은 금액.

		// 큰 동전부터 작은 동전까지 계속 사용해본다. 
	}

	cout << answer;
	return 0;
}