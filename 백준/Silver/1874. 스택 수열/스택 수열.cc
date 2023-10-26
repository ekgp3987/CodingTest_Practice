#include <iostream>
#include <string>
#include <stack>
#include <list>
using namespace std;

list<char> result = {};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	stack<int> s = {};
	bool ok = false;


	int i = 1;
	while (n--) // n의 개수만큼 반복.
	{
		int num;
		cin >> num;

		while (i <= num)
		{
			s.push(i++);
			result.push_back('+');
		}

		if (s.top() != num)
		{
			cout << "NO";
			return 0;
		}

		s.pop();
		result.push_back('-');
	}

	for (auto c : result)
		cout << c << '\n';
	return 0;
}