#include <iostream>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <stdlib.h>

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

void swap(vector<int> &v, int i, int j){// i > j
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int s = atoi(argv[2]);
    vector<int> v = desordenar(n, s);
    unsigned t0 = clock();
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < n - i - 1; ++j){
            if(v[j] > v[j + 1]){
                swap(v,j, j+1);
            }
        }
    }
    unsigned t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << time << endl;
}