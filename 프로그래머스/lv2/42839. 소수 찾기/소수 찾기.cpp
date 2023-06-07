#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(int _num)
{
    if(_num < 2 ) return false;
    
    for(int i=2; i<=sqrt(_num); ++i)
    {   
        if(_num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> vecNum;  // numbers의 각 문자 char
    vector<int>  spare;   // 소수가 될 예비군

    for(int i=0; i<numbers.size(); ++i)
    {
        vecNum.push_back(numbers[i]);
    }
    sort(vecNum.begin(), vecNum.end());
    
    // next_permutation는 다음 순열부터 반환
    do{
        string temp;
        
        for(int i=0; i<vecNum.size();++i)
        {
            temp.push_back(vecNum[i]);
            spare.push_back(stoi(temp));
        }
    }
    while(next_permutation(vecNum.begin(), vecNum.end()));
   
    // spare 중복 제거
    sort(spare.begin(), spare.end());
    auto last = unique(spare.begin(), spare.end());
    spare.erase(last, spare.end());
    
    // 소수인지 체크 
    for(int num : spare)
    {
        if(IsPrime(num))
            answer++;
    }
    
    return answer;
}