import java.io.*;
import java.util.*;

class DiceThrow {
    /** 
	 * d dice 
	 * f with m faces
	 * s means sum
	 **/
    public static long findWays(int f, int d, int s) {
        /**
		 * the 1st index means number of dice
		 * the 2nd index means sum
	     **/	
        long[][] cnt = new long[d + 1][s + 1];

        /* Table entries for only one dice */
        for (int j = 1; j <= f && j <= s; j++) cnt[1][j] = 1;

        /**
		 * Fill rest of the entries in cnt using recursive relation
         * i: number of dice
		 * j: sum 
		 **/
        for (int i = 2; i <= d; i++) {
            for (int j = 1; j <= s; j++) {
                for (int k = 1; k < j && k <= f; k++) {
                    /**
					 * Recursice approach
					 * E.g.
					 * Sum(f=2, d=2, s=3) = Sum(2, 1, 2) + Sum(2, 1, 1)
					 **/
					cnt[i][j] = (cnt[i][j] + cnt[i - 1][j - k]) % 1000000007;
  				}
            }
        }
        return cnt[d][s];
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
