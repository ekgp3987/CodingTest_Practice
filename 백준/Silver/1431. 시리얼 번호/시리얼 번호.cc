
#include <bits/stdc++.h>

using namespace std;

int n;

bool cmp(string& a, string& b)
{
	if (a.size() != b.size()) return a.size() < b.size();
	else
	{
		int sumA = 0;
		int sumB = 0;
		for (int i = 0; i < a.size(); ++i)
		{
			if ('0' <= a[i] && a[i] <= '9') sumA += a[i] - '0';
			if ('0' <= b[i] && b[i] <= '9') sumB += b[i] - '0';
		}
		
		if (sumA != sumB)
			return sumA < sumB;
		
		return a < b;
	}
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	string str;
	vector<string> vec;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		vec.push_back(str);
	}

	sort(vec.begin(), vec.end(), cmp);

	for (auto v : vec)
	{
		cout << v << '\n';
	}
}

	