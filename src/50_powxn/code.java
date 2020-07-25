class Solution {
    public double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        if (n == 1) {
            return x;
        }
        if (n > 0) {
            return powFaster(x, 1, (long)n).x;
        }
        return 1.0 / powFaster(x, 1, -(long)n).x;
    }
    
    private static class PowData {
        long n;
        double x;
        
        PowData(long n, double x) {
            this.n = n;
            this.x = x;
        }
    }
    
    private PowData powFaster(double x, long e, long n) {
        double answer = 1.0;
        if (e <= n / 2) {
            PowData output = powFaster(x * x, e * 2, n);
            answer = output.x;
            n = output.n;
        }
        if (e <= n) {
            answer *= x;
            n -= e;
        }
        return new PowData(n, answer);
    }
}

