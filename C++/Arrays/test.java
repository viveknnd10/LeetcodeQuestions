class Solution {
    int[][] solution(int[] numbers) 
    {
        Arrays.sort(numbers);
        final List<List<Integer>> result = new LinkedList<>();
        int minDistance = Integer.MAX_VALUE;
        for (int i=1; i<numbers.length; i++) 
        {
            minDistance = Math.min(minDistance, numbers[i] - numbers[i-1]);
        }
        for (int i=1; i<numbers.length; i++) 
        {
            if (minDistance == numbers[i] - numbers[i - 1]) 
            {
                result.add(Arrays.asList(numbers[i-1], numbers[i]));
            }
        }
        int[][] ans = new int[result.size()][];
        for (int i = 0; i < ans.length; i++) 
        {
            ans[i] = new int[result.get(i).size()];
            for (int j = 0; j < ans[i].length; j++) 
            {
                ans[i][j] = result.get(i).get(j);
            }
        }
        return ans;
    }
}