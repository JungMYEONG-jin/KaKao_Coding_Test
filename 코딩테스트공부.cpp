#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define INT_MAX 2147483647

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int goalAlg = 0;
    int goalCop = 0;
    for(auto& it : problems){
        goalAlg = max(it[0], goalAlg);
        goalCop = max(it[1], goalCop);
    }

    if(alp>=goalAlg && cop>=goalCop)
        return answer;
    if(alp>=goalAlg)
        alp = goalAlg;
    if(cop>=goalCop)
        cop = goalCop;
    
    int dp[goalAlg+2][goalCop+2];
    for(int i=0;i<=goalAlg+1;i++)
        fill(dp[i], dp[i]+goalCop+2, INT_MAX);
    
    dp[alp][cop] = 0;

 for(int i=alp;i<=goalAlg;i++){
        for(int j=cop;j<=goalCop;j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
            dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);
            for(const auto& it : problems){
                // 둘다 초과
                if(i>=it[0] && j>=it[1])
                {
                if(i+it[2]>goalAlg && j+it[3]>goalCop){
                    dp[goalAlg][goalCop] = min(dp[goalAlg][goalCop], dp[i][j]+it[4]);
                }else if(i+it[2]>goalAlg){
                    dp[goalAlg][j+it[3]] = min(dp[goalAlg][j+it[3]], dp[i][j]+it[4]);
                }else if(j+it[3]>goalCop){
                    dp[i+it[2]][goalCop] = min(dp[i+it[2]][goalCop], dp[i][j]+it[4]);
                }else if(i+it[2]<=goalAlg && j+it[3]<=goalCop){
                    dp[i+it[2]][j+it[3]] = min(dp[i+it[2]][j+it[3]], dp[i][j]+it[4]);
                }
                }
            }
        }
    }
    
    return answer = dp[goalAlg][goalCop];
}
