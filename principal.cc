#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <sstream> 
#include <string>
#include <vector>

using namespace std;

void func(vector<bool> &vectorB){// la funcion que hay q hacer es: "time comando"
    int pid = getpid();
    srand(pid);
    int n;
    do{
        n = rand() % (99999 - 1000 + 1) + 1000; // entre 1000 y 99999
    }while(vectorB[n - 1000]);
    vectorB[n - 1000] = true;
    string c = "./selectSort " + to_string(n) + " " + to_string(pid) + " > result.txt";
    char char_array[c.length()+1];
    strcpy(char_array, c.c_str());
    system(char_array);
    
    ifstream f = ifstream("result.txt");
    string parte;
    char fin = 10;
    getline(f,parte,fin);

    c = "./bubbleSort " + to_string(n) + " " + to_string(pid) + " > result.txt";
    char_array[c.length()+1];
    strcpy(char_array, c.c_str());
    system(char_array);

    f = ifstream("result.txt");
    string parte2;
    fin = 10;
    getline(f,parte2,fin);
    cout << n << ';' << parte << ';' << parte2 << endl;
    exit(0);
}

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    cout << "size;selectSort;bubbleSort" << endl;
    vector<bool> vectorB(8999, false);
    for(int i=0; i<n; ++i) {
        switch(fork()){
            case 0:
                func(vectorB);
                break;
            default:
                waitpid(-1, NULL,0);
                break;
        }        
    }
    exit(0);
}