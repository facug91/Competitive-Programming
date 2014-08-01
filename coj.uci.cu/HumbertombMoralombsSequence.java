/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2428
	Name: Humbertomb Moralomb’s Sequence
	Number: 2428
	Date: 24/10/2013
*/

import java.util.Scanner;

public class HumbertombMoralombsSequence {

	static int square (int n) {
		return n * n;
	}
	public static void main (String[] args) {
		int[] hm = new int[44724];
		
		for (int i=0; i<44724; i++) {
			hm[i] = square(i);
		}
		
		
		Scanner stdin = new Scanner(System.in);
		
		int n = stdin.nextInt();
		
		while (n != 0) {
			int aux = (int) Math.sqrt(n);
			if (hm[aux] == n) {
				System.out.println(aux);
			} else if (hm[aux] < n) {
				System.out.println(aux+1);
			}
			
			n = stdin.nextInt();
		}
		
		stdin.close();
	}
}
