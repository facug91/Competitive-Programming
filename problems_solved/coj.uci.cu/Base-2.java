/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1384
	Name: Base -2
	Number: 1384
	Date: 16/10/2013
*/

import java.util.Scanner;

public class Base2 {

	static String convertToNegabinary(long num) {
		if (num == 0) {
			return "0";
		} else {
			String result = "";
			while (num != 0 ) {
				if ((num < 0) && (num % 2 != 0)) {
					result = String.valueOf(Math.abs(num % -2)) + result;
					num /= -2;
					num++;
				} else {
					result = String.valueOf(Math.abs(num % -2)) + result;
					num /= -2;
				}
			}
			return result;
		}
	}
	
	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		long n = stdin.nextInt();
		for (int i=1; i<=n; i++) {
			System.out.println("Case #"+i+": "+convertToNegabinary(stdin.nextLong()));
		}
		stdin.close();
	}
}
