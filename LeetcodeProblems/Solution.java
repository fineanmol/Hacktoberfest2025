class Solution {
    public int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            if (isSymmetric(i)) {
                count++;
            }
        }
        return count;
    }

    private static boolean isSymmetric(int n) {
        String str = String.valueOf(n);
        int nDigits = str.length();
        if (nDigits % 2 == 1) {
            return false;
        }
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < nDigits / 2; i++) {
            sum1 += str.charAt(i) - '0';
            sum2 += str.charAt(nDigits - i - 1) - '0';
        }
        return sum1 == sum2;
    }
}
