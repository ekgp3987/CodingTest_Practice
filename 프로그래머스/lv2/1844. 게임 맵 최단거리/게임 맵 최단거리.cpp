#include <bits/stdc++.h>

using namespace std;

// 방향 정의
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int solution(vector<vector<int> > maps)
{
    int n = maps.size();    
    int m = maps[0].size(); 
    
    int visit[101][101] ={};
    int count = 1;
    
    queue<pair<int,int>> que;
    que.push({0,0}); // 시작점
    
    
    while(!que.empty()) // 큐 빌때까지 반복
    {
        int x = que.front().first;
        int y = que.front().second;
        
        if(x == n-1 && y == m-1) return maps[x][y];
        
        que.pop();
        
        for(int i =0; i<4;i++)
        {
            int NextX = x+dx[i];
            int NextY = y+dy[i];
            
            // 게임 맵을 벗어나는 경우 무시
            if(NextX < 0 || NextX >= n|| NextY < 0 || NextY >= m) 
                continue;
            // 벽인 경우 무시, 방문한 경우 무시
            if(maps[NextX][NextY] == 0 || visit[NextX][NextY] )
                continue;
            
            // 길
            if(maps[NextX][NextY] == 1)
            {
                count++;
                maps[NextX][NextY] = maps[x][y] + 1;
                que.push({NextX, NextY});
                visit[NextX][NextY] = 1;
                
            }
        }
        
    }
    return -1;
}