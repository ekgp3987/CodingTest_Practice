#include <bits/stdc++.h>


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int visited[102][102];

using namespace std;
int solution(vector<vector<int> > maps)
{
    
    int n= maps.size();
    int m= maps[0].size();
    
    queue<pair<int,int>> q;
    q.push({0,0});
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        
        // goal
        if(cur.first == n-1 && cur.second == m-1) return maps[cur.first][cur.second];
        
        // 4 dir
        for(int dir=0; dir<4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            // 맵 외부, 방문여부, 벽 판별
            if(nx <0 || nx>=n || ny <0 || ny>=m) continue;
            if(visited[nx][ny] || !maps[nx][ny]) continue;
            
            // update 
            maps[nx][ny] = maps[cur.first][cur.second] +1;
            visited[nx][ny] =1;
            q.push({nx,ny});
        }
    }

    return -1;
}