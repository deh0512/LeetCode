class Solution {
    public List<Integer> grayCode(int n) {
        int twoToTheN = (int)Math.pow(2, n);
        List<Integer> xors = new LinkedList<>();
        for (int bit = twoToTheN / 2; bit > 0; bit /= 2) {
            for (int i = xors.size(); i > 0; --i) {
                xors.add(i, bit);
            }
            xors.add(0, bit);
        }
        List<Integer> output = new LinkedList<>();
        int x = 0;
        output.add(x);
        for (int i = 1; i < twoToTheN; ++i) {
            x ^= xors.get(i - 1);
            output.add(x);
        }
        return output;
    }
}

