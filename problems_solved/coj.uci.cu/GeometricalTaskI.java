/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1483
	Name: Geometrical Task I
	Number: 1483
	Date: 07/10/2013
*/

import java.util.Scanner;

public class GeometricalTaskI {

	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		String shape = stdin.next();
		if (shape.equals("rectangle")) {
			int aux1 = stdin.nextInt();
			int aux2 = stdin.nextInt();
			System.out.println(aux1 * aux2);
		} else {
			int aux = stdin.nextInt();
			System.out.println(aux * aux);
		}
		stdin.close();
	}
}
