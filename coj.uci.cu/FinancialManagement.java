/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1023
	Name: Freckles
	Number: 1023
	Date: 17/10/2013
*/

import java.text.DecimalFormat;
import java.util.Scanner;

public class FinancialManagement {

	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		
		Double total = 0.0;
		for (int i=0; i<12; i++) {
			total += Double.valueOf(stdin.next());
		}
		
		total /= 12.0;
		
		DecimalFormat df = new DecimalFormat("0.00");
		
		String result = "$"+df.format(total);
		result = result.substring(0, result.length()-3) + "." + result.substring(result.length()-2, result.length());
		
		System.out.println(result);
		
		stdin.close();
	}
}
