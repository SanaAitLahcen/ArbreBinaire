#include"ArbreB.h"



int main()
{
    ArbreB* B = new ArbreB(11);
    ArbreB arbre(10);


    B->InsertArbB(8);
    B->InsertArbB(18);
    B->InsertArbB(80);
    B->InsertArbB(76);
    B->InsertArbB(60);

    arbre.InsertArbB(2);
    arbre.InsertArbB(3);
    arbre.InsertArbB(4);
    arbre.InsertArbB(5);
    arbre.InsertArbB(12);
    arbre.InsertArbB(20);

    arbre.ParcourBFS();
    arbre.RechercheDsArbre(3);

    B->RechercheDsArbreBFS(80);

    cout << "Arbre avant suppression : ";
    B->ParcourBFS();

    B->SupprimerNoeud(18);
    cout << "Arbre après suppression : ";
    B->ParcourBFS();

   
}

