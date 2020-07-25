class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Set<List<Integer>> output = new HashSet<>();
        permute(output, new LinkedList<Integer>(), IntStream.of(nums).boxed().collect(Collectors.toList()));
        return output.stream().collect(Collectors.toList());
    }
    
    private void permute(Set<List<Integer>> output, List<Integer> current, List<Integer> unused) {
        if (unused.isEmpty()) {
            output.add(current.stream().collect(Collectors.toList()));
        } else {
            for (int i = 0; i < unused.size(); ++i) {
                Integer x = unused.remove(i);
                current.add(x);
                permute(output, current, unused);
                unused.add(i, x);
                current.remove(current.size() - 1);
            }
        }
    }
}

