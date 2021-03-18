#include <string>
#include <vector>
#include <functional>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;


    function<void(int, int, int, int)> hanoi = [&hanoi, &answer](int n, int start, int to, int from){

      if(n==1)
      {
          answer.push_back({start, to});
          return ;
      }
        hanoi(n-1, start, from, to);
        answer.push_back({start, to});
        hanoi(n-1, from, to, start);
    };


    hanoi(n, 1, 3, 2);

    return answer;
}
