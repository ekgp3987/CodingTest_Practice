#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    int i= 1;
    
    vector<int> v(number+1);
    for(int i = 1; i <= number; i++) {
        for(int j = i ;j <= number; j+=i) {
            v[j]++;
        }
    }
    
    for(int i=1; i<= number; i++)
    {
        if(v[i] > limit) answer+= power;
        else answer+= v[i];
    }
    
    
    
    return answer;
}