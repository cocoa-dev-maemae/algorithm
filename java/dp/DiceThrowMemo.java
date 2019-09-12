public class DiceThrowMemo {
    public static int findWays(int f, int d, int s) {
        /**
		 * the 1st index means number of dice
		 * the 2nd index means sum
	     **/	
        int[][] mem = new int[d + 1][s + 1];
        // Table entries for no dices
        // If you do not have any data, then the value must be 0, so the result is 1
        mem[0][0] = 1;
        for (int i = 1; i <= d; i++) {
            for (int j = i; j <= s; j++) {
               /** 
				* The result is obtained in two ways, pin the current dice and spending 1 of the value,
                * so we have mem[i-1][j-1] remaining combinations, to find the remaining combinations we would have to pin the values above 1 then we use mem[i][j-1] to sum all combinations that pin the remaining j-1's. 
				* But there is a way, when "j-f-1> = 0" we would be adding extra combinations, so we remove the combinations that only pin the extrapolated dice face and subtract the extrapolated combinations
				*
			    * E.g.
			    * Sum(f=2, d=2, s=3)
				* mem[1][1] = mem[1][0] + mem[0][0] = 0 + 1 = 1
				* mem[1][2] = mem[1][1] + mem[0][1] = 1 + 0 = 1
				* mem[1][3] = mem[1][2] + mem[0][2] = 1 + 0 = 1
				* mem[2][2] = mem[2][1] + mem[1][1] = 0 + 1 = 1
				* mem[2][3] = mem[2][2] + mem[1][2] = 1 + 1 = 2
				**/
                mem[i][j] = (mem[i][j - 1] + mem[i - 1][j - 1]);
                if (j - f - 1 >= 0) {
					mem[i][j] = (mem[i][j] - mem[i - 1][j - f - 1]);
                }
            }
        }
        return mem[d][s];
    }

    public static void main(String[] args) {
        System.out.println(findWays(4, 2, 1));
        System.out.println(findWays(2, 2, 3));
        System.out.println(findWays(6, 3, 8));
        System.out.println(findWays(4, 2, 5));
        System.out.println(findWays(4, 3, 5));
        System.out.println(findWays(30, 30, 500));
    }
}
