#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int max = nums.size()/2;
    sort(nums.begin(), nums.end());
    vector<int>::iterator iter = unique(nums.begin(), nums.end());
    nums.erase(iter, nums.end());
    
    if(max >= nums.size())
        return nums.size();
    else 
        return max;
}