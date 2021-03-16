#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream sstr(s);
    string temp;

    while(getline(sstr, temp, ' '))
    {
        transform(temp.begin(), temp.end(), temp.begin(),[](auto e){return tolower(e);});
        temp[0] = toupper(temp[0]);
        answer+=temp+" ";
    }
    if(s.back()!=' ')
        answer.pop_back();
    return answer;
}
