#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> res(n, vector<int>(n));
    int goal = n;
    int num=1;
    int x=-1;
    int y=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=goal;j>0;j--)
        {
            if(i%3==0)
            {
                res[++x][y]=num;
                num++;
            }else if(i%3==1)
            {
                res[x][++y]=num;
                num++;
            }else if(i%3==2)
            {
                res[--x][--y]=num;
                num++;
            }
    
        }
        goal--;
    }
    
    
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            answer.push_back(res[i][j]);
    
    
    
    
    return answer;
}
