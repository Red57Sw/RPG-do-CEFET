#include <iostream>
#include <time.h>
#include <windows.h>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Criatura{

    private:

    //Estatisticas basicas

    string nome;

    float sangue;
    float espirito;
    float armadura;
    float resMagica;
    float poderAtk;
    float poderMag;

    //poder dos dados

    int PdB;
    int brutalidade [19];
    int PdA;
    int agilidade [19];
    int PdS;
    int sagacidade [19];

    int dado;

    public:

    Criatura( string n,float s, float e, float a, float rm, float pa, float pm, int b, int ag,int sa)
    {
        setNome(n);
        setSangue(s);
        setEspirito(e);
        setArmadura(a);
        setResMagica(rm);
        setPoderAtk(pa);
        setPoderMag(pm);
        setDadoB(b);
        setDadoA(ag);
        setDadoS(sa);

        srand(time(NULL));

    }

    //metodos impressão

    void imprimeHeroi()
    {
        cout<<this->nome<<endl;
        cout<<endl;
        cout<<"Sangue: "<<this->sangue<<endl;
        cout<<"Espirito: "<<this->espirito<<endl;
        cout<<"Armadura: "<<this->armadura*100<<endl;
        cout<<"Resistencia Magica: "<<this->resMagica*100<<endl;
        cout<<"Poder Fisico: "<<this->poderAtk<<endl;
        cout<<"Poder Magico: "<<this->poderMag<<endl;
        cout<<"Brutalidade: "<<this->PdB<<endl;
        cout<<"Agilidade: "<<this->PdA<<endl;;
        cout<<"Sagacidade: "<<this->PdS<<endl;;
    
    }

    void imprimeMonstro()
    {
        cout<<this->nome<<endl;
        cout<<endl;
        cout<<"Sangue: "<<this->sangue<<endl;
        cout<<"Armadura: "<<this->armadura*100<<endl;
        cout<<"Resistencia Magica: "<<this->resMagica*100<<endl;
        cout<<"Poder Fisico: "<<this->poderAtk<<endl;
        cout<<"Poder Magico: "<<this->poderMag<<endl;
    }

    //metodos ataques e habilidades

    void atk(Criatura& destino)
    {
        float s,a,rm;
        float dano;

        getEstatisticas(s,a,rm);
        this->dado=rand()%19;
        cout<<"Role seu Dado da Brutalidade "<<nome<<endl;
        Sleep(1500);
        cout<<"Dado da Brutalidade: "<<dado+1<<endl;
        Sleep(1500);


        if(brutalidade[dado]==1)
        {
            dano=this->poderAtk*(1-a)+this->poderMag*(1-rm);
            destino.setDano(dano);
            cout<<nome<<" fere "<<destino.nome<<" causando "<< dano <<" de dano"<<endl;
        }
        else
        {
            if(brutalidade[dado]==2)
            {
                dano=(this->poderAtk*(1-a)+this->poderMag*(1-rm))*2;
                destino.setDano(dano);
                cout<<nome<<" fere gravimente "<<destino.nome<<" causando "<< dano <<" de dano"<<endl;
            }
            else
            {
                if(brutalidade[dado]==0)
                {
                   
                    cout<<nome<<" erra seu golpe contra "<<destino.nome<<endl;
                }
            }
        }


    }




    //gets e sets

    void setNome(string n)
    {
        this->nome=n;
    }
    

    void setSangue(float s)
    {
        this->sangue=s;
    }

    void setEspirito(float e)
    {
        this->espirito=e;
    }

    void setArmadura(float a)
    {
        this->armadura=a;
    }

    void setResMagica(float rm)
    {
        this->resMagica=rm;
    }

    void setPoderAtk(float pa)
    {
        this->poderAtk=pa;
    }

    void setPoderMag(float pm)
    {
        this->poderMag=pm;
    }

    void setDadoB(int b)
    {
        if(b==3)
        {
            for(int i=0;i<4;i++)
            {
                this->brutalidade[i]=0;
            }

            for(int i=4; i<17;i++)
            {
                this->brutalidade[i]=1;
            }

            for(int i=17; i<20;i++)
            {
                this->brutalidade[i]=2;
            }

            this->PdB=3;

        }
        if(b==2)
        {
            for(int i=0;i<8;i++)
            {
                this->brutalidade[i]=0;
            }

            for(int i=8; i<17;i++)
            {
                this->brutalidade[i]=1;
            }

            for(int i=17; i<20;i++)
            {
                this->brutalidade[i]=2;
            }

            this->PdB=2;
        }
        if(b==1)
        {
            for(int i=0;i<12;i++)
            {
                this->brutalidade[i]=0;
            }

            for(int i=12; i<17;i++)
            {
                this->brutalidade[i]=1;
            }

            for(int i=17; i<20;i++)
            {
                this->brutalidade[i]=2;
            }

            this->PdB=1;
        }
    }

     void setDadoA(int a)
    {
        if(a==3)
        {
            for(int i=0;i<4;i++)
            {
                this->agilidade[i]=0;
            }

            for(int i=4; i<17;i++)
            {
                this->agilidade[i]=1;
            }

            for(int i=17; i<20;i++)
            {
                this->agilidade[i]=2;
            }

            this->PdA=3;

        }
        if(a==2)
        {
            for(int i=0;i<8;i++)
            {
                this->agilidade[i]=0;
            }

            for(int i=8; i<17;i++)
            {
                this->agilidade[i]=1;
            }

            for(int i=17; i<20;i++)
            {
                this->agilidade[i]=2;
            }

            this->PdA=2;
        }
        if(a==1)
        {
            for(int i=0;i<12;i++)
            {
                this->agilidade[i]=0;
            }

            for(int i=12; i<17;i++)
            {
                this->agilidade[i]=1;
            }

            for(int i=17; i<20;i++)
            {
                this->agilidade[i]=2;
            }

            this->PdA=1;
        }
    }

     void setDadoS(int s)
    {
        if(s==3)
        {
            for(int i=0;i<4;i++)
            {
                this->sagacidade[i]=0;
            }

            for(int i=4; i<17;i++)
            {
                this->sagacidade[i]=1;
            }

            for(int i=17; i<20;i++)
            {
                this->sagacidade[i]=2;
            }

            this->PdS=3;

        }
        if(s==2)
        {
            for(int i=0;i<8;i++)
            {
                this->sagacidade[i]=0;
            }

            for(int i=8; i<17;i++)
            {
                this->sagacidade[i]=1;
            }

            for(int i=17; i<20;i++)
            {
                this->sagacidade[i]=2;
            }

            this->PdS=2;
        }
        if(s==1)
        {
            for(int i=0;i<12;i++)
            {
                this->sagacidade[i]=0;
            }

            for(int i=12; i<17;i++)
            {
                this->sagacidade[i]=1;
            }

            for(int i=17; i<20;i++)
            {
                this->sagacidade[i]=2;
            }

            this->PdS=1;
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

int main()
{
    int op=0;

    float sG,aG,rmG;
    float sB,aB,rmB;

    Criatura Guerreiro("Guerreiro",250,150,0.6,0.6,85,0,3,2,1),Boneco("Boneco",350,0,0.3,0.3,15000,30,3,3,2);

    

    Guerreiro.getEstatisticas(sG,aG,rmG);
    Boneco.getEstatisticas(sB,aB,rmB);

    while(sB>0&&sG>0)
    {
        if(sG>0)
        {
            cout<<"É SUA VEZ GUERREIRO"<<endl;
        Sleep(2500);
        system("cls");
        Boneco.imprimeMonstro();
        cout<<endl;
        cout<<endl;
        Guerreiro.imprimeHeroi();
        cout<<endl;
        cout<<endl;
        cout<<"Acao"<<endl;
        cout<<endl;
        cout<<"Atacar:1"<<endl;
        cin>>op;
        cout<<endl;

        switch(op)
        {
            case 1: Guerreiro.atk(Boneco);
            break;
        }

        Boneco.getEstatisticas(sB,aB,rmB);
         Sleep(1500);
        system("cls");
        }
        

       

        if(sB>0)
        {
            cout<<"É SUA VEZ BONECO"<<endl;
        Sleep(2500);
        system("cls");

        Boneco.imprimeMonstro();
        cout<<endl;
        cout<<endl;
        Guerreiro.imprimeHeroi();
        cout<<endl;
        cout<<endl;

        Boneco.atk(Guerreiro);

        Guerreiro.getEstatisticas(sG,aG,rmG);
        Sleep(1500);
        system("cls");
 
        }

        
        

    }

    cout<<"fim de jogo"<<endl;


}