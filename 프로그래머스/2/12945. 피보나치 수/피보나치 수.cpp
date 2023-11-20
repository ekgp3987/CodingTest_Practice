#include<bits/stdc++.h>

using namespace std;
int ans[100001];

int solution(int n) {
    
    ans[0] = 0; ans[1] = 1;
    
    for(int i=2; i<=n; ++i)
    {
        ans[i]= (ans[i-2] + ans[i-1]) %1234567;
    }
    
    return ans[n];
}