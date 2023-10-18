#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int minRow = wallpaper.size();
    int minCol = wallpaper[0].length();
    int maxRow = 0;
    int maxCol = 0;
    for(int i=0, len = wallpaper.size() ; i<len ; i++){
        for(int j=0, vlen = wallpaper[i].length() ; j<vlen ; j++){
            if(wallpaper[i][j]=='#'){
                maxRow = max(maxRow, i+1);
                maxCol = max(maxCol, j+1);
                minRow = min(minRow, i);
                minCol = min(minCol, j);
            }
        }
    }
    answer.push_back(minRow);
    answer.push_back(minCol);
    answer.push_back(maxRow);
    answer.push_back(maxCol);
    return answer;
}
