#include <iostream>
#include <time.h>
#include <windows.h>
//#include "Guerreiro.cpp"

using std::cout;
using std::cin;
using std::endl;

class Boneco{

    private:

    //estatus basicos

    float sangueMonstruoso;
    float armadura;
    float resMagica;
    float poderAtk;
    float poderMag;

    //poder dos dados

    int brutalidadeB [12];
    int agilidadeB [10];
    int sagacidadeB [8];

    int dadoB;

    public:

    Boneco(){

        this->sangueMonstruoso= 250;
        this->armadura= 0.4;
        this->resMagica= 0.4;
        this->poderAtk= 50;
        this->poderMag= 10;

       //inicialização dos dados

       for(int i=0; i<12;i++)
       {
         this->brutalidadeB [i]= i+9;
       }

       for(int i=0; i<10; i++)
       {
         this->agilidadeB [i]=i+11;
       }

       for(int i=0; i<10; i++)
       {
         this->sagacidadeB [i]=i+13;
       }

       srand(time(NULL));


    }

    void imprimeStatus()
    {
        cout<<"Boboneco"<<endl;
        cout<<endl;
        cout<<"Sangue: "<<this->sangueMonstruoso<<endl;
        cout<<"Poder Fisico: "<<this->poderAtk<<endl;
        cout<<"Poder Magico: "<<this->poderMag<<endl;
        cout<<"Armadura: "<<this->armadura*100<<endl;
        cout<<"Resistencia Magica: "<< this->resMagica*100<<endl;
    }

    int turnoB()
    {
        this->dadoB=rand()%20 +1;
         cout<<"D20A: "<<this->dadoB<<endl;

         return this->dadoB;
    }
  
    /*void atk (Guerreiro& destino)
    {
        int x=0,y=0,z=0;
        float s,a,rm;
        float dano;

        destino.getEstatisticas(s,a,rm);

       this->dadoB=rand()%20 +1;
       cout<<"D20B: "<<this->dadoB<<endl;
        
        for(int i=0; i<12; i++)
        {
            if(this->dadoB==this->brutalidadeB[i]&&this->dadoB!=20&&this->dadoB!=19&&this->dadoB!=18)
            {
                x=1;
            }
            else
            {
                if(this->dadoB==20||this->dadoB==19||this->dadoB==18)
                {
                    y=1;
                }
                 else
                 {
                      z=1;
                 }
            } 
  
        } 

        if (x==1)
        {
            dano=this->poderAtk*(1-a);
            destino.setDano(dano);
            cout<<"O Boboneco golpeia o GUERREIRO, causando "<< dano<<" de dano fisico"<<endl;//precisa fazer o guerreiro causar dano a um monstro escolhido
        }

        if (y==1)
        {
            dano=(this->poderAtk*2)*(1-a);
            destino.setDano(dano);
            cout<<"O Boboneco golpeia violentamente o GUERREIRO, causando "<<dano<<" de dano fisico"<<endl;
        }

        if (x==0&&y==0&&z==1)
        {
        cout<<"O boboneco erra seu golpe"<<endl;
        }

    }
    */
    

    void getEstatisticas(float& s, float& a, float& rm)
    {
        s=this->sangueMonstruoso;
        a=this->armadura;
        rm=this->resMagica;
    }

    void setDano(float& dano)
    {
        this->sangueMonstruoso=sangueMonstruoso-dano;
    }

};