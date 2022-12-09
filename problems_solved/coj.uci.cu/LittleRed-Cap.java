/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2553
	Name: Little Red-Cap
	Number: 2553
	Date: 24/10/2013
*/

import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class LittleRedCap {
	
	public static void main (String[] args) {
		long[] alternativas; //alternativas de cada vertice
		long[] maxalt; //la cantidad máxima de alternativas para ese vertice
		boolean[] visitados; //si fueron visitados o no en el dfs
		ArrayList<ArrayList<Integer>> vertices;
		
		Scanner stdin = new Scanner(System.in);
		
		int n = stdin.nextInt();
		int s = stdin.nextInt();
		
		vertices = new ArrayList<ArrayList<Integer>>();
		for (int i=0; i<=n; i++) {
			vertices.add(new ArrayList<Integer>());
		}
		
		int v1, v2;
		for (int i=0; i<s; i++) {
			v1 = stdin.nextInt();
			v2 = stdin.nextInt();
			vertices.get(v1).add(v2);
			vertices.get(v2).add(v1);
		}
		
		alternativas = new long[n+1];
		alternativas[n] = 1;
		for (int i=n; i>0; i--) {
			for (Integer v: vertices.get(i)) {
				if (v < i) {
					alternativas[v] += alternativas[i];
				}
			}
		}
		
		maxalt = new long[n+1];
		visitados = new boolean[n+1];
		PriorityQueue<Integer> queue = new PriorityQueue<Integer>();
		
		queue.add(1);
		visitados[1] = true;
		maxalt[1] = alternativas[1];
		int v, w;
		
		while(!queue.isEmpty()) {
			v = queue.poll();
			
			for (int i=0; i<vertices.get(v).size(); i++) {
				w = vertices.get(v).get(i);
				if (w > v) {
					if (maxalt[w] < alternativas[w]+maxalt[v]) {
						maxalt[w] = alternativas[w]+maxalt[v];
					}
					if (!visitados[w]) {
						visitados[w] = true;
						queue.add(w);
					}
				}
			}
			
		}
		
		System.out.println(maxalt[n]);
		
		stdin.close();
	}
}
