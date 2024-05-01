#include <bits/stdc++.h>

using namespace std;

int visited[202];

void dfs(int cur_com, int n, vector<vector<int>> & computers)
{
    visited[cur_com] = 1;
    
    for(int i=0; i<n; ++i)
    {
        if(!visited[i] && computers[cur_com][i])
        {   
            dfs(i, n, computers);
        }
         
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int answer = 0;
    
    for(int i=0; i<n; ++i)
    {
        if(!visited[i])
        {
            dfs(i, n, computers);
            answer++;
        }
        
    }   
    return answer;
}