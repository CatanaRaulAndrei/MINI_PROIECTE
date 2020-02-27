#include <bits/stdc++.h>
using namespace std;
class Graf{
private:
    int numar_noduri, numar_muchii;
    int** matrice_adiacenta;
public:
    Graf(int numar_noduri,int numar_muchii);
    void inserare_muchie(int nod_inceput, int numar_muchii);
    void traversare_graf_DFS(int nod_inceput, vector<bool>& vizitat);
    void afisare_matrice_adaicenta();
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
void Graf::afisare_matrice_adaicenta(){
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
// Traversare graf cu DFS
void Graf::traversare_graf_DFS(int nod_inceput, vector<bool>& vizitat){

    // Afiseaza nodul curent
    cout<<nod_inceput<<" ";
    // Marcheaza nodul curent ca vizitat
    vizitat[nod_inceput]=true;

    for(int i=0;i<numar_noduri;i++){
        // Daca este vreun nod adiacent cu nodul curent si nu a fost vizitat inca
        if(matrice_adiacenta[nod_inceput][i]==1 && vizitat[i]==false){
           traversare_graf_DFS(i,vizitat);
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

vector<bool> vizitat(numar_noduri, false);
g.afisare_matrice_adaicenta();
 cout<<"DFS"<<endl;
g.traversare_graf_DFS(0,vizitat);

    return 0;
}
