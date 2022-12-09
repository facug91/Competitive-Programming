/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1214
	Name: Large Division
	Number: 1214
	Date: 26/07/2014
*/

import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	
	public static void main (String[] args) throws IOException {
		int t, i, j;
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		t = Integer.parseInt(in.readLine());
		for (int it=1; it<=t; it++) {
			StringTokenizer strtok = new StringTokenizer(in.readLine());
			BigInteger a = new BigInteger(strtok.nextToken());
			if (a.compareTo(BigInteger.ZERO) < 0) a = a.negate();
			BigInteger b = new BigInteger(strtok.nextToken());
			if (b.compareTo(BigInteger.ZERO) < 0) b = b.negate();
			if (a.mod(b).equals(BigInteger.ZERO)) out.write("Case "+it+": divisible\n");
			else out.write("Case "+it+": not divisible\n");
		}
		out.flush();
	}
	
}
