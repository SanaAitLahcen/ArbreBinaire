#include "ArbreB.h"



ArbreB::ArbreB(int val):Fdt(NULL),Fgh(NULL),value(val)
{
}

ArbreB* ArbreB::getFdt()
{
    return Fdt;
}

ArbreB* ArbreB::getFgh()
{
    return Fgh;
}

int ArbreB::getVal()
{
    return value;
}


//Ins�rer dans une arbre binaire
void ArbreB::InsertArbB(int val)
{

    
    if (Fgh == nullptr) 
    {
        Fgh = new ArbreB(val); 
    }
    else if (Fdt == nullptr)
    {
        Fdt = new ArbreB(val); 
    }
    else 
    {
        Fgh->InsertArbB(val);
    }
    
}

bool ArbreB::SupprimerNoeudClassique(int val)
{
    if (this == nullptr) return false;

    queue<ArbreB*> file;
    file.push(this);

    ArbreB* noeudCible = nullptr; // N�ud � supprimer
    ArbreB* dernierNoeud = nullptr; // Dernier n�ud rencontr�
    ArbreB* parentDernierNoeud = nullptr; // Parent du dernier n�ud

    // Parcours BFS pour localiser le n�ud � supprimer et le dernier n�ud
    while (!file.empty()) 
    {
        ArbreB* noeud = file.front();
        file.pop();

        // Identifier le n�ud � supprimer
        if (noeud->getVal() == val)
        {
            noeudCible = noeud;
        }

        // Identifier le dernier n�ud rencontr� et son parent
        if (noeud->getFgh())
        {
            parentDernierNoeud = noeud;
            file.push(noeud->getFgh());
        }
        if (noeud->getFdt())
        {
            parentDernierNoeud = noeud;
            file.push(noeud->getFdt());
        }

        dernierNoeud = noeud; // Mettre � jour le dernier n�ud
    }

    // Si le n�ud � supprimer n'a pas �t� trouv�
    if (!noeudCible) 
    {
        cout << "Valeur " << val << " non trouv�e dans l'arbre." << endl;
        return false;
    }

    // Remplacer la valeur du n�ud � supprimer par celle du dernier n�ud
    noeudCible->value = dernierNoeud->value;

    // Supprimer le dernier n�ud
    if (parentDernierNoeud)
    {
        if (parentDernierNoeud->getFgh() == dernierNoeud)
        {
            delete parentDernierNoeud->Fgh;
            parentDernierNoeud->Fgh = nullptr;
        }
        else if (parentDernierNoeud->getFdt() == dernierNoeud)
        {
            delete parentDernierNoeud->Fdt;
            parentDernierNoeud->Fdt = nullptr;
        }
    }
    else
    {
        // Cas particulier : si l'arbre ne contient qu'un seul n�ud
        delete this;
    }

    return true;
}



//Rechercher simple d'une valeur dans l'arbre binaire

ArbreB* ArbreB::RechercheDsArbre(int val)
{
    if (value == val)
    {
        cout << "Element " << val << " est trouve !" << endl;
        return this;
    }
        ArbreB* Gauche = (Fgh != nullptr) ? Fgh->RechercheDsArbre(val) : nullptr;
        ArbreB* Droite = (Fdt != nullptr) ? Fdt->RechercheDsArbre(val) : nullptr;
        return (Gauche != nullptr) ? Gauche : Droite;
    
}



//Le parcours BFS
void ArbreB::ParcourBFS()
{   
    if (!this) return;
    queue<ArbreB*> file;
    file.push(this);

    while (!file.empty()) 
    {
        ArbreB* noeud = file.front(); 
        file.pop();
        cout << noeud->getVal() << " ";

        if (noeud->getFgh() != nullptr) file.push(noeud->getFgh());
        if (noeud->getFdt() != nullptr) file.push(noeud->getFdt());
    }
    cout << endl;
}


//Rechercher  d'une valeur dans l'arbre binaire en utilisant un parcours BFS

ArbreB* ArbreB::RechercheDsArbreBFS(int val)
{
    if (this == nullptr) return nullptr;

    queue<ArbreB*> file;
    file.push(this);  

    while (!file.empty()) 
    {
        ArbreB* noeud = file.front(); 
        file.pop();  

        
        if (noeud->getVal() == val) 
        {
            cout << "Element " << val << " est trouve !" << endl;
            return noeud;  
        }

       
        if (noeud->getFgh() != nullptr) file.push(noeud->getFgh());
        if (noeud->getFdt() != nullptr) file.push(noeud->getFdt());
    }

    
    cout << "Element " << val << " non trouve dans l'arbre." << endl;
    return nullptr;
}

