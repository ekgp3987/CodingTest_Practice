#include <bits/stdc++.h>

using namespace std;

int goal =0; 
int cnt = 0;
void dfs(vector<int>& numbers,int idx, int now)
{
    if(idx >= numbers.size())
    {
        if(now == goal) cnt++;
        return;
    }

    dfs(numbers,idx+1,now-numbers[idx] );
    dfs(numbers,idx+1,now+numbers[idx] );
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    goal = target;

    dfs(numbers,0, 0);

    return cnt;
}