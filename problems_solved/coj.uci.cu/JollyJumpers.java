/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=
	Name: Jolly Jumpers
	Number: 1294
	Date: 05/10/2013
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main01 {
	
	public static void main (String[] args) throws IOException{
		BufferedReader stdin = new BufferedReader
				(new InputStreamReader(System.in));
		String s;
		String delimiter = "[ ]+";
		String[] tokens;
		
		while((s = stdin.readLine()) != null){

			tokens = s.split(delimiter); //arreglo con todos los numeros de la linea

			long n = Long.parseLong(tokens[0]); //cantidad de numeros de la secuencia

			if (n > 1){
				
				Set<Long> sequence = new HashSet<Long>();
				
				for(long j=1;j<n;j++) //armado de un set con los numeros de la secuencia
					sequence.add(j);
				for(int i=1;i<n;i++){ //recorrido de la linea de números
					sequence.remove(Math.abs(Long.parseLong(tokens[i])-Long.parseLong(tokens[i+1])));
				}

				if (sequence.isEmpty()){
					System.out.println("Jolly");
				}else{
					System.out.println("Not jolly");
				}
				
			} else {
				
				if (n == 1){
					System.out.println("Jolly");
				}
				
				else
					System.out.println("Not jolly");
			}
		}
	}
}
