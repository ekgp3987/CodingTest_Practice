#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    vector<string>::iterator iter = survey.begin();
    
    vector<string> RT;
    vector<string> CF;
    vector<string> JM;
    vector<string> AN;
    
    int i=0;
    for(; iter != survey.end(); ++iter)
    {
        switch((*iter)[0])
        {
            case 'R':
                {  
                    int choice = choices[i];
                    if(choice < 4) // 비동의 
                    {
                        int score = 4-choice;
                        RT.insert(RT.begin(), score, "R");
                    }
                    else
                    {
                        int score = choice-4;
                        RT.insert(RT.begin(), score, "T");
                    }
                    break;
                }
            case 'T':
                {  
                    int choice = choices[i];
                    if(choice < 4) // 비동의 
                    {
                        int score = 4-choice;
                        RT.insert(RT.begin(), score, "T");
                    }
                    else
                    {
                        int score = choice-4;
                        RT.insert(RT.begin(), score, "R");
                    }
                    break;
                }
            case 'C':
                {  
                    int choice = choices[i];
                    if(choice < 4) // 비동의 
                    {
                        int score = 4-choice;
                        CF.insert(CF.begin(), score, "C");
                    }
                    else
                    {
                        int score = choice-4;
                        CF.insert(CF.begin(), score, "F");
                    }
                    break;
                }
            case 'F':  
                {  
                    int choice = choices[i];
                    if(choice < 4) // 비동의 
                    {
                        int score = 4-choice;
                        CF.insert(CF.begin(), score, "F");
                    }
                    else
                    {
                        int score = choice-4;
                        CF.insert(CF.begin(), score, "C");
                    }
                    break;
                }
            case 'J':
                 {  
                    int choice = choices[i];
                    if(choice < 4) // 비동의 
                    {
                        int score = 4-choice;
                        JM.insert(JM.begin(), score, "J");
                    }
                    else
                    {
                        int score = choice-4;
                        JM.insert(JM.begin(), score, "M");
                    }
                    break;
                }
            case 'M':
                {  
                    int choice = choices[i];
                    if(choice < 4) // 비동의 
                    {
                        int score = 4-choice;
                        JM.insert(JM.begin(), score, "M");
                    }
                    else
                    {
                        int score = choice-4;
                        JM.insert(JM.begin(), score, "J");
                    }
                    break;
                }
            case 'A':
                {  
                    int choice = choices[i];
                    if(choice < 4) // 비동의 
                    {
                        int score = 4-choice;
                        AN.insert(AN.begin(), score, "A");
                    }
                    else
                    {
                        int score = choice-4;
                        AN.insert(AN.begin(), score, "N");
                    }
                    break;
                }
            case 'N':
                {  
                    int choice = choices[i];
                    if(choice < 4) // 비동의 
                    {
                        int score = 4-choice;
                        AN.insert(AN.begin(), score, "N");
                    }
                    else
                    {
                        int score = choice-4;
                        AN.insert(AN.begin(), score, "A");
                    }
                    break;
                }
        }
        ++i;
    }
    
   if(count(RT.begin(), RT.end(), "R") >= count(RT.begin(), RT.end(), "T"))
      answer+="R";
    else 
      answer+="T";
      
    if(count(CF.begin(), CF.end(), "C") >= count(CF.begin(), CF.end(), "F"))
      answer+="C";
    else 
      answer+="F";
       
    if(count(JM.begin(), JM.end(), "J") >= count(JM.begin(), JM.end(), "M"))
      answer+="J";
    else 
      answer+="M";
       
    if(count(AN.begin(), AN.end(), "A") >= count(AN.begin(), AN.end(), "N"))
      answer+="A";
    else 
      answer+="N";
    
    return answer;
}