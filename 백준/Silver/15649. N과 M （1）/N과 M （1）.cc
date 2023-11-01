
#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
bool isUsed[10];

void func(int k)
{
	// m개를 모두 택했으면 arr에 기록된 수를 출력한다.
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!isUsed[i]) // 아직 i가 사용되지 않았다면
		{
			arr[k] = i;
			isUsed[i] = true;
			func(k + 1);
			isUsed[i] = false;
			// 현재 값이 i인 arr[k]는 굳이 0과 같은 값으로
			// 변경할 필요가 없는데 어차피 자연스럽게
			// 다른 값으로 덮힐 예정이라 그렇다.
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);

	return 0;
}