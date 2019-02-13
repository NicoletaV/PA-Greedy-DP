/* Copyright 2018
 * <Vina Nicoleta> 325CD
 */

#include <fstream>
using namespace std;

int main() {
	ifstream fin;
    fin.open("planificare.in");

    unsigned int p, d, b, i, x;
    /* pierderile l sunt initializate cu 0, nr de concursuri cu 1 */
    unsigned long long int l = 0, n = 1, aux, t;

    /* se citesc P, D, B si prima durata x din fisier */
    fin >> p >> d >> b >> x;

    /* totalul porneste cu valoarea lui x */
    t = x;

    /* se citesc si prelucreaza pe rand cele p-1 durate ramase */
    for (i = 0; i < p-1; i++) {
        fin >> x;

        /* daca la totalul curent se adauga pauza si durata curenta si ar depasi
        durata D, se incrementeaza nr de concursuri si se adauga pierderea
        curenta la pierderile totale; se reseteaza apoi totalul la durata
        curenta a probei */
        if (t + b + x > d) {
            n++;
            aux = d - t;
            l += aux * aux * aux;
            t = x;

        /* altfel, doar se adauga (durata + pauza) la totalul curent t
        si se continua verificarile si citirile */
        } else {
            t += b + x;
        }
    }

    fin.close();

    ofstream fout;
    fout.open("planificare.out");
    /* se scriu pierderile totale si nr de concursuri in fisierul de output */
    fout << l << " " << n;
    fout.close();

	return 0;
}
