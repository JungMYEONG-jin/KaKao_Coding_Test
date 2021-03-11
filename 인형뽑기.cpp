#include <string>
#include <vector>
#include <stack>
#include <iostream>


using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> res;
    
    int len = board.size();
    vector<vector<int>> board2(len);
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(board[j][i]!=0)
                board2[i].push_back(board[j][i]);
        }
        
    }
     
    
    for(auto i : moves)
    {
        

          bool same = false;
      if(!board2[i-1].empty())
      {
          
          while(!res.empty() && res.top()==board2[i-1][0])
          {
              answer+=2;
              res.pop();
              same=true;
          }
          
          if(!same)
              res.push(board2[i-1][0]);
          board2[i-1].erase(board2[i-1].begin());
          
          
      }
    
    
    }
    
    
    
    return answer;
}
