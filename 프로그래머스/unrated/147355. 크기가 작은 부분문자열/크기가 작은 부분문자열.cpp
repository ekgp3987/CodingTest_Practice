#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int n = p.length();
    
    for(int i=0; i<t.length()-n+1; ++i)
    {
        string strPart = t.substr(i,n);
        if(stoll(strPart) <= stoll(p))
            answer++;
    }
    
    return answer;
}