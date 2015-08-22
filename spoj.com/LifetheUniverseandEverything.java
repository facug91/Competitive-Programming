/*
	By: facug91
	From: http://www.spoj.com/problems/TEST/
	Name: Life, the Universe, and Everything
	Number: 1
	Date: 27/08/2013
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader stdin = new BufferedReader
			(new InputStreamReader(System.in));
		Integer num = Integer.parseInt(stdin.readLine());
		while (num != 42){
			System.out.println(num);
			num = Integer.parseInt(stdin.readLine());
		}
    }
} 
