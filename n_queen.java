class Solution {
    
    public static int[] board = new int[13];
    public static int ans;
     
    public int solution(int n) {
        int answer = 0;
        n_queen(0,n);
        answer = ans;
        return answer;
    }
    
    public static boolean promising(int idx)
    {
        boolean flag = true;
        for(int i=0;i<idx;i++)
        {
            if(board[i]==board[idx] || Math.abs(board[i]-board[idx])==(idx-i))
            {
                flag = false;
                break;
            }
        }
        
        return flag;
    }
    
    public static void n_queen(int idx, int n)
    {
        if(idx==n)
        {
            ans++;
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            board[idx] = i;
            if(promising(idx))
                n_queen(idx+1,n);
        }
    }
    
}
