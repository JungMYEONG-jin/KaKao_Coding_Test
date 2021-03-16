#include <string>
#include <iostream>
#include <vector>


using namespace std;




int solution(string dirs) {
    int answer = 0;

    int visited[11][11][11][11];
    // 1 ud      2 rl
    int up_down=5;
    int left_right=5;
    for(auto i : dirs)
    {
     if(i=='U')
     {
         if(up_down+1<11)
         {
         if(visited[up_down][left_right][up_down+1][left_right]!=1)
         {
             visited[up_down][left_right][up_down+1][left_right]=1;
             visited[up_down+1][left_right][up_down][left_right]=1;
             answer++;
         }
         up_down++;
         }
     }else if(i=='D')
     {
         if(up_down-1>=0)
         {
            if(visited[up_down][left_right][up_down-1][left_right]!=1)
            {
                 visited[up_down][left_right][up_down-1][left_right]=1;
                visited[up_down-1][left_right][up_down][left_right]=1;
                answer++;
            }
         up_down--;




         }
     }else if(i=='R')
     {
         if(left_right+1<11)
         {


             if(visited[up_down][left_right][up_down][left_right+1]!=1)
             {
                 visited[up_down][left_right][up_down][left_right+1] = 1;
                 visited[up_down][left_right+1][up_down][left_right] = 1;
                 answer++;
             }

             left_right++;

         }
     }else if(i=='L')
     {
         if(left_right-1>=0)
         {


             if(visited[up_down][left_right][up_down][left_right-1]!=1)
             {
                 visited[up_down][left_right][up_down][left_right-1] = 1;
                 visited[up_down][left_right-1][up_down][left_right] = 1;
                 answer++;
             }

             left_right--;



         }
     }






    }



    return answer;
}

