//
//  main.cpp
//  Diffie-Hellman
//
//  Created by jonas on 02/04/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#include <iostream>
#include "math.h"
#include <vector>
using namespace std;

vector<int> binario;

void decimal2binario(int dec){
    if (dec!=0)
    {
        decimal2binario(dec/2);
        binario.push_back(dec%2);
    }
}
int expRap(int n, int exp, int mod){
    decimal2binario(exp);
    for (int i = 0; i < binario.size(); i++) {
        cout << binario[i];
    }
    //cout << endl;
    int x = 1;
    int resultado = 0;
    for (int i = 0; i < binario.size(); i++) {
        if (binario[i] == 1) {
            resultado = ((x*x)*n)%mod;
            //cout << "i= " << i << ", b" << i << "= " << binario[i] << " x= " << x << "^" << n << "mod" << mod << " = " << resultado << endl;
        } else if (binario[i] == 0) {
            resultado = (x*x)%mod;
            //cout << "i= " << i << ", b" << i << "= " << binario[i] << " x= " << x << "^" << n << "mod" << mod << " = " << resultado << endl;
        }
        x = resultado;
    }
    return resultado;
}


int main()
{
    long int p,g,a,b,A,B,K,K1,divisor,X=1;
    bool primo = true;
    cout << "INTERCAMBIO DE CLAVES DE DIFFIE HELLMAN" << endl;
    cout << "---------------------------------------" << endl;
    while (X==1) {
        primo = true;
        cout << "Introduce el número primo p:" << endl;
        cin >> p;
        for (divisor=2; divisor<=sqrt(p); divisor++) {
            if (p%divisor==0) {
                primo = false;
            }
        }
        if (primo == true) {
            X=0;
        } else {
            cout << "Debe introducirse un número primo" << endl;
        }
    }
    cout << "Introduce el número g<p:" << endl;
    cin >> g;
    cout << "Introduce los números secretos:" << endl;
    cout << "   Xa: ";
    cin >> a;
    cout << "   Xb: ";
    cin >> b;
    //Operaciones
    A = expRap(g, a, p);
    B = expRap(g, b, p);
    
    K = expRap(B, a, p);
    K1 = expRap(A, b, p);
    if (K==K1) {
        cout << "p = " << p << ", g = " << g << ", Xa = " << a << ", Xb = " << b << ", yA = " << A << ", yB = " << B << ", K = " << K << endl;
    }
    //mostrar resultado
    
    
    return 0;
}

