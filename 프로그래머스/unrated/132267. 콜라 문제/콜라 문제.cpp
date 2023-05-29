#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b, int n) {
    
    int answer=0;
    vector<int> cola;
    
    while(n >= a)
    {
        int share = n/a;
        n = n-(a*share)+(b*share);
        cola.push_back(b*share);
    }
   
    for(int i:cola)
        answer+=i;
    
    return answer;
}