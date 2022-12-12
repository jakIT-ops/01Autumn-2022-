public class L03_Predict_The_Winner {
    public static boolean PredictTheWinner(int[] nums) {
        int n = nums.length;
        return predict(nums, 0, n-1) >= 0;
    }

    public static int predict(int[] nums, int left, int right) {
        if (left == right)
            return nums[left];
        else {
            return Math.max(nums[left] - predict(nums, left+1, right), nums[right] - predict(nums, left, right-1));
        }
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 5, 2};
        int[] nums2 = {1, 5, 233, 7};

        System.out.println(PredictTheWinner(nums1));
        System.out.println(PredictTheWinner(nums2));
    }
}
