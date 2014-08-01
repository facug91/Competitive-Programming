/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2557
	Name: War
	Number: 2557
	Date: 22/10/2013
*/

import java.util.PriorityQueue;
import java.util.Scanner;

public class War {

	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		
		PriorityQueue<Integer> cola1 = new PriorityQueue<Integer>();
		PriorityQueue<Integer> cola2 = new PriorityQueue<Integer>();
		
		int s = stdin.nextInt();
		
		for (int i=0; i<s; i++) {
			cola1.add(stdin.nextInt());
		}
		for (int i=0; i<s; i++) {
			cola2.add(stdin.nextInt());
		}
			
		int total = 0;
		while (!cola2.isEmpty()) {
			if (cola1.peek() < cola2.peek()) {
				cola1.poll();
				cola2.poll();
				total++;
			} else {
				cola2.poll();
			}
		}
		System.out.println(total);
			
		stdin.close();
	}
}
