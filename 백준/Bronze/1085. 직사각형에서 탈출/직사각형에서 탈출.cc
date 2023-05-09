#include <iostream>

using namespace std;
int main()
{

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int array[4] = { x, y, w - x, h - y };

	int small = array[0];
	for (int i = 0; i < 4; ++i)
	{
		if (small > array[i])
		{
			small = array[i];
		}
	}

	cout << small;
	return 0;
}