
#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr[10001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int num;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		arr[num]+=1;
	}

	int i = 1;
	int cnt = 0;
	while (cnt < n)
	{
		if (arr[i] > 0)
		{
			num = arr[i];
			for (int j = 0; j < num; ++j)
			{
				cout << i << '\n';
				cnt++;
			}
		}
		i++;
	}
	return 0;
}