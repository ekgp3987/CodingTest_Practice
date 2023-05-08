#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string suback = "수박";
    
    int repeat = n/2;
    for(int i=0; i<repeat; ++i)
    {
        answer +=suback;
    }
    if(n%2 == 1) //홀수
         answer += "수";
    return answer;
}