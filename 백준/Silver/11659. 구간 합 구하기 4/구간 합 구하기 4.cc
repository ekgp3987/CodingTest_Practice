#include <bits/stdc++.h>

using namespace std;

int d[100005];

int n, m, i, j;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	vector<int> vec;

	// input
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}

	//dp
	d[0] = 0;
	d[1] = vec[0];
	d[2] = d[1] + vec[1];

	for (int i = 3; i <= n; ++i)
	{
		d[i] = d[i - 1] + vec[i - 1];
	}

	for (int k = 0; k < m; ++k)
	{
		cin >> i >> j;
		cout << d[j] - d[i-1] << '\n';
	}
	return 0;
}