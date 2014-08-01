/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2552
	Name: Elections
	Number: 2552
	Date: 22/10/2013
*/

import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class Elections {

	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		
		int n = stdin.nextInt();
		int[] votes = new int[n];
		int total = 0;
		
		for (int i=0; i<n; i++) {
			votes[i] = stdin.nextInt();
			total += votes[i];
		}
		
		LinkedList<Double> porcentajes = new LinkedList<Double>();
		
		for (int i=0; i<n; i++) {
			porcentajes.add((votes[i] * 100.0 / total));
		}
		
		Collections.sort(porcentajes);
		
		if ((porcentajes.getLast() >= 45.0) || ((porcentajes.getLast() >= 40.0) && (porcentajes.removeLast() - 10.0 >= porcentajes.getLast()))){
			System.out.println("1");
		} else {
			System.out.println("2");
		}
		
		stdin.close();
	}
}
