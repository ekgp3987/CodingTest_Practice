
#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];

void func(int k)
{
	if (k == m)
	{
		int arr1[10] = {};
		for (int i = 0; i < m; ++i)
		{
			if (i > 0 && arr1[i - 1] > arr[i])
				break;

			arr1[i] = arr[i];

			if (i == m - 1)
			{
				for (int j = 0; j < m; ++j)
					cout << arr1[j] << ' ';


				cout << '\n';
			}

			//cout << arr[i] << ' ';
		}
		return;
	}

	
	for (int i = 1; i <= n; ++i)
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
	func(0);
	return 0;
}