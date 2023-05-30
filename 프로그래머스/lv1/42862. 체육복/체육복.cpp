#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    
    // 정렬
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
        
    // 여벌옷이 있는 학생이 도난당했을 경우.
    for(int i=0; i<lost.size(); ++i)
    {
        auto iter = find(reserve.begin(), reserve.end(), lost[i]);
        
        if(iter != reserve.end())
        {
            answer++;
            lost.erase(lost.begin()+i);
            reserve.erase(iter);
            i--;
        }
    }
    
    while(lost.size())
    {
        if(!reserve.size()) break;
        
        int volunteer = reserve.front();
        int target = lost.front();

        if(lost.front()-1 == volunteer || lost.front()+1 == volunteer)
        {
            answer++;
            reserve.erase(reserve.begin());
            lost.erase(lost.begin());
        }
        else
        {
           if(lost.front() < reserve.front())
                lost.erase(lost.begin());
            else
                reserve.erase(reserve.begin());
        }
  
    }
       

    return answer;
}