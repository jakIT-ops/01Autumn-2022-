import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class L04_Palindrome_Partitioning {
    public static List<List<String>> partition(String s){
        List<List<String>> rt = new ArrayList<>();

        if("".equals(s)){
            return rt;
        }

        if(s.length() == 1) {
            rt.add(Arrays.asList(s));
            return rt;
        }

        for (int i = 0; i < s.length(); i++){

            String x = s.substring(0, i + 1);
            List<List<String>> sub = new ArrayList<List<String>>();

            if (isPal(x)) {
                sub = partition(s.substring(i + 1));

                if (sub.isEmpty()) {
                    rt.add(Arrays.asList(x));
                } else {
                    for (List<String> l : sub) {
                        List<String> _l = new ArrayList<String>();
                        _l.add(x);
                        _l.addAll(l);
                        rt.add(_l);
                    }
                }
            }
        }
        return rt;
    }

    static boolean isPal(String s) {
        int st = 0, ed = s.length() - 1;

        while (st < ed) {
            if (s.charAt(st++) != s.charAt(ed--)) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 5, 2};
        int[] nums2 = {1, 5, 233, 7};

        System.out.println(partition("aab"));
        System.out.println(partition("aaabbbccccdeda"));
    }

}

