/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1495
	Name: Increasing Order List
	Number: 1495
	Date: 18/10/2013
*/

import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		
		int t = stdin.nextInt();
		LinkedList<Integer> list = new LinkedList<Integer>();
		for (int i=0; i<t; i++) {
			list.add(stdin.nextInt());
		}
		
		Collections.sort(list);
		
		for (Integer n: list) {
			System.out.println(n);
		}
		
		stdin.close();
	}
}
