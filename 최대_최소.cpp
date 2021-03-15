#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> res;
    stringstream sstr(s);
    string temp;
    
    while(getline(sstr, temp, ' ')) // default space split
        res.push_back(stoi(temp));
    sort(res.begin(), res.end());
    answer+=to_string(res[0])+" "+to_string(res.back());
    return answer;
}
