#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    if(participant.size()==1)
        return participant[0];
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i=0; i<participant.size(); ++i)
    {
        if(participant[i]!=completion[i])
            return participant[i];
    }
    
    return answer;
}