/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2549
	Name: SETNJA
	Number: 2549
	Date: 22/10/2013
*/

import java.text.DecimalFormat;
import java.util.Scanner;

public class SETNJA {

	static int square (int n) {
		return (n * n);
	}
	
	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		
		int n = stdin.nextInt();
		
		int[] x = new int[n];
		int[] y = new int[n];
		
		int pointx = 0;
		int pointy = 0;
		
		for (int i=0; i<n; i++) {
			x[i] = stdin.nextInt();
			y[i] = stdin.nextInt();
			
			pointx += x[i];
			pointy += y[i];
		}
		
		System.out.println(pointx+" "+pointy);
		
		Double min = Math.sqrt(square(pointx) + square(pointy)); //distancia original
		Double aux;
		
		int j = 0;
		while ((min > 0) && (j < n)) {
			pointx -= x[j];
			pointy -= y[j];
			aux = Math.sqrt(square(pointx) + square(pointy));
			if (aux < min) {
				min = aux;
			}
			pointx += x[j];
			pointy += y[j];
			j++;
		}
		
		DecimalFormat df = new DecimalFormat("0.00");
		
		String result = df.format(min);
		result = result.substring(0,result.length()-3)+"."+result.substring(result.length()-2,result.length());
		
		System.out.println(result);
		
		stdin.close();
	}
}
