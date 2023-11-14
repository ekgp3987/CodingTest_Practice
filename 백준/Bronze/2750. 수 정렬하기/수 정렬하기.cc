
#include <bits/stdc++.h>

using namespace std;

int n, m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int num;
	vector<int> arr;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	for (auto s : arr)
	{
		cout << s << '\n';
	}
	return 0;
}