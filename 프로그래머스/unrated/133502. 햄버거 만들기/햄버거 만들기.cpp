
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;

    vector<int> ingredients;
    
    for(int i=0; i<ingredient.size(); i++)
    {
        ingredients.push_back(ingredient[i]);
        
        if(ingredients.size() >= 4 
           && ingredients[ingredients.size()-1] == 1
           && ingredients[ingredients.size()-2] == 3
           && ingredients[ingredients.size()-3] == 2  
           && ingredients[ingredients.size()-4] == 1
           )
        {
            answer++; 
            ingredients.pop_back(); // 1
            ingredients.pop_back(); // 3 
            ingredients.pop_back(); // 2
            ingredients.pop_back(); // 1
        }
    
    }
    return answer;
}