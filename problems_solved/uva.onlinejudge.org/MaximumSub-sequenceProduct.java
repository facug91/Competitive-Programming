/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=649&page=show_problem&problem=728
	Name: Maximum Sub-sequence Product
	Date: 16/11/2015
*/

import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	public static void main (String [] args) throws IOException {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		Writer out = new BufferedWriter(new OutputStreamWriter(System.out));
		ArrayList<BigInteger> a;
		BigInteger bi, ans, aux;
		while (in.hasNextBigInteger()) {
			a = new ArrayList<BigInteger>();
			bi = in.nextBigInteger();
			while (bi.compareTo(new BigInteger("-999999")) != 0) {
				a.add(bi);
				bi = in.nextBigInteger();
			}
			ans = new BigInteger("-1000000");
			for (int i=0; i<a.size(); i++) {
				aux = new BigInteger("1");
				for (int j=i; j<a.size(); j++) {
					aux = aux.multiply(a.get(j));
					if (ans.compareTo(aux) < 0) ans = aux;
				}
			}
			out.write(ans.toString()+"\n");
		}
		out.flush();
		in.close();
	}
}
