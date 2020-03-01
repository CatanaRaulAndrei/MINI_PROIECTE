#include <bits/stdc++.h>
using namespace std;
class Graf{
private:
    int numar_noduri, numar_muchii;
    int** matrice_adiacenta;
public:
    Graf(int numar_noduri,int numar_muchii);
    void inserare_muchie(int nod_inceput, int numar_muchii);
    void traversare_graf_BFS(int nod_inceput);
    void afisare_matrice_adiacenta();
};
// Matricea de adiaceanta initializata cu 0
Graf::Graf(int numar_noduri,int numar_muchii){

    this->numar_noduri = numar_noduri;
    this->numar_muchii = numar_muchii;
    matrice_adiacenta = new int*[numar_noduri];

    for(int linii=0; linii<numar_noduri;linii++){
        matrice_adiacenta[linii] = new int[numar_noduri];
        for(int coloane=0;coloane<numar_noduri;coloane++){
            matrice_adiacenta[linii][coloane]=0;
        }
    }
}

// Afisare Matrice de adiacenta
void Graf::afisare_matrice_adiacenta(){
    cout<<"Matrice de adiacenta"<<endl;
    for(int linii=0; linii<numar_noduri;linii++){
        for(int coloane=0;coloane<numar_noduri;coloane++){
            cout<<matrice_adiacenta[linii][coloane]<<" ";
        }
        cout<<"\n";
    }
}

// Adauga un nod nou in graf
void Graf::inserare_muchie(int nod_inceput, int numar_muchii){

    matrice_adiacenta[nod_inceput][numar_muchii]=1;
    matrice_adiacenta[numar_muchii][nod_inceput]=1;

}
// Traversare graf cu BFS
void Graf::traversare_graf_BFS(int nod_inceput){

    // Vizitam vectorul astfel incat nodul sa nu fie vizitati mai mult decat odata
    // Initializam nodul pe false pentru ca nici un nod nu este vizitat la inceput
    int nod_curent;
    vector<bool> vizitat(nod_inceput, false);
    vector<int> coada;
    coada.push_back(nod_inceput);
    // Marcheaza nodul de inceput ca vizitat
    vizitat[nod_inceput] = true;
    while(coada.empty()==0){
        nod_curent = coada[0];
        // Afisare nod curent
        cout<<nod_curent<<" ";
        coada.erase(coada.begin());
        for(int i=0;i<numar_noduri;i++){
            // Daca exita muchie intre noduri si nodul nu este vizitat
            if(matrice_adiacenta[nod_curent][i]==1 && vizitat[i]==0){
                // eliminam elementul vizitat din coada
                    coada. push_back(i);
                    vizitat[i]= true;

            }
        }
    }
}


int main(){
int numar_noduri, numar_muchii;
numar_noduri = 7;
numar_muchii = 6;
Graf g(numar_noduri,numar_muchii);
g.inserare_muchie(0,1);
g.inserare_muchie(0,2);
g.inserare_muchie(1,3);
g.inserare_muchie(1,4);
g.inserare_muchie(2,5);
g.inserare_muchie(2,6);
g.afisare_matrice_adiacenta();
cout<<"BFS"<<endl;
g.traversare_graf_BFS(0);

    return 0;
}
