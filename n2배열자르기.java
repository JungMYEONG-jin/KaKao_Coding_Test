class Solution {
    public int[] solution(int n, long left, long right) {
        int cap = (int)(right-left+1);
        int[] answer = new int[cap];
        int idx = 0;
        while(left<=right)
        {
            answer[idx++] = Math.max((int)Math.floor(left/n), (int)(left++%n))+1;
        }
        return answer;
    }
}
