#include <iostream>
#include <time.h>
#include <windows.h>
#include "Guerreiro.cpp"


using std::cout;
using std::cin;
using std::endl;

int main()
{
    Guerreiro Guarda;
    Boneco Boboneco;

    float sB,aB,rmB;

    
    Boboneco.getEstatisticas(sB,aB,rmB);
    int op=9;

    cout<<"Mestre das Masmorras: Vc encontra o meu velho boneco de treino, use-o para testar suas habilidades"<<endl;
     Sleep(3000);
    while(sB>0)
    {
        system("cls");
        Boboneco.imprimeStatus();
        cout<<endl;
        cout<<endl;

        Guarda.imprimeStatus();
        cout<<endl;
        cout<<endl;

        cout<<"Atacar:1"<<endl;
        cout<<"Habilidade:2"<<endl;
        cout<<"Item:3"<<endl;
        cout<<"Fugir:4"<<endl;
        cout<<endl;
       
        cin>>op;

        switch(op)
        {
            case 1: Guarda.atk(Boboneco);
            break;
        
        }

       Boboneco.getEstatisticas(sB,aB,rmB);
        Sleep(1500);
        

    }

    cout<<"Mestre das Masmorras: Hey! vc quebrou o meu boneco >:("<<endl;

       

    
    
    return 0;

}