
#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		vector<int> vecA;
		vector<int> vecB;

		cin >> n >> m;
		int num;
		while (n--)
		{
			cin >> num;
			vecA.push_back(num);
		}
		while (m--)
		{
			cin >> num;
			vecB.push_back(num);
		}

		sort(vecA.begin(), vecA.end());
		sort(vecB.begin(), vecB.end());

		int cnt = 0;
		for (int i = 0; i < vecA.size(); ++i)
		{
			for (int j = 0; j < vecB.size(); ++j)
			{
				if (vecA[i] > vecB[j])
					cnt++;
				else
					break;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}