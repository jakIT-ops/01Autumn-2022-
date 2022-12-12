import java.util.Arrays;
import java.util.Comparator;

public class L07_Longest_String_Chain {
    private static boolean isPred(String a, String b) {
        int diff = 0;
        if(a.length() != b.length()-1) return false;
        for(int i = 0, j = 0; i < a.length() && j < b.length() ;){
            if(a.charAt(i) == b.charAt(j)){
                i++;
                j++;
            } else {
                if(diff>0) return false;
                diff++;
                j++;
            }
        }
        return true;
    }

    public static int longestStrChain(String[] words) {
        int[] dp = new int[words.length];
        Integer max = Integer.MIN_VALUE;
        for(int i = 0; i<dp.length; i++) dp[i]=1;
        Arrays.sort(words, new Comparator<String>(){
            public int compare(String s1, String s2){
                return s1.length() - s2.length();
            }
        });
        for(int j = 1; j < words.length; j++){
            for(int i = 0; i < j; i++){
                if(isPred(words[i], words[j])) {
                    dp[j] = Math.max(dp[j], 1+dp[i]);
                    max = Math.max(max, dp[j]);
                }
            }
        }
//        System.out.println(Arrays.toString(dp));
        return Math.max(1, max);
    }

    public static void main(String argv[]){

        String words[] = {"a","b","ba","bca","bda","bdca"};
        String words1[] = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
        String words2[] = {"abcd","dbqca"};
        System.out.println(longestStrChain(words));
        System.out.println(longestStrChain(words1));
        System.out.println(longestStrChain(words2));
    }
}
