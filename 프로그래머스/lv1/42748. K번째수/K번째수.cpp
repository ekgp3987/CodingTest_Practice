#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    
    for(int i=0; i<commands.size(); ++i)
    {
        vector<int> before;
     
        int begin = commands[i][0];
        int end = commands[i][1];
        int pos = commands[i][2];
        
        for(int j=begin-1; j<end; ++j)
        {
            before.push_back(array[j]);
        } 
        sort(before.begin(), before.end());
        answer.push_back(before[pos-1]);
    }
    
    
    
    return answer;
}