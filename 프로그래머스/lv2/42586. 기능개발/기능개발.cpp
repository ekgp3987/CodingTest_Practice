#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
 
    while(progresses.size())
    {
        for(int j=0; j<progresses.size(); ++j)
        { 
            progresses[j] += speeds[j];
        }
       
        if(progresses.front() >= 100)
        {
            int cnt =0;
            while(!(progresses.front() < 100))
            {
                progresses.erase(progresses.begin());
                speeds.erase(speeds.begin());
                cnt++;
                
                if (!progresses.size()) break;
            }
            answer.push_back(cnt);
        }
    }    
    
    return answer;
}