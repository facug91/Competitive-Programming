/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2521
	Name: Zero or One
	Number: 2521
	Date: 23/10/2013
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Auxiliar {
	
	public static void main (String[] args) throws IOException{
		BufferedReader stdin = new BufferedReader
				(new InputStreamReader(System.in));
		String s;
		
		while((s = stdin.readLine()) != null){
			String[] tokens = s.split("[ ]+");
			if ((tokens[0].equals("0"))) {
				if ((tokens[1].equals("0"))) {
					if ((tokens[2].equals("0"))) {
						System.out.println("*");
					} else {
						System.out.println("C");
					}
				} else {
					if ((tokens[2].equals("0"))) {
						System.out.println("B");
					} else {
						System.out.println("A");
					}
				}
			} else {
				if ((tokens[1].equals("0"))) {
					if ((tokens[2].equals("0"))) {
						System.out.println("A");
					} else {
						System.out.println("B");
					}
				} else {
					if ((tokens[2].equals("0"))) {
						System.out.println("C");
					} else {
						System.out.println("*");
					}
				}
			}
		}
	}
}
