/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1047
	Name: Visible Lattice Points
	Number: 1047
	Date: 23/10/2013
*/

import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;

//Visible Lattice Points
//Problem code: 1047
//

public class VisibleLatticePoints {

	static int gcd (int a, int b) {
		if (b == 0) {
			return a;
		} else {
			return gcd(b, a%b);
		}
	}
	static int lcm (int a, int b) {
		return ((a * b) / gcd(a, b));
	}
	
	public static void main (String[] args) {
		ArrayList<Integer> primos = new ArrayList<Integer>();
		
		//criba para factorización
		int[] factor = new int[1001];
		
		for (int i=2; i<32; i++) {
			if (factor[i] == 0) {
				primos.add(i);
				for (int j=i; j<1001; j+=i) {
					factor[j] = i;
				}
			}
		}
		for (int i=33; i<1001; i+=2) {
			if (factor[i] == 0) {
				primos.add(i);
				factor[i] = i;
			}
		}
		
		//mcm de los primos
		int[][] lcm = new int[1001][1001];
		for (int i=0; i<168; i++) {
			for (int j=i+1; j<168; j++) {
				lcm[primos.get(i)][primos.get(j)] = lcm(primos.get(i), primos.get(j));
				lcm[primos.get(j)][primos.get(i)] = lcm[primos.get(i)][primos.get(j)];
			}
		}
		
		long[] result = new long[1001];
		result[1] = 3;
		result[2] = 5;
		result[3] = 9;
		long cont;
		int aux;
		HashSet<Integer> factores; 
		for (int i=4; i<1001; i++) {
			factores = new HashSet<Integer>();
			aux = i;
			cont = (i-1)*2;
			while (aux != 1) {
				factores.add(factor[aux]);
				aux /= factor[aux];
			}
			if (factores.size() == 4) {
				for (int k=1; k<i; k++) {
					if (gcd(i, k) != 1) {
						cont-=2;
					}
				}
			} else {
				LinkedList<Integer> faux = new LinkedList<Integer>();
				for (Integer f: factores) {
					cont -= (i-f)/f*2;
					for (Integer fa: faux) {
						cont += (i-lcm[f][fa])/lcm[f][fa]*2;
					}
					faux.add(f);
				}
				if (faux.size() == 3) {
					aux = lcm(lcm[faux.get(0)][faux.get(1)],faux.get(2));
					cont -= (i-aux)/aux*2;
				}
			}
			result[i] = result[i-1] + cont;
		}
		
		Scanner stdin = new Scanner(System.in);
		
		int c = stdin.nextInt();
		
		for (int i=1; i<=c; i++) {
			aux = stdin.nextInt();
			System.out.println(i+" "+aux+" "+result[aux]);
		}
		
		stdin.close();
	}
}
