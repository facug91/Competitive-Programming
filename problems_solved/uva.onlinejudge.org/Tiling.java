/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1300
	Name: Tiling
	Number: 10359
	Date: 07/10/2014
*/

import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	
	public static ArrayList<BigInteger> DP = new ArrayList<BigInteger>(255);
	public static void init () {
		DP.add(new BigInteger("1"));
		DP.add(new BigInteger("1"));
		for (int i=2; i<255; i++) {
			DP.add(DP.get(i-1).add(DP.get(i-2).multiply(new BigInteger("2"))));
		}
	}
	
	public static void main (String[] args) throws IOException {
		init();
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		int n;
		while (in.hasNextInt()) {
			n = in.nextInt();
			out.write(DP.get(n).toString()+"\n");
		}
		
		out.flush();
	}
	
}
