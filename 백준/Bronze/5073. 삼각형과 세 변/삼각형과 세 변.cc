#include <iostream>
#include <queue>
//#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c;

	queue<string> q;
	while (true)
	{
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) break;

		int maxLine = std::max(std::max(a, b), c);

		// 가장 긴변의 길이보다 나머지 두변의 길이의 합이 길지 않은 경우
		if (a + b + c - maxLine <= maxLine)
			q.push("Invalid");
		else if ((a == b) && (b == c)) 
			q.push("Equilateral");
		else if ((a == b) || (b == c) || (a == c)) 
			q.push("Isosceles");
		else if (a != b && b != c && a != c)  
			q.push("Scalene");

	}

	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}

	return 0;
}