/*
	By: facug91
	From: https://codility.com/demo/take-sample-test/genomic_range_query
	Name: GenomicRangeQuery
	Score: 100%
*/

#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    
    vector<int> dna[5], ans;
    int len = S.length(), i, j;
    
    for (i=0; i<len; i++) {
        switch (S[i]) {
            case 'A':
                dna[1].push_back(i);
                break;
            case 'C':
                dna[2].push_back(i);
                break;
            case 'G':
                dna[3].push_back(i);
                break;
            case 'T':
                dna[4].push_back(i);
                break;
        }
    }
    
    /*for (i=1; i<5; i++) {
        for (j=0; j<dna[i].size(); j++) {
            cout<<" "<<dna[i][j];
        }
        cout<<endl;
    }*/
    
    vector<int>::iterator itr1, itr2;
    len = P.size();
    
    for (i=0; i<len; i++) {
        j = 0;
        do {
            j++;
            if (dna[j].size() != 0) {
                itr1 = lower_bound(dna[j].begin(), dna[j].end(), P[i]);
                itr2 = upper_bound(dna[j].begin(), dna[j].end(), Q[i]);
                itr2--;
            }
        } while ((dna[j].size() == 0) || (itr1 == dna[j].end()) || ((*itr1) > (*itr2)) || ((*itr1) < P[i]) || ((*itr2) > Q[i]));
        ans.push_back(j);
    }
    
    return ans;
    
}
