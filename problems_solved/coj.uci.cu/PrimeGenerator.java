/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1136
	Name: Prime Generator
	Number: 1136
	Date: 05/10/2013
*/

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	public static void main (String[] args) {
				
		Scanner stdin = new Scanner(System.in);
		int t = stdin.nextInt();
		
		boolean[] daux = new boolean[32001]; //raiz cuadrada de mil millones + 1
		ArrayList<Integer> d = new ArrayList<Integer>();
		
		for (int n=3; n<=179; n+=2) { //178 raiz cuadrada de 31622
			if (!daux[n]) {
				for (int p=n*3; p<=32000; p+=n*2) {
					daux[p] = true;
				}
			}
		}
		for (int i=3; i<32000; i+=2){
			if (!daux[i]) d.add(i);
		}
		
		
		for (int i=0; i<t; i++) {
			
			int originalBegin = stdin.nextInt();
			int begin = originalBegin;
			
			if (originalBegin % 2 == 0) //guarda el ingreso original, pero si es par lo incrementa
				begin = originalBegin + 1;
			if (begin == 1) //si el ingreso original era 1, lo pasa a 3
				begin = 3;

			int end = stdin.nextInt();
			
			int dif = end - begin;
			
			int sqrt = (int) Math.sqrt(end) + 1;
			
			boolean[] primo = new boolean[dif+1];
			
			int ind = 0;
			int act;
			while (d.get(ind) <= sqrt) {
				act = d.get(ind);
				if ((begin%act == 0) && (begin != act)) {
					for (int l=begin; l<=end; l+=act) {
						primo[l - begin] = true;
					}
				} else {
					if (begin < act) {
						for (int l=(begin+(act-(begin%act)+act)); l<=end; l+=act) {
							primo[l - begin] = true;
						}
					} else {
						for (int l=(begin+(act-(begin%act))); l<=end; l+=act) {
							primo[l - begin] = true;
						}
					}
					
				}
				ind++;
			}

			if ((originalBegin == 1) || (originalBegin == 2)) {
				System.out.println("2");
			} 
			for (int m=begin; m<=end; m+=2) {
				if (!primo[m-begin]) {
					System.out.println(m);
				}
			}
			System.out.println();
		}
		
		stdin.close();
	}
}
