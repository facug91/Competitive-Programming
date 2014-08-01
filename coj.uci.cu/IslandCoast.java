/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2105
	Name: Island Coast
	Number: 2105
	Date: 28/10/2013
*/

import java.util.Scanner;

public class IslandCoast {

	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		
		int n = Integer.parseInt(stdin.next());
		int m = Integer.parseInt(stdin.next());
		String[] input = new String[n];
		int i, j;
		
		for (i=0; i<n; i++) {
			input[i] = stdin.next();
		}
		
		int total = 0;
		
		//primera fila
		if (input[0].charAt(0) == '+') {
			if ((input[0].charAt(1) == '-') || (input[1].charAt(0) == '-')) {
				total++;
			}
		}
		for (i=1; i<m-1; i++) {
			if (input[0].charAt(i) == '+') {
				if ((input[0].charAt(i-1) == '-') || (input[0].charAt(i+1) == '-') || (input[1].charAt(i) == '-')) {
					total++;
				}
			}
		}
		if (input[0].charAt(m-1) == '+') {
			if ((input[0].charAt(m-2) == '-') || (input[1].charAt(m-1) == '-')) {
				total++;
			}
		}
		
		//medio
		for(i=1; i<n-1; i++) {
			if (input[i].charAt(0) == '+') {
				if ((input[i-1].charAt(0) == '-') || (input[i].charAt(1) == '-') || (input[i+1].charAt(0) == '-')) {
					total++;
				}
			}
			for (j=1; j<m-1; j++) {
				if (input[i].charAt(j) == '+') {
					if ((input[i].charAt(j+1) == '-') || (input[i].charAt(j-1) == '-') || (input[i+1].charAt(j) == '-') || (input[i-1].charAt(j) == '-')) {
						total++;
					}
				}
			}
			if (input[i].charAt(m-1) == '+') {
				if ((input[i-1].charAt(m-1) == '-') || (input[i].charAt(m-2) == '-') || (input[i+1].charAt(m-1) == '-')) {
					total++;
				}
			}
		}
		
		//última fila
		if (input[n-1].charAt(0) == '+') {
			if ((input[n-1].charAt(1) == '-') || (input[n-2].charAt(0) == '-')) {
				total++;
			}
		}
		for (i=1; i<m-1; i++) {
			if (input[n-1].charAt(i) == '+') {
				if ((input[n-1].charAt(i+1) == '-') || (input[n-1].charAt(i-1) == '-') || (input[n-2].charAt(i) == '-')) {
					total++;
				}
			}
		}
		if (input[n-1].charAt(m-1) == '+') {
			if ((input[n-1].charAt(m-2) == '-') || (input[n-2].charAt(m-1) == '-')) {
				total++;
			}
		}
		
		System.out.println(total);
		stdin.close();
	}
}
