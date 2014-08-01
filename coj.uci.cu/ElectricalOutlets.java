/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2322
	Name: Electrical Outlets
	Number: 2322
	Date: 23/10/2013
*/

import java.util.Scanner;

public class Auxiliar {
	
	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		
		int n = stdin.nextInt();
		
		for (int i=0; i<n; i++) {
			int k = stdin.nextInt();
			int total;
			if (k == 1) {
				total = stdin.nextInt();
			} else {
				total = stdin.nextInt()-1;
				
				for (int j=1; j<k-1; j++){
					total += stdin.nextInt()-1;
				}
				
				total += stdin.nextInt();
			}
			
			System.out.println(total);
		}
		
		
		stdin.close();
	}
}
