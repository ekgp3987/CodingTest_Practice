
#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
int num[10];

int cnt[10002];
vector<int> tt;

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << tt[arr[i]] << ' ';
		}
		cout << "\n";
		return;
	}

	int st = 0;
	if (k != 0) st = arr[k - 1];
	for (int i = st; i < n; ++i)
	{
		arr[k] = i;
		func(k + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
		cnt[num[i]]++;
	}

	int idx = 0;
	for (int i = 1; i < 10002; ++i)
	{
		if (cnt[i])
		{
			tt.push_back(i);
			idx++;
		}
	}
	n = idx;

	func(0);
}