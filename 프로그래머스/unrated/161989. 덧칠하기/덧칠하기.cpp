#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int paint=0;
    int roller=0;
    
    for(int i=0; i<section.size(); ++i)
    {
        // 구역 번호가 낮은곳부터 페인트칠을 한다.
        // 현재 section[i]벽이 페인트칠이 되지 않았을 경우, 롤러 1회 사용
        if(section[i] > paint)
        {
            roller++;
            
            // 롤러 1회 사용시, 페인트칠은 m길이만큼 칠해진다. 
            // m이 4일 경우,
            // 해당벽(section[i]), 2번째, 3번째, 4번째 는 section[i]+m-1이다.
            paint = section[i]+m-1;
        }        
    }
    
    
    return roller;
}