#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr, arr + 3); //  끝 +1까지 넣어야함.
	
	// 삼각형 성질 성립 -> 수정 x
	if (arr[0] + arr[1] > arr[2])
		cout << arr[0] + arr[1] + arr[2];
	else // 제일 긴 변의 길이를 변경-> 수정 o
		cout << arr[0] + arr[1] + (arr[0] + arr[1] - 1);
	return 0;
}