#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> nums;
    int len = s.length();
    int idx=0;
    for(int i=0; i<len; ++i)
    {
        if(s[i] == ' ')
        {
            nums.push_back(stoi(s.substr(idx, i-idx)));
            idx = i;
        }
    }
    
    // 마지막 숫자 넣기
    nums.push_back(stoi(s.substr(idx, len-idx)));
        
    int minNum = *min_element(nums.begin(), nums.end());
    int maxNum = *max_element(nums.begin(), nums.end());
    
    answer = to_string(minNum) + ' ' + to_string(maxNum);
    return answer;
}