
#include <bits/stdc++.h>

using namespace std;

int n;

int x;
int y;
vector<pair<int, int>> vec;
pair<int,int> tmp[100001];

void merge(int st, int en)
{
	int mid = (st + en) / 2;

	int lidx = st;
	int ridx = mid;
	
	for (int i = st; i < en; ++i)
	{
		if (ridx == en) tmp[i] = vec[lidx++];
		else if (lidx == mid) tmp[i] = vec[ridx++];
		else if (vec[lidx].first > vec[ridx].first) tmp[i] = vec[lidx++];
		else if (vec[lidx].first == vec[ridx].first)
		{
			if (vec[lidx].second <= vec[ridx].second)
				tmp[i] = vec[ridx++];
			else
				tmp[i] = vec[lidx++];
		}
		else tmp[i] = vec[ridx++];
	}

	for (int i = st; i < en; ++i) vec[i] = tmp[i];
}


void merge_sort(int st, int en)
{
	if (st + 1 == en)	return;

	int mid = (st + en) / 2;

	merge_sort(st, mid);
	merge_sort(mid, en);

	merge(st, en);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		cin >> y;
	
		vec.push_back({ x, y });
	}

	merge_sort(0, n);
	
	for (int i = 0; i < n; ++i)
	{
		cout << vec.back().first << " " << vec.back().second << '\n';
		vec.pop_back();
	}

	return 0;
}