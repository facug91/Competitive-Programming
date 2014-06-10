/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1003
	Name: General Election
	Number: 1003
*/

import java.util.Scanner;

public class GeneralElection {

	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		int t = stdin.nextInt();
		int n, m;
		int max, winner;
		int[] votes;
		
		for (int i=1; i<=t; i++) {
			n = stdin.nextInt();
			m = stdin.nextInt();
			votes = new int[n];
			
			for (int j=0; j<m; j++) {
				for (int k=0; k<n; k++) {
					votes[k] += stdin.nextInt();
				}
			}
			
			max = -1;
			winner = -1;
			for (int k=0; k<n; k++) {
				if (votes[k] > max) {
					max = votes[k];
					winner = k;
				}
			}
			
			System.out.println(winner+1);
		}
		stdin.close();
	}
}
