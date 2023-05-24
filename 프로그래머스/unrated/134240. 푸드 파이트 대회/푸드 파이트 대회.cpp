#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    vector<string> front_player;
    vector<string> back_player;
    
    for(int i=1; i<food.size(); ++i)
    {
        for(int j=0; j<food[i]; ++j)
        { 
            if(j ==food[i]-1 && j%2 == 0)
                 continue;
            
            if(j%2 ==0)
                front_player.push_back(to_string(i));  // 반 담기
            else
                back_player.push_back(to_string(i));   // 반 담기
        }
    }
    
    // 뒷선수 리버스
    reverse(back_player.begin(),back_player.end());
    
    for(string a : front_player)
        answer += a;
    
    answer +='0'; // 중간 물 추가
    
    for(string b : back_player)
        answer +=b;
    
    return answer;
}