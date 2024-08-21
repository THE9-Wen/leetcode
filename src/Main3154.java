public class Main3154 {
    public int waysToReachStair(int k) {
        int n = 0;
        int npow = 1;
        int result = 0;
        while (true) {
            if (npow - n - 1 <= k && npow >= k) {
                result += comb(n + 1, npow - k);
            } else if (npow - n - 1 > k) {
                break;
            }
            n++;
            npow *= 2;
        }
        return result;
    }

    public int comb(int n, int k) {
        long result = 1;
        for (int i = n; i >= n - k + 1 ; i--) {
            result *= i;
            result /= n - i + 1;
        }
        return (int)result;
    }
}
