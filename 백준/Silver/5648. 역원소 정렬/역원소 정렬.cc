
#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	string num;
	priority_queue<long long,vector<long long>, greater<long long>> pq;

	for(int i=0; i<n;++i)
	{
		cin >> num;

		reverse(num.begin(), num.end());
		pq.push(stoll(num));
	}

	while (!pq.empty())
	{
		cout << pq.top() << '\n';
		pq.pop();
	}

	return 0;
}