/*
	By: facug91
	From: http://www.spoj.com/problems/ADDREV/
	Name: Adding Reversed Numbers
	Number: 42
	Date: 27/08/2013
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
public class Main {
	
	private Integer reverse (Integer num){
		String s = String.valueOf(num);
		String s2 = "";
		for(int i=1;i<=s.length();i++){
			s2 = s2+s.charAt(s.length()-i);
		}
		return Integer.parseInt(s2);
	}
	
	public static void main(String[] args) throws IOException {
		Main m = new Main();
		BufferedReader stdin = new BufferedReader
			(new InputStreamReader(System.in));
		Integer n = Integer.parseInt(stdin.readLine());
		String s;
		for(int i=0;i<n;i++){
			s = stdin.readLine();
			System.out.println(m.reverse(m.reverse(Integer.parseInt(s.substring(0, s.indexOf(" "))))+m.reverse(Integer.parseInt(s.substring(s.indexOf(" ")+1,s.length())))));
		}
		
    }
}
