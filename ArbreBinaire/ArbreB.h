#pragma once
#include<iostream>
#include<string>
#include <queue>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

// Définition de la classe ArbreB qui représente un arbre binaire
class ArbreB
{
private:
    int value;             // Valeur du noeud courant
    ArbreB* Fdt;          // Pointeur vers le fils droit
    ArbreB* Fgh;          // Pointeur vers le fils gauche

public:
    // Constructeur pour initialiser un noeud avec une valeur donnée
    ArbreB(int val);

    // Getter pour le fils droit (Fdt)
    ArbreB* getFdt();

    // Getter pour le fils gauche (Fgh)
    ArbreB* getFgh();

    // Getter pour la valeur du noeud
    int getVal();

    // Insérer une nouvelle valeur dans l'arbre binaire
    void InsertArbB(int val);

    // Supprimer un noeud avec une valeur spécifique de l'arbre
    bool SupprimerNoeud(int val);

    // Recherche un noeud avec une valeur spécifique dans l'arbre de manière récursive
    ArbreB* RechercheDsArbre(int val);

    // Parcours en largeur (BFS) pour visiter tous les noeuds de l'arbre
    void ParcourBFS();

    // Recherche un noeud avec une valeur spécifique dans l'arbre en utilisant BFS
    ArbreB* RechercheDsArbreBFS(int val);
};
