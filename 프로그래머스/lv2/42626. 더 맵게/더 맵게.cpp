#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    

    priority_queue<int, vector<int>, greater<int>> pq;
        
    for(int i=0; i<scoville.size(); ++i)
    {
       pq.push(scoville[i]);
    }
    
    while(pq.size()>1)
    {
        if(pq.top() < K)
        {
            int idx0 = pq.top();
            pq.pop();
            int idx1 = pq.top();
            pq.pop();
            
            int newScoville = idx0 + 2*idx1;
            
            pq.push(newScoville);
            answer++;
        }
        
        if(pq.top() >= K) return answer;
    }
    return -1;
}