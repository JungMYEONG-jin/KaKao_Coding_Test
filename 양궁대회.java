import java.util.Arrays;

class Solution {
     static int[] result = new int[11];
     static int[] lion = new int[11];
     static int maxValue = 0;

    public int[] solution(int n, int[] info) {
       dfs(0, n, lion, info);
       return maxValue==0?new int[]{-1}:result;
    }

    public void dfs(int idx, int remain, int[] lion, int[] apeach) {
        if(idx==11 || remain==0)
        {
            lion[10]+=remain;
            get_score(lion, apeach);
            lion[10]-=remain;
            return;
        }
        
        if(remain>apeach[idx])
        {
            lion[idx]+=apeach[idx]+1;
            dfs(idx+1, remain-apeach[idx]-1, lion, apeach);
            lion[idx]-=(apeach[idx]+1);
            
        }
        dfs(idx+1, remain, lion, apeach);


    }
    
    public boolean is_sorted(int[] lion)
    {
        for(int i=10;i>=0;i--)
        {
            if(lion[i]>result[i])
                return true;
            else if(lion[i]<result[i])
                return false;
        }
        return false;
    }
    
    public void get_score(int[] lion, int[] apeach)
    {
        int score = 0;
        for(int i=0;i<11;i++)
        {
            if(lion[i]==0 && apeach[i]==0)
                continue;
            if(lion[i]>apeach[i])
                score+=10-i;
            else
                score+=i-10;
        }
        
        if(score>0 && score>=maxValue)
        {
            if(score==maxValue && !is_sorted(lion))
                return;
            maxValue = score;
            for(int i=0;i<11;i++)
                result[i] = lion[i];
        }
    }
}
