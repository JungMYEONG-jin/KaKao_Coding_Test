#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = -1;
    
    int dp[501][501]={0};
    
    dp[0][0] = triangle[0][0];
    int len = triangle.size();
    for(int i=1;i<len;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0)
                dp[i][j] = dp[i-1][j]+triangle[i][j];
            else if(j==i-1)
                dp[i][j] = dp[i-1][j-1]+triangle[i][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1])+triangle[i][j];
        }
    }
    
    
    for(int i=0;i<len;i++)
    {
        answer = max(answer, dp[len-1][i]);
    }
    
    
    
    return answer;
}
