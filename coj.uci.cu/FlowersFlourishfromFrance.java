/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1244
	Name: Flowers Flourish from France
	Number: 1244
	Date: 08/11/2013
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main (String[] args) throws IOException {

		BufferedReader stdin = new BufferedReader
				(new InputStreamReader(System.in));

		String input = stdin.readLine();
		String[] inputTokens;
		boolean tautograma;
		char act;
		int i;
		
		while (!input.equals("*")) {
			input = input.toLowerCase();
			inputTokens = input.split("[ ]+");
			tautograma = true;
			act = input.charAt(0);
			i = 0;
			
			while ((tautograma) && (i < inputTokens.length)) {
				if (inputTokens[i].charAt(0) != act) {
					tautograma = false;
				}
				i++;
			}
			
			if (tautograma) {
				System.out.println("Y");
			} else {
				System.out.println("N");
			}
			
			input = stdin.readLine();
		}
	}
}
