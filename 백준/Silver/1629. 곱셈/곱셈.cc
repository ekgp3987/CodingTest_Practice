
#include <bits/stdc++.h>

using namespace std;

int res(long long a, long long b, long long c)
{
	if (b == 1) return a% c;

	// a^n * a^n = a^2n
	long long val = res(a, b / 2, c);
	val = val * val % c; // 4^58mod m =  16^29mod m  

	if (b % 2 == 0) return val; // b가 짝수일 경우 val을 한번 더 곱해주지 않는다.
	return val * a % c; // 홀수일경우 
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);             

	long long a, b, c;
	cin >> a >> b >> c;
	

	cout << res(a, b, c);
	return 0;
}