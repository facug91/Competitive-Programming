/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1026
	Name: Longest Run on a Snowboard
	Number: 1026
	Date: 05/10/2013
*/

import java.util.Scanner;

public class Main15 {

	static int[][] heights;
	static boolean[][] states;
	static int[][] longestRun;
	
	static void initialize (int r, int c) {
		heights = new int[r+2][c+2];
		states = new boolean[r+2][c+2];
		longestRun = new int[r+2][c+2];
		
		for (int i=0; i<r+2; i++) {
			heights[i][0] = 101;
			heights[i][c+1] = 101;
			states[i][0] = true;
			states[i][c+1] = true;
			longestRun[i][0] = -1;
			longestRun[i][c+1] = -1;
		}
		for (int j=0; j<c+2; j++) {
			heights[0][j] = 101;
			heights[r+1][j] = 101;
			states[0][j] = true;
			states[r+1][j] = true;
			longestRun[0][j] = -1;
			longestRun[r+1][j] = -1;
		}
	}
	
	static void loadHeights (Scanner stdin, int r, int c) {
		for (int i=1; i<r+1; i++) {
			for (int j=1; j<c+1; j++) {
				heights[i][j] = stdin.nextInt();
			}
		}
	}
	
	static int clr (int i, int j) {
		if (longestRun[i][j] == 0) {
			states[i][j] = true;
			int max = 0;
			if (!states[i-1][j]) {
				if (heights[i-1][j] > heights[i][j]) {
					max = Math.max(max, clr(i-1, j));
				}
			}
			if (!states[i+1][j]) {
				if (heights[i+1][j] > heights[i][j]) {
					max = Math.max(max, clr(i+1, j));
				}
			}
			if (!states[i][j-1]) {
				if (heights[i][j-1] > heights[i][j]) {
					max = Math.max(max, clr(i, j-1));
				}
			}
			if (!states[i][j+1]) {
				if (heights[i][j+1] > heights[i][j]) {
					max = Math.max(max, clr(i, j+1));
				}
			}
			longestRun[i][j] = max+1;
			states[i][j] = false;
		}
		
		
		return longestRun[i][j]; //
	}
	static int calculateLongestRun (int r, int c) {
		int max = 0;
		for (int i=1; i<r+1; i++) {
			for (int j=1; j<c+1; j++) {
				if (longestRun[i][j] == 0) {
					int aux = clr(i,j); //calcula el camino más largo desde esta altura
					max = Math.max(aux, max);
				}
			}
		}
		
		return max;
	}
	
	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		
		int n = stdin.nextInt();
		for (int i=0; i<n; i++) {
			int theLongest = 0;
			String name = stdin.next();
			
			int rows = stdin.nextInt();
			int columns = stdin.nextInt();
			
			heights = new int[rows][columns];
			
			initialize(rows, columns); //Inicializa todas las matrices
			
			loadHeights(stdin, rows, columns);
			
			theLongest = calculateLongestRun(rows, columns);
			
			System.out.println(name+": "+theLongest);
			
			
		}
		stdin.close();
	}

}
