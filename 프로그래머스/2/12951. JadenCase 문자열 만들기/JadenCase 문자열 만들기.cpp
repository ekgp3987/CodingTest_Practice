#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if('a' <= s[0] && s[0] <='z')
            s[0] = s[0]-32;
    
    for(int i=1; i<s.length(); ++i)
    {
        if('A' <= s[i] && s[i] <='Z') s[i] += 32;
    }
    
    for(int i=1; i<s.length(); ++i)
    {
        if(s[i] == ' ')
        { 
            if(s[i+1] == ' ') continue;
            
            if(!('0' <= s[i+1] && s[i+1]  <='9') &&
            !('A' <= s[i+1] && s[i+1]  <= 'Z'))
            {
                s[i+1]  -=32;
            }
        }
    }
    return s;
}