
#include <bits/stdc++.h>

using namespace std;

int n, m;

int arrA[1000002];
int arrB[1000002];

int arrC[1000002];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> arrA[i];
	for (int j = 0; j < m; ++j)
		cin >> arrB[j];

	sort(arrA, arrA + n);
	sort(arrB, arrB + m);

	int idxA = 0;
	int idxB = 0;

	for (int i = 0; i < n+m; ++i)
	{
		if (idxA == n)  arrC[i] = arrB[idxB++];
		else if (idxB == m) arrC[i] = arrA[idxA++];
		else
		{
			if (arrA[idxA] <= arrB[idxB])
				arrC[i] = arrA[idxA++];
			else
				arrC[i] = arrB[idxB++];
		}
	}

	for (int i = 0; i < n + m; ++i)
		cout << arrC[i] << " ";

	return 0;
}