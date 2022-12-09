/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1312
	Name: R2
	Number: 1312
*/

import java.util.Scanner;

public class Main {
	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		int r1 = stdin.nextInt();
		int s = stdin.nextInt();
		int result = (2 * s) - r1;
		System.out.println(result);
		stdin.close();
	}
}
