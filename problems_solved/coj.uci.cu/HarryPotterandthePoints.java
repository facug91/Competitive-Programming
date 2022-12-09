/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2362
	Name: Harry Potter and the Points
	Number: 2362
	Date: 24/10/2013
*/

import java.util.ArrayList;
import java.util.Scanner;

public class Auxiliar {
	
	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		
		int m = stdin.nextInt();
		int n;
		ArrayList<Long> result = new ArrayList<Long>();
		result.add(new Long(0));
		result.add(new Long(1));
		
		for (int i=0; i<m; i++) {
			n = stdin.nextInt();
			if (result.size() >= n+1) {
				System.out.println(result.get(n));
			} else {
				for (int j=result.size(); j<=n; j++) {
					result.add(result.get(j-1)+(j-1)*4);
				}
				System.out.println(result.get(n));
			}
		}
		
		stdin.close();
	}
}
