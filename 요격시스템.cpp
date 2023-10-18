#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    if(targets.size() == 1)
        return 1;
    sort(targets.begin(), targets.end(), [](auto left, auto right){
        return (left[1] < right[1] );
    });
    for(const auto& target : targets){
        cout<<target[0]<<" "<<target[1]<<endl;
    }
    

    int bomb = -1;
    for(int i=0, len = targets.size() ; i<len ; i++){
        if(bomb == -1){
            bomb = targets[0][1];
            answer++;
        }
        if(targets[i][0] < bomb && bomb <= targets[i][1]){
            continue;
        }
        bomb = targets[i][1];
        answer++;
    }
    
    return answer;
}
