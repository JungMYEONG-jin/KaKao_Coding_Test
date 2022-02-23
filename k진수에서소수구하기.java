class Solution {
    
    public static boolean is_prime(long n)
    {
        if(n<=1)
            return false;
        if(n==2)
            return true;
        for(int i=2;i<=Math.sqrt(n);i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    
    
    public int solution(int n, int k) {
        String str="";
        int ans = 0;
       
            while(n!=0)
            {
                int rem = n%k;
                str+=String.valueOf(rem);
                n/=k;
            }
        
        char[] chars = str.toCharArray();
        char[] result = new char[chars.length];
        int len = chars.length;
        for(int i=0;i<len;i++)
        {
            result[i] = chars[len-i-1];
        }
        String temp = new String(result);
        String[] split = temp.split("0");
        for (String s : split) {
            if(!s.equals(""))
            {
                if(is_prime(Long.parseLong(s)))
                    ans++;

            }

        }
        return ans;
    }
}
