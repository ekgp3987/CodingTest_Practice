
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
			cout << num[arr[i]] << ' '; 
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (!isused[i]) // i가 아직 사용되지 않았을 경우
		{
			arr[k] = i; // k번쨰 인덱스를 i로 정함.
			isused[i] = true; 
			func(k + 1);
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