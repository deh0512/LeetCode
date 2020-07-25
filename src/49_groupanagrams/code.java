class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        return Arrays.asList(strs)
            .stream()
            .collect(Collectors.groupingBy(str -> orderLetters(str)))
            .values()
            .stream()
            .collect(Collectors.toList());
    }
    
    private String orderLetters(String input) {
        return input
            .chars()
            .sorted()
            .collect(StringBuilder::new, StringBuilder::append, StringBuilder::append)
            .toString();
    }
}

