
#include <bits/stdc++.h>

using namespace std;

int n, c;

vector<pair<int,int>> vec;

bool tmp(pair<int,int> a, pair<int,int> b)
{
	return a.first > b.first; 
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;

	int num;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;

		bool check = false;
		for (auto& i : vec)
		{
			if (i.second == num)
			{
				check = true;
				i.first++;
				break;
			}
		}

		if (check == false) vec.push_back({ 1,num });
	}
	
	stable_sort(vec.begin(), vec.end(), tmp);
	
	for (int i = 0; i < vec.size(); ++i)
	{
		int cnt = vec[i].first;
		while (cnt--)
		{
			cout << vec[i].second << '\n';
		}
	}
	return 0;
}