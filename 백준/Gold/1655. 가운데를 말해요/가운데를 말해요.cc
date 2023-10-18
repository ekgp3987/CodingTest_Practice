#include <iostream>
#include <queue>

using namespace std;

int main()
{
	 // 입출력 최적화 코드(printf scanf랑 같이 쓰면X, 싱글스레드에서만)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // 오름차순, 내림차순 우선순위 큐 생성
    // minHeap : 작은 수들의 max, maxHeap :  큰 수들의 min
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    // maxHeap.top()이 언제나 정답이다. 
    int input;

    for (int i = 0; i < N; ++i)
    {
        cin >> input;

        if (minHeap.empty() && maxHeap.empty()) // if i ==0
        {
            maxHeap.push(input);
        }
        else if (maxHeap.size() <= minHeap.size())
        {
            maxHeap.push(input);
        }
        else 
        {
            minHeap.push(input);
        }

        if ((!minHeap.empty() && !maxHeap.empty())
               && (minHeap.top() < maxHeap.top()))
        {
            // swap
            int minVal = minHeap.top();
            int maxVal = maxHeap.top();

            minHeap.pop();
            maxHeap.pop();

            maxHeap.push(minVal);
            minHeap.push(maxVal);
        }

        cout << maxHeap.top() << '\n';
    }

    return 0;
}