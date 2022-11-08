#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    string low = "abcdefghijklmnopqrstuvwxyz";
    string up;
    for(auto ch : low){
        up+=toupper(ch);
    }
    int baseLen = low.size();
    for(auto ch : s){
        if (ch == ' ')
        {
            /* code */
            answer+=ch;
        }else if(islower(ch)){
            int idx = low.find(ch);
            idx+=n;
            answer+=low[idx%baseLen];
        }else if(isupper(ch)){
            int idx = up.find(ch);
            idx+=n;
            answer+=up[idx%baseLen];
        }
    }
    return answer;
}
