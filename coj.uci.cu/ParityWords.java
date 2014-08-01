/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2183
	Name: Parity Words
	Number: 2183
	Date: 27/10/2013
*/

import java.util.Scanner;

public class Auxiliar {
	
	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);

		int t = Integer.parseInt(stdin.nextLine());
		String input;
		int odd, even, maxeven, maxodd;
		
		for (int i=0; i<t; i++) {
			odd = 0;
			even = 0;
			input = stdin.nextLine();
			if (input.length() % 2 == 0) {
				maxodd = input.length()/2;
				maxeven = (input.length()/2)+1;
			} else {
				maxodd = (input.length()/2)+1;
				maxeven = (input.length()/2)+1;
			}
			
			int j = 0;
			while ((odd < maxodd) && (even < maxeven)) {
				if (((int) input.charAt(j)) % 2 == 0) {
					even++;
				} else {
					odd++;
				}
				j++;
			}
			
			if (even > odd) {
				System.out.println("Even");
			} else {
				System.out.println("Odd");
			}
			
		}
		
		
		
		stdin.close();
	}
}
