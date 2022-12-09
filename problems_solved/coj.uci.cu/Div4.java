/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1306
	Name: Div 4
	Number: 1306
	Date: 18/10/2013
*/

import java.util.Scanner;

public class Main {
	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		
		int t = stdin.nextInt();
		String input;
		int n;
		for (int i=0; i<t; i++) {
			input = stdin.next();
			if (input.length() < 2) {
				n = Integer.parseInt(input.substring(input.length()-1));
			} else {
				n = Integer.parseInt(input.substring(input.length()-2));
			}
			
			if (n % 4 == 0) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
		}
		
		stdin.close();
	}
}
