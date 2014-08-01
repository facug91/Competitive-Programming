/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2373
	Name: Math Table
	Number: 2373
	Date: 24/10/2013
*/

import java.util.LinkedList;
import java.util.Scanner;

public class Auxiliar {
	
	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		
		LinkedList<Double> list = new LinkedList<Double>();
		Double A = stdin.nextInt()*1.0;
		Double B = stdin.nextInt()*1.0;
		Double C = stdin.nextInt()*1.0;
		Double D = stdin.nextInt()*1.0;
		
		list.add(A);
		list.add(B);
		list.add(D);
		list.add(C);
		
		int result = 0;
		Double max = -1.0;
		Double aux;
		for (int i=0; i<4; i++) {
			aux = (list.get(0) / list.get(1)) + (list.get(3) / list.get(2));
			if (aux > max) {
				max = aux;
				result = i;
			}
			list.addFirst(list.remove(3));
		}
		
		System.out.println(result);
		
		stdin.close();
	}
}
