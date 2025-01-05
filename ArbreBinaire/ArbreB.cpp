#include "ArbreB.h"

ArbreB::ArbreB(int val) : Fdt(NULL), Fgh(NULL), value(val)
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

// Insérer une nouvelle valeur dans l'arbre binaire
void ArbreB::InsertArbB(int val)
{
    // Si le fils gauche est vide, insérer à gauche
    if (Fgh == nullptr)
    {
        Fgh = new ArbreB(val);
    }
    // Sinon, si le fils droit est vide, insérer à droite
    else if (Fdt == nullptr)
    {
        Fdt = new ArbreB(val);
    }
    // Si les deux enfants sont présents, continuer l'insertion à gauche
    else
    {
        Fgh->InsertArbB(val);
    }
}

// Supprimer un noeud de l'arbre binaire
bool ArbreB::SupprimerNoeud(int val)
{
    // Si l'arbre est vide, retourner false
    if (this == nullptr) return false;

    queue<ArbreB*> file;  // Queue pour effectuer un parcours BFS
    file.push(this);

    ArbreB* noeudCible = nullptr;          // Noeud à supprimer
    ArbreB* dernierNoeud = nullptr;        // Dernier noeud rencontré
    ArbreB* parentDernierNoeud = nullptr;  // Parent du dernier noeud rencontré

    // Parcours BFS pour localiser le noeud à supprimer et le dernier noeud
    while (!file.empty())
    {
        ArbreB* noeud = file.front();  // Récupérer le noeud courant
        file.pop();

        // Si le noeud courant a la valeur recherchée, le marquer comme noeud à supprimer
        if (noeud->getVal() == val)
        {
            noeudCible = noeud;
        }

        // Ajouter les enfants à la file pour parcourir l'arbre
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

        dernierNoeud = noeud;  // Mettre à jour le dernier noeud
    }

    // Si le noeud à supprimer n'a pas été trouvé, afficher un message d'erreur
    if (!noeudCible)
    {
        cout << "Valeur " << val << " non trouvée dans l'arbre." << endl;
        return false;
    }

    // Remplacer la valeur du noeud à supprimer par celle du dernier noeud
    noeudCible->value = dernierNoeud->value;

    // Supprimer le dernier noeud
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
        // Cas particulier : si l'arbre ne contient qu'un seul noeud
        delete this;
    }

    return true;
}



// Rechercher un noeud avec une valeur spécifique dans l'arbre de manière récursive
ArbreB* ArbreB::RechercheDsArbre(int val)
{
    // Si le noeud courant contient la valeur, le retourner
    if (value == val)
    {
        cout << "Element " << val << " est trouve !" << endl;
        return this;
    }

    // Rechercher dans les sous-arbres gauche et droit, si présents
    ArbreB* Gauche = (Fgh != nullptr) ? Fgh->RechercheDsArbre(val) : nullptr;
    ArbreB* Droite = (Fdt != nullptr) ? Fdt->RechercheDsArbre(val) : nullptr;

    // Retourner le noeud trouvé (gauche ou droite)
    return (Gauche != nullptr) ? Gauche : Droite;
}

// Parcours en largeur (BFS) pour visiter tous les noeuds de l'arbre
void ArbreB::ParcourBFS()
{
    if (!this) return;  // Vérifier si l'arbre est vide
    queue<ArbreB*> file;  // Queue pour effectuer un parcours BFS
    file.push(this);  // Ajouter le noeud racine à la file

    while (!file.empty())
    {
        ArbreB* noeud = file.front();  // Récupérer le noeud courant
        file.pop();
        cout << noeud->getVal() << " ";  // Afficher la valeur du noeud courant

        // Ajouter les enfants du noeud à la file pour un prochain traitement
        if (noeud->getFgh() != nullptr) file.push(noeud->getFgh());
        if (noeud->getFdt() != nullptr) file.push(noeud->getFdt());
    }
    cout << endl;
}



// Recherche d'un noeud avec une valeur spécifique dans l'arbre en utilisant un parcours BFS
ArbreB* ArbreB::RechercheDsArbreBFS(int val)
{
    if (this == nullptr) return nullptr;  // Si l'arbre est vide, retourner nullptr

    queue<ArbreB*> file;  // Queue pour effectuer un parcours BFS
    file.push(this);  // Ajouter le noeud racine à la file

    while (!file.empty())
    {
        ArbreB* noeud = file.front();  // Récupérer le noeud courant
        file.pop();

        // Si le noeud courant a la valeur recherchée, le retourner
        if (noeud->getVal() == val)
        {
            cout << "Element " << val << " est trouve !" << endl;
            return noeud;
        }

        // Ajouter les enfants du noeud à la file pour un prochain traitement
        if (noeud->getFgh() != nullptr) file.push(noeud->getFgh());
        if (noeud->getFdt() != nullptr) file.push(noeud->getFdt());
    }

    // Si l'élément n'a pas été trouvé, afficher un message d'erreur
    cout << "Element " << val << " non trouve dans l'arbre." << endl;
    return nullptr;
}
