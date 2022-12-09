/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2202
	Name: 
	Number: 2202
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class HowManyLatticePoints {

	static long gcd (long a, long b) {
		if (b == 0) {
			return a;
		} 
		return gcd(b, a%b);
	}
	
	public static void main (String[] args) throws IOException {

		BufferedReader stdin = new BufferedReader
				(new InputStreamReader(System.in));
		
		Long x, y, z;
		Long total;
		
		String input = stdin.readLine();
		while (input != null) {
			String[] inputTokens = input.split("[ ]+");
			x = Math.abs(Long.parseLong(inputTokens[0]) - Long.parseLong(inputTokens[3]));
			y = Math.abs(Long.parseLong(inputTokens[1]) - Long.parseLong(inputTokens[4]));
			z = Math.abs(Long.parseLong(inputTokens[2]) - Long.parseLong(inputTokens[5]));
			
			total = gcd(gcd(x, y), z)+1;
			
			System.out.println(total);
			
			input = stdin.readLine();
		}
		
		stdin.close();
	}
}
