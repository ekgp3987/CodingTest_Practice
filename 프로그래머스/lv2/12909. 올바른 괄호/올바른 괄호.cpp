#include<string>
#include <iostream>
#include <stack>


using namespace std;

stack<int> sLeft;
stack<int> sRight;

bool solution(string s)
{
    for(int i=0; i<s.size(); ++i)
    {
        if(s.substr(i,1) == "(")
            sLeft.push(i);
        else
            sRight.push(i);
    }
    if(sLeft.size() != sRight.size()) return false;
   
    while(!sLeft.empty())
    {
        if(sLeft.top() < sRight.top())
        {   
            sLeft.pop();
            sRight.pop();
        }
        else 
            return false;
    }   
    if(sRight.empty()) return true;
    else return false;
    
}