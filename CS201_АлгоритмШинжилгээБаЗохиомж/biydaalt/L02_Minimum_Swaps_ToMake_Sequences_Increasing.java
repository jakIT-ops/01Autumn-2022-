import java.util.Arrays;

public class L02_Minimum_Swaps_ToMake_Sequences_Increasing {
    public static int minSwap(int[] nums1, int[] nums2) {
        int prevNoSwap = 0;

        int prevSwap = 1;

        for(int i = 1; i < nums1.length; i++){
            boolean bothIncrease = nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i];

            boolean switchABToIncrease = nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i];

            if(bothIncrease && switchABToIncrease){ // AB could swap or not swap
                int temp = Math.min(prevNoSwap, prevSwap);

                prevSwap = temp + 1;

                prevNoSwap = temp;
            } else if(bothIncrease){ // AB does not need to swap
                prevSwap++;
            } else { // AB need to swap
                int temp = prevSwap;

                prevSwap = prevNoSwap + 1;

                prevNoSwap = temp;
            }
        }

        return Math.min(prevSwap, prevNoSwap);
    }

    /*
    * nums1 = [1, 3, 5, 4], and
    * nums2 = [1, 2, 3, 7]
    * output 1:
    * nums1 = [1, 3, 5, 7], and nums2 = [1, 2, 3, 4]
    * */
    public static void main(String[] args) {
        int[] nums1 = {1, 3, 5, 4};
        int[] nums2 = {1, 2, 3, 7};

        int[] nums3 = {0, 3, 5, 8, 9};
        int[] nums4 = {2, 1, 4, 6, 9};

        System.out.println(minSwap(nums1, nums2));
        System.out.println(minSwap(nums3, nums4));
    }
}