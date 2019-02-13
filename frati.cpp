/* Copyright 2018
 * <Vina Nicoleta> 325CD
 */

#include <fstream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

/* structura game contine nr de jocuri, nr de benzi si suma dintre acestea */
struct game {
    int j, b, sum;
};

/* comparatorul pentru sortarea vectorului */
bool sum_comparator(const game &x, const game &y) {
    if (x.sum != y.sum) {
        return x.sum > y.sum;
    }

    return x.j > y.j;
}

int main() {
    ifstream fin;
    fin.open("frati.in");

    int n, i;
    fin >> n;

    std::vector<game> v;

    /* pentru datele de intrare, se completeaza structura game si se adauga
    in vector */
    for (i = 0; i < n; i++) {
        int jocuri, benzi;
        fin >> jocuri >> benzi;

        game g;
        g.j = jocuri;
        g.b = benzi;
        g.sum = jocuri + benzi;

        v.push_back(g);
    }

    fin.close();

    /* se sorteaza descrescator dupa suma, iar pentru sume egale, descrescator
    dupa nr de jocuri */
    std::sort(v.begin(), v.end(), sum_comparator);

    /* rez_j e rezultatul final al lui Jon, rez_s al lui Sam, iar ok-ul
    reprezinta al cui e randul sa aleaga jocul: ok=1 pentru Jon si 0 pt Sam */
    int rez_j = 0, rez_s = 0, ok = 1;

    for (i = 0; i < n; i++) {
        /* daca nu urmeaza o bucata cu sume egale, doar se adauga la rez-ul
        corespunzator */
        if (v[i + 1].sum != v[i].sum) {
            if (ok == 1) {
                rez_j += v[i].j;
                ok = 0;
            } else {
                rez_s += v[i].b;
                ok = 1;
            }

        } else {
            /* pentru fiecare bucata de vector cu elemente cu suma egala, acestea
            se adauga intr-o structura de tip deque si acesta se parcurge,
            updatand rez-urile corespunzator */
            std::deque<game> q;
            q.push_back(v[i]);

            int aux = i + 1;
            while (v[i].sum == v[aux].sum) {
                q.push_back(v[aux]);
                aux++;
            }
            aux--;

            /* cat timp deque nu este goala */
            for (int k = i; k <= aux; k++) {
                /* daca e randul lui Jon, acesta ia din fata si se elimina
                elementul, pentru ca sunt deja sortate pentru el */
                if (ok == 1) {
                    rez_j += q.front().j;
                    q.pop_front();
                    ok = 0;

                /* daca e randul lui Sam, acesta ia din spate si se elimina
                elementul, deoarece elementele luate in ordine inversa sunt
                deja sortate pentru el */
                } else {
                    rez_s += q.back().b;
                    q.pop_back();
                    ok = 1;
                }
            }

            /* continua in vector dupa ce s-a terminat de prelucrat bucata cu
            elemente cu suma egala */
            i = aux;
        }
    }

    ofstream fout;
    fout.open("frati.out");

    /* scrie cele doua rezultate finale in fisierul de iesire */
    fout << rez_j << " " << rez_s << endl;

    fout.close();

    return 0;
}
