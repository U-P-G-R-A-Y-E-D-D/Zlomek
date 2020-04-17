/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Zlomek.hpp
 * Author: student
 *
 * Created on 9. března 2017, 12:52
 */

#ifndef ZLOMEK_HPP
#define ZLOMEK_HPP
#include <string>

class Zlomek {
public:
    Zlomek();
    Zlomek(const Zlomek& orig);
    virtual ~Zlomek();
    
    
    Zlomek(Zlomek&);   
    Zlomek(int,int);
    int getJmenovatel()const;
    int getCitatel()const;
    bool setJmenovatel(int);
    bool setCitatel(int);
    float desetinne()const; 
    bool kraceni();
    bool prevraceni();
    Zlomek & operator=(const Zlomek &);
    Zlomek operator+(Zlomek& zlomekKSecteni);
    Zlomek operator-(Zlomek& zlomekKOdecten);
    Zlomek operator*(Zlomek& zlomekKNasobeni);
    Zlomek operator/(Zlomek & zlomekKDeleni);
    std::string vypisZlomek()const;
    std::string vratZlomek(); 
  
private:
    int jmenovatel;
    int citatel;
    //int nejvetsiDelitel(int,int)const;
    //int nejmensiNasobek(int,int)const;
    
    int nejmensiSpolecnyNasobek(Zlomek&);

};

#endif /* ZLOMEK_HPP */

