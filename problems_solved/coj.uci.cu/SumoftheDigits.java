/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2152
	Name: Sum of the Digits
	Number: 2152
	Date: 27/10/2013
*/

import java.util.Scanner;

public class Auxiliar {
	
	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);

		int t = Integer.parseInt(stdin.next());
		String input;
		int result;
		
		for (int i=0; i<t; i++) {
			result = 0;
			input = stdin.next();
			
			if (input.charAt(0) == '-') {
				for (int j=1; j<input.length(); j++) {
					result += Integer.parseInt(String.valueOf(input.charAt(j)));
				}
			} else {
				for (int j=0; j<input.length(); j++) {
					result += Integer.parseInt(String.valueOf(input.charAt(j)));
				}
			}
			
			System.out.println(result);
			
			
		}
		
		
		
		stdin.close();
	}
}
