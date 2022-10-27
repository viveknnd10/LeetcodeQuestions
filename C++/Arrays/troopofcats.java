public class troopofcats 
{
    public static int minimumCost(int arr[], int H, int X, int Y)
    {
        int cost = 0,N=arr.length();
        Arrays.sort(arr);
        int i = 0, j = N - 1;
        while (i < j)
        {
            if (arr[i] + arr[j] < H)
            {
                cost += Y;
                i++;
                j--;
            }
            else
            {
                cost += X;
                j--;
            }
        }
        if (i == j)
            cost += X;
        return Math.min(cost, N * X);
    }
}
