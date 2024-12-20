#pragma once
#include<iostream>
#include<string>
#include <queue>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

class ArbreB
{
private:
	int value;
	ArbreB* Fdt;
	ArbreB* Fgh;

public:
	ArbreB(int );
	ArbreB* getFdt();
	ArbreB* getFgh();
	int getVal();
	void InsertArbB(int val);
	bool SupprimerNoeud(int val);
	ArbreB* RechercheDsArbre(int);
	void ParcourBFS();
	ArbreB* RechercheDsArbreBFS(int val);

};

