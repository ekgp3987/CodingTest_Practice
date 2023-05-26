#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int>::iterator iter = unique(arr.begin(),arr.end());
    arr.erase(iter, arr.end());

    return arr;
}