int dp[1e5+1];
int solution(vector<int> sticker)
{
    int answer = 0;
    int len = sticker.size();
    if (len==1)
    {
        /* code */
        return sticker[0];
    }

    dp[0] = sticker[0];
    dp[1] = sticker[0];

    for(int i=2;i<len-1;i++){
        dp[i] = max(dp[i-2]+sticker[i], dp[i-1]);
    }

    answer = max(answer, dp[len-2]);

    dp[0] = 0
    dp[1] = sticker[1];
    for(int i=2;i<len;i++){
        dp[i] = max(dp[i-2]+sticker[i], dp[i-1]);
    }
    answer = max(answer, dp[len-1]);
    return answer;
}
