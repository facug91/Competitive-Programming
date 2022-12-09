/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2611
	Name: Football
	Number: 2611
	Date: 14/11/2014
*/

import java.util.PriorityQueue;
import java.util.Scanner;


public class F {

	public static void main (String[] args) {
		
		Scanner stdin = new Scanner(System.in);
		
		PriorityQueue<Integer> cola = new PriorityQueue<Integer>();
		
		int n = stdin.nextInt();
		int g = stdin.nextInt();
		
		int puntosTotales = 0;
		
		int s, r, dif;
		
		int i = 0;
		
		while ((i < n) && (g > 0)) {
			s = stdin.nextInt();
			r = stdin.nextInt();
			dif = s - r;
			if (dif > 0) {
				puntosTotales += 3;
			} else { 
				if (dif == 0) {
					g--;
					puntosTotales += 3;
				} else {
					cola.add(-dif);
				}
			}
			i++;
		}
		
		while ((g == 0) && (i < n)) {
			s = stdin.nextInt();
			r = stdin.nextInt();
			dif = s - r;
			if (dif > 0) {
				puntosTotales += 3;
			} else { 
				if (dif == 0) {
					puntosTotales++;
				}
			}
			i++;
		}
		
		int aux;
		while ((!cola.isEmpty()) && (g > 0)) {
			aux = cola.poll();
			g -= aux;
			g--;
			if (g >= 0) {
				puntosTotales += 3;
			} else {
				g++;
				if (g == 0) {
					puntosTotales++;
				}
			}
		}
		
		
		
		System.out.println(puntosTotales);
		
		stdin.close();
	}
}
