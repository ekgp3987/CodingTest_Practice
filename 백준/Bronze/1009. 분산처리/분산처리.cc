
#include <iostream>
using namespace std;


int main()
{
    int numCase;
    cin >> numCase;

    for (int i = 0; i < numCase; i++)
    {
        int answer = 1; // a^b를 만들기 위해서 1이어야한다. 

        int a, b;
        cin >> a >> b;

        for (int j = 0; j < b; j++)
        {
            // 제곱을 해야하니까 b만큼 a를 곱해주고 나머지를 계속 구해둠
            answer *= a;
            answer %= 10;
        }

        if (answer == 0) answer = 10;
        cout << answer << endl;
    }

    return 0;
}

