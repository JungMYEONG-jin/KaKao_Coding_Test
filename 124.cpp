#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string str[3] = {"4","1","2"};

     while(n){
        answer = str[(n % 3)] + answer;
        n = (n / 3) - (n % 3==0);
     }





    return answer;
}

