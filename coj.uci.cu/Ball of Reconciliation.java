/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2053
	Name: Ball of Reconciliation
	Number: 2053
	Date: 04/10/2013
*/

import java.util.Scanner;

public class Main {
	
	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		int n = stdin.nextInt();
		while (n != -1) {
			int cont = 0;
			for (int i=1; i<=(int) Math.sqrt(n); i++){
				if (n % i == 0) {
					cont++;
				}
			}
			
			for (int i=1; i<=(n-1)/2 ; i++) {
				for (int j=1; (n>=i*j) && (j<=i) ; j++) {
					for (int k=1; (k<=j); k++) {
						int aux = i*j+i*k+j*k;
						if (aux == n) {
							cont++;
						}
					} 
				}
			}
			
			System.out.println(cont);
			
			n = stdin.nextInt();
		}
		stdin.close();
	}
}
