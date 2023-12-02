#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int num;
	vector<int> vec;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		vec.push_back(num);
	}
	
	vector<int> answer(n, -1000);

	answer[0] = vec[0];
	for (int i = 1; i < n; ++i)
	{
		answer[i] = max(vec[i], answer[i - 1] + vec[i]);
	}
	
	cout << *max_element(answer.begin(), answer.end());
	return 0;
}