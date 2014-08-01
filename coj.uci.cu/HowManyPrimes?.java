/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2427
	Name: How Many Primes?
	Number: 2427
	Date: 23/10/2013
*/

import java.util.Scanner;

public class HowManyPrimes {

	public static void main (String[] args) {
		int[] primes = new int[1000001];
		primes[2] = 1;
		int ant = 1;
		for (int i=4; i<1000001; i+=2) {
			primes[i] = -1;
		}
		for (int i=3; i<=1001; i+=2) {
			if (primes[i] != -1) {
				ant++;
				primes[i] = ant;
				for (int j=i+i*2; j<1000001; j+=i*2) {
					primes[j] = -1;
				}
			}
		}
		for (int i=1003; i<1000001; i+=2) {
			if (primes[i] != -1) {
				ant++;
				primes[i] = ant;
			}
		}
		
		Scanner stdin = new Scanner(System.in);
		
		int a = stdin.nextInt();
		int b = stdin.nextInt();
		
		while ((a != 0) && (b != 0)) {
			while ((primes[a] == -1) && (a < 1000000)) {
				a++;
			}
			if (a > b) {
				System.out.println(0);
			} else {
				while ((primes[b] == -1) && (b > 0)) {
					b--;
				}
				if (a > b) {
					System.out.println(0);
				} else {
					System.out.println(primes[b]-primes[a]+1);
				}
			}
			a = stdin.nextInt();
			b = stdin.nextInt();
		}
		
		
		
		
		
		
		
		stdin.close();
	}
}
