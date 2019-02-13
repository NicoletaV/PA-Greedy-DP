/* Copyright 2018
 * <Vina Nicoleta> 325CD
 */

#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin;
    fin.open("numaratoare.in");

    int s, n, j, aux, k = 0;
    long long int i, l = -1;

    /* se citesc datele de intrare */
    fin >> s >> n >> i;
    fin.close();

    /* in vectorul ce va stoca partitiile, cu s elemente, se pune s pe
    prima pozitie */
    std::vector<int> v(s);
    v[0] = s;

    ofstream fout;
    fout.open("numaratoare.out");

    while (1) {
    	aux = 0;

    	while (k >= 0 && v[k] == 1) {
    		aux += v[k];
    		k--;
    	}

    	/* cand k = 0 nu mai sunt partitii, intrucat toti termenii exprimarii
    	sunt 1 */
    	if (k < 0) {
    		break;
    	}

        aux++;
    	v[k]--;

    	/* se pune aux la v[k+1] si noua partitie e v[0...k+1] */
    	while (aux > v[k]) {
    		v[k + 1] = v[k];
    		aux -= v[k];
    		k++;
    	}

        /* se incrementeaza pozitia si se pune aux in vector la aceasta */
        k++;
        v[k] = aux;

        /* daca exprimarea contine n termeni, se numara in l */
        if (k == n-1) {
            l++;

            /* s-a ajuns la a "i"-a exprimare, aceasta se afiseaza in fisier */
            if (l == i) {
                fout << s << "=" << v[0];

                for (j = 1; j < k + 1; j++) {
                    fout << "+" << v[j];
                }
                break;
            }
        }
    }

    /* daca nu s-a gasit solutie */
    if (l != i) {
    	fout << "-";
    }

    fout.close();

	return 0;
}
