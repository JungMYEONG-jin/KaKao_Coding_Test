import java.util.Stack;

public class Solution {

    public static Stack<Character> res = new Stack<>();
    public static boolean check(String s)
    {
        int cnt = 0;
        int len = s.length();
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i) == '{' || s.charAt(i) == '[' || s.charAt(i) == '(')
                res.push(s.charAt(i));
            else
            {
                if(res.isEmpty()) // 비었다면 진행할 이유 없음.
                    return false;

                char op = s.charAt(i);

                if(op==']')
                {
                    char op2 = res.pop();

                    if(op2=='[')
                        cnt++;
                    else
                        return false;
                }else if(op=='}')
                {
                    char op2 = res.pop();
                    if(op2=='{')
                        cnt++;
                    else
                        return false;
                }else if(op==')')
                {
                    char op2 = res.pop();
                    if(op2=='(')
                        cnt++;
                    else
                        return false;
                }
            }
        }
        return 2*cnt==len;
        
    }
    public static int solution(String s) {
        int answer = 0;
        for(int i=0;i<s.length();i++)
        {
            String temp = s.substring(i)+s.substring(0,i);
            if(check(temp))
                answer++;
        }
        return answer;
    }
    


}
