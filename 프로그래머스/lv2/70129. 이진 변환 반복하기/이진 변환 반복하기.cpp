#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int Count0 = 0; // 제거한 0의 개수
    int CountTurn = 0; // 이진 변환 회차

    while(true)
    {
        if(s.size() == 1)
            break; // 종료
        
        CountTurn++;
        
        int StartsSize = s.size();
        
        // 0 제거
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        int EndsSize = s.size();
    
        // 제거한 0의 개수
        Count0 += StartsSize - EndsSize;
        
        string binary;
    
        // EndsSize 이진변환
        while(EndsSize >= 0)
        {
            
            if(EndsSize / 2 > 0)
            {   
                if(EndsSize % 2 == 0)
                    binary = "0" + binary;
                else 
                    binary = "1" + binary;
                
                EndsSize /= 2;
            }
            else // EndsSize/2 <= 0  
            {  
                if(EndsSize % 2 == 0)
                    binary = "0" + binary;
                else 
                    binary = "1" + binary;
                
                s = binary;
                break;
            }
           
        }
        
    }
    
    answer.push_back(CountTurn);
    answer.push_back(Count0);
   
    return answer;
}