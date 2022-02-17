class Solution {
    public int solution(String word) {
        int answer = 0;
        String str = "AEIOU";
        int[] num = {781, 156, 31, 6, 1};
        int idx;
        answer = word.length();
        for(int i=0;i<word.length();i++)
        {
            idx = str.indexOf(word.charAt(i));
            answer+=idx*num[i];
        }
        return answer;
    }
}
