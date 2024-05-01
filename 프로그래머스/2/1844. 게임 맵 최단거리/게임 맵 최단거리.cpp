#include <bits/stdc++.h>

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int visited[102][102];

using namespace std;
int solution(vector<vector<int> > maps)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<int,int>> q;
    q.push({0,0}); // start point
   
    while(!q.empty())
    {
       auto cur = q.front(); q.pop();
        
        if(cur.first == n-1 && cur.second == m-1) 
            return maps[cur.first][cur.second];
        
        for(int dir=0; dir<4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second+ dy[dir];
            
            if(nx <0 || nx > n-1 || ny <0 || ny >m-1) continue;
            if(visited[nx][ny] || !maps[nx][ny]) continue;
            
            maps[nx][ny] = maps[cur.first][cur.second] +1;
            visited[nx][ny]  = 1;
            q.push({nx,ny});
        } 
    }
    
    return -1;
}