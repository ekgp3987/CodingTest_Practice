#include <string>
#include <vector>

using namespace std;

vector<string> strNum = {"zero", "one", "two","three","four","five","six","seven","eight","nine"};

int solution(string s) {
    
    string answer;
    
    for(int i=0; i<s.size(); ++i)
    {
        // 문자열이 숫자인경우
        if('0' <= s[i] && s[i] <= '9')
            answer +=s[i];
        else
        {
            for(int j=0; j<strNum.size(); ++j)
            {
                if(s.substr(i,strNum[j].size()) == strNum[j])
                {
                    answer += to_string(j);
                    i += strNum[j].size()-1;
                    break;
                }
            
                
            }
        }
            
    }
    
    return stoi(answer);
}