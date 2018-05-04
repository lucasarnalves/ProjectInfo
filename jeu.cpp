#include "jeu.h"

Jeu::Jeu()
{

}

void Jeu::Init(){

    // Ajouter les briques
    for (int i=1;i<=10;i++){
        for(int j=1;j<=5;j++){
            v_Brique.push_back(new Brique(-55+10*i,32-3.5*j));
        }
    }
    // Ajouter le palet
    Palet_=new Palet(0);
    // Ajouter le boule
    Boule_=new Boule(0,-26,(rand() % 120)+30);
    // Ajouter le mur
    Mur_=new Mur(50,30);
    // Inicialize le Score et Etat
    Score_=0;
    Vie_=2;
    Nivel_=1;
    FinPartie=FALSE;

}


void Jeu::MovePalet(float Pos){
    Palet_->UpdatePos(Pos);
}

void Jeu::Display(){
    Palet_->Display();
    Boule_->Display();
    Mur_->Display();
    for(Brique * it : v_Brique) it->Display();
}

void Jeu::Joue(){
    int count=0;
    if(Mur_->VerifieBas(Boule_->GetY())) VerifiEtat();
    Boule_->SetAngle(Palet_->InteractPalet(Boule_->GetX(),Boule_->GetY(),Boule_->GetAngle())); //Verifie si le boule hit palet
    for(Brique * it : v_Brique) Boule_->SetAngle(it->InteractBrique(Boule_->GetX(),Boule_->GetY(),Boule_->GetAngle()));
    Boule_->SetAngle(Mur_->InteractMur(Boule_->GetX(),Boule_->GetY(),Boule_->GetAngle())); //Verifie si le boule hit le mur
    Boule_->Update();
    for(Brique * it : v_Brique) if(!it->GetEtat())count++;
    Score_=count;
    if(Score_==v_Brique.size()) NextLvl();
}

void Jeu::VerifiEtat(){
    if(Vie_>0){
        delete Boule_;
        Boule_=new Boule(0,-26.5,(rand() % 120)+30);// Depart aleatoire entre 30 a 150 degrées
        Boule_->SetVitese(1+(Nivel_-1)*0.5);
        Vie_-=1;
    }
    else FinPartie=TRUE;
}

void Jeu::NextLvl()
{
    Nivel_+=1;
    delete Boule_;
    Boule_=new Boule(0,-26.5,(rand() % 120)+30);
    Boule_->SetVitese(1+(Nivel_-1)*0.5);
    int colum=5+(rand() % 3);
    for (int i=1;i<=10;i++){
        for(int j=1;j<=colum;j++){
            v_Brique.push_back(new Brique(-55+10*i,32-3.5*j));
        }
    }
}

void Jeu::Restart()
{
    delete Boule_;
    delete Mur_;
    delete Palet_;
    v_Brique.clear();
    Init();
}


int Jeu::GetScore(){
    return Score_;
}
int Jeu::GetVie(){
    return Vie_;
}

int Jeu::GetNivel()
{
return Nivel_;
}

bool Jeu::GetEtat()
{
    return FinPartie;
}
