#include <bits/stdc++.h>

using namespace std;

int n;

int d[1003];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());


	d[0] = vec[0];
	for (int i = 1; i < n; ++i)
	{
		d[i] = d[i - 1] + vec[i];
	}

	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += d[i];
	}
	cout << sum;
	return 0;
}
