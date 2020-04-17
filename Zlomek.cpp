/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Zlomek.cpp
 * Author: student
 * 
 * Created on 9. března 2017, 12:52
 */

#include "Zlomek.hpp"
#include <sstream>
#include <cstdlib>
#include <string>


using namespace std;



Zlomek::Zlomek(){
    this->citatel = 1;
    this->jmenovatel = 1;
}

Zlomek::Zlomek(int citatel,int jmenovatel){
    this->citatel=citatel;
    if(jmenovatel!=0){
        this->jmenovatel=jmenovatel;
    }
    else
    {
        this->jmenovatel=1;
    }
}

Zlomek::Zlomek(const Zlomek& orig) {
}

Zlomek::~Zlomek() {
}

int Zlomek::getCitatel()const{
    return this->citatel;
}

int Zlomek::getJmenovatel() const{
    return this->jmenovatel;
}

std::string Zlomek::vypisZlomek()const{
    std::ostringstream vystup;
    if((this->citatel < 0 && this->jmenovatel > 0) || (this->citatel > 0 && this->jmenovatel<0))
        vystup<<"-";
    vystup<<abs(this->citatel)<<"/"<<abs(this->jmenovatel);
    return vystup.str();
}

bool Zlomek::setCitatel(int citatel){
    this->citatel = citatel;
    return true;
}

bool Zlomek::setJmenovatel(int jmenovatel){
    if(jmenovatel==0)
        return false;
    else{
        this->jmenovatel=jmenovatel;
        return true;
    }
}

float Zlomek::desetinne() const{
    return(float) this->citatel / (float) this->jmenovatel;
}

bool Zlomek::prevraceni(){
    int pom;
        if(this->citatel == 0)
        return false;
    else{
        pom = this->citatel;
        this->citatel = this->jmenovatel;
        this->jmenovatel = pom;
        return true;
    }
}


//Scitani, odcitani, nasobeni, deleni

Zlomek::Zlomek(Zlomek & druhyZlomek)
{
	/*
		Hlavne pri pocetnich operacich, pokud dostanu adresu nejakeho Zlomku, nastavim jeho hodnoty do nynejsiho pairu.
	*/

	this->citatel = druhyZlomek.citatel;
	this->jmenovatel = druhyZlomek.jmenovatel;
}

Zlomek Zlomek::operator+(Zlomek& zlomekKSecteni){
    
	if (this->jmenovatel == zlomekKSecteni.jmenovatel)
		return Zlomek(this->citatel + zlomekKSecteni.citatel, this->jmenovatel);
	else {
		int nsn = this->nejmensiSpolecnyNasobek(zlomekKSecteni);
		return Zlomek((nsn / this->jmenovatel * this->citatel) + (nsn / zlomekKSecteni.jmenovatel * zlomekKSecteni.citatel), nsn);
	}
}


Zlomek Zlomek::operator-(Zlomek& zlomekKOdecteni) {
	/*
		1. Pripad:
			Jestlize je jmenovatel stejny, staci odecist citatele a jmenovatel zustane stejny.

		2. Pripad:
			Jestli jsou jmenovatele rozdilni, najdu nejmensi spolecny nasobek a podle pravidel zlomku citatele vhodne vynasobim a odectu.
	*/

	if (this->jmenovatel == zlomekKOdecteni.jmenovatel)
		return Zlomek(this->citatel - zlomekKOdecteni.citatel, this->jmenovatel);
	else {
		int nsn = this->nejmensiSpolecnyNasobek(zlomekKOdecteni);
		return Zlomek((nsn / this->jmenovatel * this->citatel) - (nsn / zlomekKOdecteni.jmenovatel * zlomekKOdecteni.citatel), nsn);
	}
}

Zlomek Zlomek::operator*(Zlomek& zlomekKNasobeni){
	/*
		V pripade nasobeni staci vynasobit citatele spolu a jmenovatele spolu.
	*/

	return Zlomek(this->citatel * zlomekKNasobeni.citatel, this->jmenovatel * zlomekKNasobeni.jmenovatel);
}

Zlomek Zlomek::operator/(Zlomek & zlomekKDeleni){
	/*
		V pripade deleni staci obratit druhy zlomek a vzajemne je opet vynasobit.
		Funguje kraceni zlomku, hleda se nejvyssi spolecny. Nejdriv se najde nizsi cislo z citatele a jmenovatele a pote se odecita.
	*/
	Zlomek vynasobenyZlomek(this->citatel * zlomekKDeleni.jmenovatel, this->jmenovatel * zlomekKDeleni.citatel);
	int min = (vynasobenyZlomek.citatel < vynasobenyZlomek.jmenovatel) ? vynasobenyZlomek.citatel : vynasobenyZlomek.jmenovatel;

	while (!((vynasobenyZlomek.citatel % min == 0 && vynasobenyZlomek.jmenovatel % min == 0) || min == 0)) {
		min--;
	}

	if (min == 0)
		return vynasobenyZlomek;

	return Zlomek(vynasobenyZlomek.citatel / min, vynasobenyZlomek.jmenovatel / min);
}

 




std::string Zlomek::vratZlomek()
{
	/*
		Vraceni zlomku jako string v improvizovanem stavu.
	*/
	return std::to_string(this->citatel) + "/" + std::to_string(this->jmenovatel);
}

int Zlomek::nejmensiSpolecnyNasobek(Zlomek& druhyZlomek)
{
	/*
		Vzorecek jsem nasel na internetu, ale trosku jsem zkratil cyklus while... Podminku jsem hodil na zacatek.
	*/
	int maxValue;
	maxValue = (this->jmenovatel > druhyZlomek.jmenovatel) ? this->jmenovatel : druhyZlomek.jmenovatel;

	while (!( (maxValue % this->jmenovatel == 0) && (maxValue % druhyZlomek.jmenovatel == 0) )) {
		maxValue++;
	}

	return maxValue;
}
