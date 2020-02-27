#include <iostream>
#include <limits.h>
#define Numar_noduri_graf 9
#define infinit INT_MAX
using namespace std;
// returneaza indicele nodului cu distanta minima
int Nod_Distanta_Minima(int distanta_minima[], bool nod_vizitat[]){
    int minim=infinit, indice_minim;
    for(int v=0;i<Numar_noduri_graf;v++){
        if(nod_vizitat[v]==false && distanta_minima[v]<= minim){
            minim=distanta_minima[v];
            indice_minim=v;
        }
    }

    return indice_minim;
}
// afiseaza calea minima, fara nodul sursa
void Afisare_Cale(int lista_noduri_parinte[],int nod_tinta){
    if(lista_noduri_parinte[nod_tinta]==-1){
        return;
    }
    Afisare_Cale(lista_noduri_parinte,lista_noduri_parinte[nod_tinta]);
    cout<<nod_tinta<<" ";
}
// afiseaza nodul sursa si nodul tinta, distanta minima si calea minima cu nodul sursa
void Afisare_Solutie(int distanta_minima[], int NumarNoduriGraf,int lista_noduri_parinte[]){
    int nod_sursa=0;
    cout<<"Nod\t\tDistanta\tCale";
    for(int i=0;i<NumarNoduriGraf;i++){
        cout<<"\n"<<nod_sursa<<"->"<<i<<"\t\t"<<distanta_minima[i]<<"\t\t"<<nod_sursa<<" ";
        Afisare_Cale(lista_noduri_parinte,i);
    }
}
// Algoritmul Dijkstra care ne ofera calea cea mai scurta dintre un nod sursa si unul destinatie
void Dijkstra(int Graf[Numar_noduri_graf][Numar_noduri_graf], int nod_sursa){
    int distanta_minima[Numar_noduri_graf];
    bool nod_vizitat[Numar_noduri_graf];
    int lista_noduri_parinte[Numar_noduri_graf];
    for (int i=0;i<Numar_noduri_graf;i++){
         lista_noduri_parinte[0]=-1;
         distanta_minima[i]=infinit;
         nod_vizitat[i]=false;
    }
    distanta_minima[nod_sursa]=0;
    for(int i=0;i<Numar_noduri_graf-1;i++){
        int u = Nod_Distanta_Minima(distanta_minima, nod_vizitat);
        nod_vizitat[u]= true;
        for(int v=0;v<Numar_noduri_graf;v++){
            if(nod_vizitat[v]==false && Graf[u][v]!=0 && distanta_minima[u]+Graf[u][v]<distanta_minima[v]){
                lista_noduri_parinte[v]=u;
                distanta_minima[v]=distanta_minima[u]+Graf[u][v];
            }
        }
    }
    Afisare_Solutie(distanta_minima,Numar_noduri_graf,lista_noduri_parinte);
}

int main(){

    int nod_sursa=0;
    int Graf[Numar_noduri_graf][Numar_noduri_graf]={
                                {0, 4, 0, 0, 0, 0, 0, 8, 0},
                                {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                {0, 0, 4, 0, 10, 0, 2, 0, 0},
                                {0, 0, 0, 14, 0, 2, 0, 1, 6},
                                {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                {0, 0, 2, 0, 0, 0, 6, 7, 0}

};
    Dijkstra(Graf,nod_sursa);
    return 0;
}
