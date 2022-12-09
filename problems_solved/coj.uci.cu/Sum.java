/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1049
	Name: Sum
	Number: 1049
	Date: 07/10/2013
*/

import java.util.Scanner;

public class Auxiliar {
	
	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		long n = stdin.nextInt();
		if (n >= 0) {
			System.out.println(n = (n*(n+1))/2);
		} else {
			n = Math.abs(n);
			n = (n*(n+1))/2;
			n--;
			System.out.println("-"+String.valueOf(n));
		}
		stdin.close();
	}
}
