/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1106
	Name: All in All
	Number: 1106
	Date: 31/10/2013
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Auxiliar {
	
	public static void main (String[] args) throws IOException {
		BufferedReader stdin = new BufferedReader
				(new InputStreamReader(System.in));

		int n = Integer.parseInt(stdin.readLine());
		int impar = 0;
		int par = 0;
		for (int i=0; i<n/2; i++) {
			impar += Integer.parseInt(stdin.readLine());
			par += Integer.parseInt(stdin.readLine());
		}
		
		if (impar > par) {
			System.out.println(impar+" "+par);
		} else {
			System.out.println(par+" "+impar);
		}
	}
}
