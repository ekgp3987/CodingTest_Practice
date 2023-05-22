#include <string>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

string intToBinaryString(int number, int numBits) {
    std::bitset<32> binary(number);
    return binary.to_string().substr(32 - numBits);
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    // 이진수 string 변환
    vector<string> arrBinary1;
    vector<string> arrBinary2;
    for(int i=0; i<n; ++i)
    {
        arrBinary1.push_back(intToBinaryString(arr1[i], n));
        arrBinary2.push_back(intToBinaryString(arr2[i], n));
    }
    
    
    // 비교
    for(int i=0; i<n; ++i)
    {
        string moneyMap ={};
        for(int j=0; j<n; ++j)
        { 
            if(arrBinary1[i][j]== '1' || arrBinary2[i][j] == '1')
                moneyMap += "#";
            else
                moneyMap += " ";
                
        }
       answer.push_back(moneyMap);
            
    }
    
    
    return answer;
}