#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <ctime>

using namespace std;


vector<int> desordenar(int n, int s){
    vector<bool> nUsed(n, false);
    vector<int> v(n);
    srand(s);
    for(int i = 0; i < n; ++i){
        do{
            v[i] = rand() % n;
        }while(nUsed[v[i]]);
        nUsed[v[i]] = true;
    }
    return v;
}

void swap(vector<int> &v, int i, int j){// i < j
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int s = atoi(argv[2]);
    vector<int> v = desordenar(n,s);
    unsigned t0 = clock();
    for(int i = 0; i < n; ++i){
        int min = v[i];
        int ix = i;
        for(int j = i + 1; j < n; ++j){
            if(min > v[j]){
                min = v[j];
                ix = j;
            }
        }
        swap(v, i, ix);
    }
    unsigned t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << time << endl;
}