#include <iostream>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
int main()
{
	int angle1 = 0, angle2 = 0, angle3=0;
	cin >> angle1 >> angle2 >> angle3;

	if ((angle1 == angle2) && (angle2 == angle3) && (angle1 == 60))
		cout << "Equilateral";
	else if ((angle1 + angle2 + angle3 == 180) &&
		((angle1 == angle2) || (angle1 == angle3) || (angle2 == angle3)))
		cout << "Isosceles";
	else if ((angle1 + angle2 + angle3 == 180) &&
		angle1 != angle2 && angle2 != angle3 && angle1 != angle3)
		cout << "Scalene";
	else if (angle1 + angle2 + angle3 != 180)
		cout << "Error";

	return 0;
}