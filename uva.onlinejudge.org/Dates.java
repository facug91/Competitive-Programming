/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2341
	Name: Dates
	Number: 11356
	Date: 07/10/2014
*/

import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	
	public static HashMap<String, Integer> monthToNumber = new HashMap<String, Integer>();
	public static HashMap<Integer, String> numberToMonth = new HashMap<Integer, String>();
	
	public static void init () {
		monthToNumber.put("January", 0);
		monthToNumber.put("February", 1);
		monthToNumber.put("March", 2);
		monthToNumber.put("April", 3);
		monthToNumber.put("May", 4);
		monthToNumber.put("June", 5);
		monthToNumber.put("July", 6);
		monthToNumber.put("August", 7);
		monthToNumber.put("September", 8);
		monthToNumber.put("October", 9);
		monthToNumber.put("November", 10);
		monthToNumber.put("December", 11);
		numberToMonth.put(0, "January");
		numberToMonth.put(1, "February");
		numberToMonth.put(2, "March");
		numberToMonth.put(3, "April");
		numberToMonth.put(4, "May");
		numberToMonth.put(5, "June");
		numberToMonth.put(6, "July");
		numberToMonth.put(7, "August");
		numberToMonth.put(8, "September");
		numberToMonth.put(9, "October");
		numberToMonth.put(10, "November");
		numberToMonth.put(11, "December");
	}
	
	public static void main (String[] args) throws IOException {
		init();
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer strtok;
		Integer year, day, month, k;
		GregorianCalendar gc;
		Integer TC = Integer.parseInt(in.readLine());
		for (Integer it=1; it<=TC; it++) {
			strtok = new StringTokenizer(in.readLine(), " -");
			year = Integer.parseInt(strtok.nextToken());
			month = monthToNumber.get(strtok.nextToken());
			day = Integer.parseInt(strtok.nextToken());
			
			gc = new GregorianCalendar(year, month, day);

			strtok = new StringTokenizer(in.readLine());
			k = Integer.parseInt(strtok.nextToken());
			
			gc.add(GregorianCalendar.DAY_OF_MONTH, k);
			out.write("Case "+it+": "+gc.get(GregorianCalendar.YEAR)+"-"+numberToMonth.get(gc.get(GregorianCalendar.MONTH))+"-"+String.format("%02d", gc.get(GregorianCalendar.DAY_OF_MONTH))+"\n");
		}
		
		out.flush();
	}
	
}
