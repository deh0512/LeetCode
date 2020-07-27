class Solution {
    public void rotate(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            return;
        }
        int temp;
        for (int boundary = 0; boundary < matrix.length / 2; ++boundary) {
            int r1 = boundary;
            int r2 = matrix.length - boundary - 1;
            int c1 = r1;
            int c2 = r2;
            for (int mod = 0; mod < matrix.length - (2 * boundary) - 1; ++mod) {
                temp = matrix[r1][c1 + mod];
                matrix[r1][c1 + mod] = matrix[r2 - mod][c1];
                matrix[r2 - mod][c1] = matrix[r2][c2 - mod];
                matrix[r2][c2 - mod] = matrix[r1 + mod][c2];
                matrix[r1 + mod][c2] = temp;
            }
        }
    }
}

