/*
	By: facug91
	From: http://www.spoj.com/problems/ELIS/
	Name: Easy Longest Increasing Subsequence
	Number: 11110
	Date: 23/08/2014
*/

import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	
	static int n;
	static int[] a = new int[25];
	static int[] LIS = new int[25];
	
	static int lis () {
		int i, j, ans = -1;
		for (i=0; i<n; i++) {
			LIS[i] = 1;
			for (j=0; j<i; j++) {
				if ((a[j] < a[i]) && (LIS[j]+1 > LIS[i]))
					LIS[i] = LIS[j]+1;
			}
			if (ans < LIS[i])
				ans = LIS[i];
		}
		return ans;
	}
	
	public static void main (String[] args) throws IOException {
		int i, j;
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		n = in.nextInt();
		for (i=0; i<n; i++)
			a[i] = in.nextInt();
		System.out.println(lis());
	}
	
}
