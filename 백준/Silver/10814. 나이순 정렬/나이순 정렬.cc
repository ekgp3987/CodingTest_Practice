
#include <bits/stdc++.h>

using namespace std;

int n;

int age;
string name;
vector<pair<int, string>> vecMember;
pair<int,string> tmp[100001];

void merge(int st, int en)
{
	int mid = (st + en) / 2;

	int lidx = st;
	int ridx = mid;
	
	for (int i = st; i < en; ++i)
	{
		if (ridx == en) tmp[i] = vecMember[lidx++];
		else if (lidx == mid) tmp[i] = vecMember[ridx++];
		else if (vecMember[lidx].first > vecMember[ridx].first) tmp[i] = vecMember[lidx++];
		else tmp[i] = vecMember[ridx++];
	}

	for (int i = st; i < en; ++i) vecMember[i] = tmp[i];
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
		cin >> age;
		cin >> name;
	
		vecMember.push_back({ age, name });
	}

	merge_sort(0, n);
	
	for (int i = 0; i < n; ++i)
	{
		cout << vecMember.back().first << " " << vecMember.back().second << '\n';
		vecMember.pop_back();
	}

	return 0;
}