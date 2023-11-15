
#include <bits/stdc++.h>

using namespace std;

int n;

bool tmp(string a, string b)
{
	if (a.size() != b.size()) return a.size() < b.size();

	return a < b;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	vector<string> vecStr;
	string word;
	while (n--)
	{
		cin >> word;
		vecStr.push_back(word);
	}

	sort(vecStr.begin(), vecStr.end(), tmp);

	// 중복 제거
	vecStr.erase(unique(vecStr.begin(), vecStr.end()), vecStr.end());

	for (auto s : vecStr)
		cout << s << '\n';
	return 0;
}