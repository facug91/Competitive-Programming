/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1293
	Name: Powers of Two
	Number: 1293
	Date: 11/11/2013
*/

import java.math.BigInteger;
import java.util.Scanner;


public class Auxiliar {
    
    public static void main(String [] args) {
    	BigInteger bi = new BigInteger("2");
    	Scanner stdin = new Scanner(System.in);
    	System.out.println(bi.pow(stdin.nextInt()).toString());
		stdin.close();
    }
}
