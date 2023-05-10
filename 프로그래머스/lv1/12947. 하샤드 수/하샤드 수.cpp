#include <string>
#include <vector>
using namespace std;

bool solution(int x) {
    
    int oriX = x;
    int sum = 0;
    
    string xNum = to_string(x); // x가 몇자리 수인지 알기위해 문자열로 전환
    int num = xNum.size();
    
    for(int i=0; i<num; ++i)
    {
        sum += x%10;
        x= x/10;
    }
    
    if(oriX % sum)
        return false;
    
    
    return true;
}