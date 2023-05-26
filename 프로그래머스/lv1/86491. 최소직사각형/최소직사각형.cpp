#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> sizes) {
    
    vector<int> vecMax;
    vector<int> vecMin;
    
    for(int i=0; i<sizes.size(); ++i)
    {
        vecMax.push_back(max(sizes[i][0], sizes[i][1]));
        vecMin.push_back(min(sizes[i][0], sizes[i][1]));
    }
    
    int w =0; int h=0;
    for(int i=0; i<sizes.size();++i)
    {
         w = max(w, vecMax[i]);
         h = max(h, vecMin[i]);      
    }
    return w*h;
}