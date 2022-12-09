/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2555
	Name: Escaping from Escaping
	Number: 2555
	Date: 24/10/2013
*/

import java.util.HashSet;
import java.util.Scanner;

//Escaping from escaping
//Problem code: TAP2013E
//Accepted

public class EscapingFromEscaping {

	static int potencia (int a, int x) {
		int aux = 1;
		for (int i=0; i<x; i++) {
			aux *= a;
		}
		return aux;
	}
	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		
		String input;
		HashSet<String> digitos;
		
		input = stdin.next();
		int indice = 0;
		do {
			digitos = new HashSet<String>();
			indice++;
			for (int j=0; j+indice<=input.length(); j++) {
				digitos.add(input.substring(j,j+indice));
			}
		} while (digitos.size() == potencia(2, indice));
		
		System.out.println(indice);
			
		stdin.close();
	}
}
