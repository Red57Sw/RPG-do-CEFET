#include <iostream>
#include <time.h>
#include <windows.h>
#include "Boneco.cpp"


using std::cout;
using std::cin;
using std::endl;

class Guerreiro{

    private:

    //estatus basicos

    
    float sangue;
    float lixo;
    float espirito;
    float armadura;
    float resMagica;
    float poderAtk;
    float poderMag;

    //poder dos dados

    int brutalidadeG [12];
    int agilidadeG [10];
    int sagacidadeG [8];

    int dadoG;

    public:

    Guerreiro(){

        this->lixo=0;
        this->sangue=250;
        this->espirito= 150;
        this->armadura= 0.6;
        this->resMagica= 0.6;
        this->poderAtk= 50;
        this->poderMag= 10;

       //inicialização dos dados

       for(int i=0; i<12;i++)
       {
         this->brutalidadeG [i]= i+9;
       }

       for(int i=0; i<10; i++)
       {
         this->agilidadeG [i]=i+11;
       }

       for(int i=0; i<10; i++)
       {
         this->sagacidadeG [i]=i+13;
       }

       srand(time(NULL));


    }

    void imprimeStatus()
    {
        cout<<"Guerreiro"<<endl;
        cout<<endl;
        cout<<"Sangue: "<<this->sangue<<endl;
        cout<<"Espirito: "<<this->espirito<<endl;
        cout<<"Poder Fisico: "<<this->poderAtk<<endl;
        cout<<"Poder Magico: "<<this->poderMag<<endl;
        cout<<"Armadura: "<<this->armadura*100<<endl;
        cout<<"Resistencia Magica: "<< this->resMagica*100<<endl;
        cout<<"Brutalidade: 3"<<endl;
        cout<<"Agilidade: 2"<<endl;
        cout<<"Sagacidade: 1"<<endl;
    }

    int turnoG()
    {
        this->dadoG=rand()%20 +1;
         cout<<"D20A: "<<this->dadoG<<endl;

         return this->dadoG;
    }
   
    void atk (Boneco& destino)
    {
        int x=0,y=0,z=0;
        float s,a,rm;
        float dano;

        destino.getEstatisticas(s,a,rm);

       this->dadoG=rand()%20 +1;
       cout<<"D20B: "<<this->dadoG<<endl;
        
        for(int i=0; i<12; i++)
        {
            if(this->dadoG==this->brutalidadeG[i]&&this->dadoG!=20&&this->dadoG!=19&&this->dadoG!=18)
            {
                x=1;
            }
            else
            {
                if(this->dadoG==20||this->dadoG==19||this->dadoG==18)
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
            cout<<"O GUERREIRO fere a criatura, causando "<< dano<<" de dano fisico"<<endl;//precisa fazer o guerreiro causar dano a um monstro escolhido
        }

        if (y==1)
        {
            dano=(this->poderAtk*2)*(1-a);
            destino.setDano(dano);
            cout<<"O GUERREIRO fere gravimente a criatura, causando "<<dano<<" de dano fisico"<<endl;
        }

        if (x==0&&y==0&&z==1)
        {
        cout<<"O GUERREIRO erra seu golpe"<<endl;
        }

    }

    

    void getEstatisticas(float& s,float& a, float& rm)
    {
        s=this->sangue;
        a=this->armadura;
        rm=this->resMagica;
    }

     void setDano(float& dano)
    {
        this->sangue=sangue-dano;
    }




};