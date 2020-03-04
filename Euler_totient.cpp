#include <iostream>

using namespace std;

class Functia_PHI{
private:
    int n;
public:
    int PHI(int n);
    void Afisare_PHI(int numar_functii);
};

int Functia_PHI::PHI(int n){
    int rezultat = n;
    for(int p = 2 ; p*p < n; p++){
        if(n % p == 0){
            while(n % p){
                n = n/p;
            }
         rezultat = rezultat - rezultat/p;
        }
    }
    if(n > 1){
        rezultat = rezultat - rezultat/n;
    }

return rezultat;
}

void Functia_PHI::Afisare_PHI(int numar_functii){
    for (int i = 1; i <= numar_functii; i++){
        cout<<"phi["<<i<<"]="<<PHI(i)<<endl;
    }
}


int main(){
Functia_PHI obj;
obj.Afisare_PHI(10);// PHI(1)........numar_functii_de_phi
    return 0;
}
