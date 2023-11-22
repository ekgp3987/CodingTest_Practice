#include <bits/stdc++.h>

using namespace std;

int h, w;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> h >> w;

	vector<int> height(w); // 처음 vector 개수 w개로 생성

	for (int i = 0; i < w; ++i)
		cin >> height[i];
	
	int answer = 0;
	for (int i = 1; i < w - 1; ++i)
	{
		int left = 0; 
		int right = 0;

		// max val in left
		for (int j = 0; j < i; ++j) left = max(left, height[j]);
		// max val in right
		for (int j = w - 1; j > i; j--) right = max(right, height[j]);
		
		answer += max(0, min(left, right) - height[i]);
	}

	cout << answer << '\n';

	return 0;
}