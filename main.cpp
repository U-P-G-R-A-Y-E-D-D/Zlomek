/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: student
 *
 * Created on 9. března 2017, 12:51
 */

#include <cstdlib>
#include <iostream>
#include "Zlomek.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
 
    
    Zlomek z1;
    Zlomek z2(-1,2);
    Zlomek z3;
    int vstup;
    
    
    Zlomek zlomek1(5, 12);
	Zlomek zlomek2(10, 5);

	Zlomek zlomek3 = zlomek1 + zlomek2;
	Zlomek zlomek4 = zlomek1 - zlomek2;
	Zlomek zlomek5 = zlomek1 * zlomek2;
	Zlomek zlomek6 = zlomek1 / zlomek2;

	cout << "Secteni zlomku: " << zlomek1.vratZlomek() << " + " << zlomek2.vratZlomek() << " = " << zlomek3.vratZlomek() << endl;
	cout << "Odecteni zlomku: " << zlomek1.vratZlomek() << " - " << zlomek2.vratZlomek() << " = " << zlomek4.vratZlomek() << endl;
	cout << "Vynasobeni zlomku: " << zlomek1.vratZlomek() << " * " << zlomek2.vratZlomek() << " = " << zlomek5.vratZlomek() << endl;
	cout << "Vydeleni zlomku: " << zlomek1.vratZlomek() << " / " << zlomek2.vratZlomek() << " = " << zlomek6.vratZlomek() << endl;
    
        cout<<endl;
        cout<<endl;
                
        
    cout<<"Objekt vytvoreny konstruktorem bez parametru: "<<z1.vypisZlomek()<<endl;
    cout<<"Objekt jako desetinne cislo: "<<z1.desetinne()<<endl;
    cout<<"Objekt vytvoreny konstruktorem s parametrem: "<<z2.vypisZlomek()<<endl;
    cout<<"Objekt jako desetinne cislo: "<<z2.desetinne()<<endl;
    z2.prevraceni();
    cout<<"Objekt po prevraceni: "<<z2.vypisZlomek()<<endl;
    cout<<"Zadej citatel: ";
    cin>>vstup;
    z3.setCitatel(vstup);
    cout<<"Zlomek po zmene citatele: "<<z3.vypisZlomek()<<endl;
    cout<<"Zadej jmenovatel: "; 
    cin>>vstup;
    if(z3.setJmenovatel(vstup)){
        cout<<"Zlomek po zmene jmenovatele: "<<z3.vypisZlomek()<<endl;
        cout<<"Objekt jako desetinne cislo: "<<z3.desetinne()<<endl;
        if(z3.prevraceni())
           cout<<"Objekt po prevraceni: "<<z3.vypisZlomek()<<endl;
        else
           cout<<"Zlomek nelze prevratit"<<endl; 
    }
    else
        cout<<"Jmenovatele nelze zmenit."<<endl;
       


    
    
    
    
    return 0;
}


