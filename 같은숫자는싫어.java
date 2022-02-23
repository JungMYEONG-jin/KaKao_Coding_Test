import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        int[] answer = {};
            // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
            int prev = -1;
            List<Integer> res = new ArrayList<>();
            for(int i=0, len = arr.length;i<len;i++)
            {
                if(prev!=arr[i])
                {
                    res.add(arr[i]);
                    prev = arr[i];
                }

            }
            answer = res.stream().mapToInt(i->i).toArray();

            return answer;
    }
}
