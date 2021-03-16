#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;





vector<int> solution(string s) {
    vector<int> answer;
    int number=0;

    auto to_bin = [](string& s){
        int number =count(s.begin(), s.end(), '0');
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        return number;
    };


    auto make_bin = [](int n){
        string temp="";
        while(n)
        {
            temp+=to_string(n%2);
            n/=2;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    };


    cout<<s<<endl;
    int cnt=0;
    while(true)
    {
        number+=to_bin(s);
        cnt++;

        s = make_bin(s.size());

        if(s=="1")
            break;
    }

    answer.push_back(cnt);
    answer.push_back(number);

    return answer;
}

