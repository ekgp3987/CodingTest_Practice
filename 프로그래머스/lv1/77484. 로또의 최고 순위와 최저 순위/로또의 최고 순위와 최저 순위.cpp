#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zeroCnt = 0;
    int winCnt = 0;
    
    // 0의 개수를 센다. 
    for(int i=0; i<lottos.size(); ++i)
    {
        if(lottos[i] == 0)
            zeroCnt++;
    }
    
    for(int i=0; i<lottos.size(); ++i)
    {
        for(int j=0; j<lottos.size(); ++j)
        {
            if(win_nums[i] == lottos[j])
                winCnt++;
        }
       
    }
   
    // 최고 순위
    int highRank = 7-winCnt-zeroCnt;
    int lowRank = 7-winCnt;
    
    if(highRank ==7 || highRank==0)
    {
        if(highRank == 7) highRank = 6;
        else highRank = 1;
    }
    
    if(lowRank ==7 || lowRank==0)
    {
        if(lowRank == 7) lowRank = 6;
        else lowRank = 1;
    }
    
    answer.push_back(highRank);
    answer.push_back(lowRank);
    return answer;
}