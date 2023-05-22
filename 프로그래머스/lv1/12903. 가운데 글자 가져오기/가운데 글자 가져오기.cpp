#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if(s.length()%2 == 0) // 짝수
    {
        int idx = (s.length()/2) -1;
        answer = s.substr(idx,2);
        cout << answer;
    }
    else
    {
        int idx = (s.length()/2);
        answer = s[idx];
        cout << answer;
    }
    return answer;
}