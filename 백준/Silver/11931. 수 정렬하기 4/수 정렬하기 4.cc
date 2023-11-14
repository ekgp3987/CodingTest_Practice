
#include <bits/stdc++.h>

using namespace std;

int n;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int num;

	priority_queue<int> pq;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		pq.push(num);
	}

	
	while(!pq.empty())
	{
		cout << pq.top() << '\n';
		pq.pop();
	}
	
	return 0;
}