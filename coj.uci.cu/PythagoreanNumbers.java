/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1099
	Name: Pythagorean Numbers
	Number: 1099
	Date: 07/10/2013
*/

import java.util.Scanner;

public class PythagoreanNumbers {

	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		int a, b, c;
		
		a = stdin.nextInt();
		while (a != 0) {
			b = stdin.nextInt();
			c = stdin.nextInt();
			a *= a;
			b *= b;
			c *= c;
			
			if ((a+b == c) || (b+c == a) || (a+c == b)) {
				System.out.println("right");
			} else {
				System.out.println("wrong");
			}
			
			a = stdin.nextInt();
		}
		stdin.close();
	}
}
