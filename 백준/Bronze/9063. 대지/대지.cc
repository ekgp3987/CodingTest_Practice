#include <iostream>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;

	int minX= 10000, maxX = -10000, minY=10000, maxY= -10000;

		int x, y;
		for (int i = 0; i < n; ++i)
		{
			cin >> x >> y;
			minX = min(minX, x);
			maxX = max(maxX, x);
			minY = min(minY, y);
			maxY = max(maxY, y);
		}

		if (n == 1) cout << 0;
		else cout << (maxX - minX) * (maxY - minY);

	return 0;
}