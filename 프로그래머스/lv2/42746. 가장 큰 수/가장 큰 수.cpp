#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b)
{
    string A = a+b;
    string B = b+a;
    
    return stoi(A)>stoi(B);
}
string solution(vector<int> numbers) 
{
    string answer = "";
    
    vector<string> str_nums;
    for(int i : numbers)
        str_nums.push_back(to_string(i));
    
    sort(str_nums.begin(),str_nums.end(),compare);
    
    for(string j : str_nums)
        answer+=j;
    
    if(answer.substr(0,1) == "0") return "0";
    
    return answer;
}