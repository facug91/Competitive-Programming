/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1220
	Name: Come and Go
	Number: 1220
	Date: 24/10/2013
*/

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class ComeAndGo {

	public static void main (String[] args) {
		Scanner stdin = new Scanner(System.in);
		
		int n = stdin.nextInt();
		int m = stdin.nextInt();
		
		ArrayList<ArrayList<Integer>> vertices;
		ArrayList<ArrayList<Integer>> verticesEspejo;
		
		while ((n != 0) || (m != 0)) {
			vertices = new ArrayList<ArrayList<Integer>>();
			verticesEspejo = new ArrayList<ArrayList<Integer>>();
			for (int i=0; i<=n; i++) {
				vertices.add(new ArrayList<Integer>());
				verticesEspejo.add(new ArrayList<Integer>());
			}
			
			int v, w, p;
			for (int i=0; i<m; i++) {
				v = stdin.nextInt();
				w = stdin.nextInt();
				p = stdin.nextInt();
				
				vertices.get(v).add(w);
				if (p == 2) {
					vertices.get(w).add(v);
				}
				verticesEspejo.get(w).add(v);
				if (p == 2) {
					verticesEspejo.get(v).add(w);
				}
			}
			
			
			//primer dfs
			boolean[] visitados = new boolean[n+1];
			Stack<Integer> stack = new Stack<Integer>();
			
			stack.push(1);
			visitados[1] = true;
			
			int act, adj, cont = 0;
			while (!stack.empty()) {
				act = stack.pop();
				cont++;
				
				for (int i=0; i<vertices.get(act).size(); i++) {
					adj = vertices.get(act).get(i);
					if (!visitados[adj]) {
						stack.add(adj);
	                    visitados[adj] = true;
					}
				}
			}
			if (cont != n) {
				System.out.println(0);
			} else {
				//segundo dfs
				boolean[] visitadosEspejo = new boolean[n+1];
				Stack<Integer> stackEspejo = new Stack<Integer>();
				stackEspejo.push(1);
				visitadosEspejo[1] = true;
				
				cont = 0;
				while (!stackEspejo.empty()) {
					act = stackEspejo.pop();
					cont++;
					
					for (int i=0; i<verticesEspejo.get(act).size(); i++) {
						adj = verticesEspejo.get(act).get(i);
						if (!visitadosEspejo[adj]) {
							stackEspejo.add(adj);
		                    visitadosEspejo[adj] = true;
						}
					}
				}
				if (cont != n) {
					System.out.println(0);
				} else {
					System.out.println(1);
				}
			}
			
			n = stdin.nextInt();
			m = stdin.nextInt();
		}
		
		stdin.close();
	}
}
