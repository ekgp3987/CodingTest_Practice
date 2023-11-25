#include <bits/stdc++.h>

using namespace std;

int n;
long long zero[94];
long long one[94];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	zero[1] = 0; one[1] = 1;  //1
	zero[2] = 1; one[2] = 0;  // 10
	zero[3] = 1; one[3] = 1;
	zero[4] = 2; one[4] = 1;
	//zero[5] = 3; one[4] = 2;

	//d[3] = 2;  //'10 0'                  '10 1'
	//d[4] = 3;  //'10 00'       '10 01'   '10 10' 
	// d[5]   '10 000' '10 001' 10 010 ' '10 101' '10 100' 



	//끝자리가 0이면 다음이 *2
	//	1이면 다음이 1
	/*
		d[3] = d[3-1]
	*/
	for (int i = 5; i <= n; ++i)
	{
		zero[i] = one[i - 1] + zero[i - 1];
		one[i] = zero[i - 1];
	}
	

	cout << zero[n] + one[n];
	return 0;
}