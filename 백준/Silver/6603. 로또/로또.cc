
#include <bits/stdc++.h>

using namespace std;

int n;
int num[15];
int arr[15];

bool isused[15];
void func(int k, int cur)
{
	if (k == 6)
	{
		for (int i = 0; i < 6; ++i)
			cout << num[arr[i]]  << ' ';

		cout << "\n";
		return;
	}

	for (int i = cur; i < n; ++i)
	{
		arr[k] = i;
		func(k + 1, i+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		cin >> n;
		if (n == 0) return 0;

		for (int i = 0; i < n; ++i)
			cin >> num[i];

		sort(num, num + n);
		func(0,0);

		cout << '\n';
	}
}