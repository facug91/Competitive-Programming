/*
        By: facug91
        From: http://www.spoj.com/problems/TAP2014K/
        Name: Encryption kit
        Date: 10/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
#define list askjdgisebwqdasbjdgbq
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

struct node {
	int sum, prev, next, ini, end;
	bool inv;
	node () {
		sum = 0;
		prev = next = ini = end = -1;
		inv = false;
	}
	node (int _ini, int _end) {
		sum = 0;
		prev = next = -1;
		ini = _ini; end = _end;
		inv = false;
	}
};

node list[350];
int size;
string s;
int n, i, j, k, l;

void swap_segments () {
	
	int idx = list[0].next, bnum = 0, num = (list[idx].end - list[idx].ini);
	//busca el comienzo de i
	while (num <= i) {
		idx = list[idx].next;
		bnum = num;
		num += (list[idx].end - list[idx].ini);
	}
	
	if (bnum != i) {
		//divide el nodo
		list[size] = node();
		list[size].next = list[idx].next;
		list[idx].next = size;
		list[list[size].next].prev = size;
		list[size].prev = idx;
		list[size].inv = list[idx].inv;
		list[size].sum = list[idx].sum;
		if (list[idx].inv) {
			list[size].ini = list[idx].ini;
			list[size].end = list[idx].end - (i - bnum);
			list[idx].ini = list[size].end;
		} else {
			list[size].end = list[idx].end;
			list[idx].end = list[idx].ini + (i - bnum);
			list[size].ini = list[idx].end;
		}
		idx = size++;
	}
	int a = idx; //el índice del primer nodo del segmento [i, j)
	bnum = i;
	num = i + (list[idx].end - list[idx].ini);
	
	//invierte todos los nodos entre i y j
	while (num <= j) {
		list[idx].inv = !list[idx].inv;
		list[idx].sum++;
		swap(list[idx].prev, list[idx].next);
		idx = list[idx].prev;
		bnum = num;
		num += (list[idx].end - list[idx].ini);
	}
	
	if (bnum != j) {
		//divide el nodo
		list[size] = node();
		list[size].next = list[idx].next;
		list[idx].next = size;
		list[list[size].next].prev = size;
		list[size].prev = idx;
		list[size].inv = list[idx].inv;
		list[size].sum = list[idx].sum;
		if (list[idx].inv) {
			list[size].ini = list[idx].ini;
			list[size].end = list[idx].end - (j - bnum);
			list[idx].ini = list[size].end;
		} else {
			list[size].end = list[idx].end;
			list[idx].end = list[idx].ini + (j - bnum);
			list[size].ini = list[idx].end;
		}
		//invierte el pedazo que faltó
		list[idx].inv = !list[idx].inv;
		list[idx].sum++;
		swap(list[idx].prev, list[idx].next);
		idx = size++;
		bnum = j;
		num = j + (list[idx].end - list[idx].ini);
	}
	int b = list[idx].prev; //el índice del último nodo del segmento [i, j)
	
	//busca el comienzo de k
	while (num <= k) {
		idx = list[idx].next;
		bnum = num;
		num += (list[idx].end - list[idx].ini);
	}
	
	if (bnum != k) {
		//divide el nodo
		list[size] = node();
		list[size].next = list[idx].next;
		list[idx].next = size;
		list[list[size].next].prev = size;
		list[size].prev = idx;
		list[size].inv = list[idx].inv;
		list[size].sum = list[idx].sum;
		if (list[idx].inv) {
			list[size].ini = list[idx].ini;
			list[size].end = list[idx].end - (k - bnum);
			list[idx].ini = list[size].end;
		} else {
			list[size].end = list[idx].end;
			list[idx].end = list[idx].ini + (k - bnum);
			list[size].ini = list[idx].end;
		}
		idx = size++;
	}
	int c = idx; //el índice del primer nodo del segmento [k, l)
	bnum = k;
	num = k + (list[idx].end - list[idx].ini);
	
	//invierte todos los nodos entre k y l
	while (num <= l) {
		list[idx].inv = !list[idx].inv;
		list[idx].sum++;
		swap(list[idx].prev, list[idx].next);
		idx = list[idx].prev;
		bnum = num;
		num += (list[idx].end - list[idx].ini);
	}
	
	if (bnum != l) {
		//divide el nodo
		list[size] = node();
		list[size].next = list[idx].next;
		list[idx].next = size;
		list[list[size].next].prev = size;
		list[size].prev = idx;
		list[size].inv = list[idx].inv;
		list[size].sum = list[idx].sum;
		if (list[idx].inv) {
			list[size].ini = list[idx].ini;
			list[size].end = list[idx].end - (l - bnum);
			list[idx].ini = list[size].end;
		} else {
			list[size].end = list[idx].end;
			list[idx].end = list[idx].ini + (l - bnum);
			list[size].ini = list[idx].end;
		}
		//invierte el pedazo que faltó
		list[idx].inv = !list[idx].inv;
		list[idx].sum++;
		swap(list[idx].prev, list[idx].next);
		idx = size++;
		bnum = l;
		num = l + (list[idx].end - list[idx].ini);
	}
	int d = list[idx].prev; //el índice del último nodo del segmento [k, l)
	
	//realiza el swap de los índices
	list[list[d].prev].prev = a;
	list[list[a].next].next = d;
	swap(list[a].next, list[d].prev);
	if (list[b].prev != c) {
		list[list[b].prev].prev = c;
		list[list[c].next].next = b;
		swap(list[b].prev, list[c].next);
	}
}

void compress () {
	int i, j;
	string aux = "";
	i = list[0].next;
	while (i != 2){
		if (list[i].inv) {
			for (j=list[i].end-1; j>=list[i].ini; j--) {
				aux += (char)((((s[j]-'a')+list[i].sum)%26)+'a');
			}
		} else {
			for (j=list[i].ini; j<list[i].end; j++) {
				aux += (char)((((s[j]-'a')+list[i].sum)%26)+'a');
			}
		}
		i = list[i].next;
	}
	s = aux;
	//inicializa la lista
	list[0] = node(-1, 0);
	list[1] = node(0, s.length());
	list[2] = node(s.length(), s.length()+1);
	list[0].prev = -1;
	list[0].next = 1;
	list[1].prev = 0;
	list[1].next = 2;
	list[2].prev = 1;
	list[2].next = -1;
	size = 3;
}

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC;
	
	cin>>TC;
	while (TC--) {
		cin>>s;
		
		//inicializa la lista
		list[0] = node(-1, 0);
		list[1] = node(0, s.length());
		list[2] = node(s.length(), s.length()+1);
		list[0].prev = -1;
		list[0].next = 1;
		list[1].prev = 0;
		list[1].next = 2;
		list[2].prev = 1;
		list[2].next = -1;
		size = 3;
		
		cin>>n;
		int limit = sqrt(s.length()) + 5;
		while (n--) {
			cin>>i>>j>>k>>l; i--; k--;
			swap_segments();
			if (size > limit) compress();
		}
		compress();
		cout<<s<<endl;
	}
	
	return 0;
}
