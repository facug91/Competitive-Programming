/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1805
	Name: Harder A+B
	Number: 1805
*/

import java.util.Scanner;

public class Auxiliar {
	
	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		
		long a = stdin.nextLong();
		long b = stdin.nextLong();
		long total = a * 2 + b * 2;
		System.out.println(total);
		
		stdin.close();
	}
}
