
#include <bits/stdc++.h>

using namespace std;

int n, m;

int num[10];
int arr[10];
bool isused[10];

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << num[arr[i]] << ' '; 

		}
		cout << '\n';
		return;
	}

	int st = 0;
	if (k != 0) st = arr[k - 1] + 1;
	for (int i = st; i < n; ++i)
	{
		if (!isused[i])
		{
			arr[k] = i; // k번째 인덱스를 i로 정한다.
			isused[i] = true;
			func(k + 1); // 다음 인덱스를 정하러 감.
			isused[i] = false;  
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> num[i];

	sort(num, num + n);
	func(0);
}