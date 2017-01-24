//en marche
//fichier modifier
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

struct data  {

  int taille;
  double **tab;
  int  ** dist;

};

using namespace std;
  
int main(){

  data var;
 
 
  
  var.tab=new double *[var.taille];
  string nomfic;

  cout<<"Donner le nom du fichier "<<endl;
  cin>>nomfic;

  ifstream  fil(nomfic.c_str());
  fil>>var.taille>>ws;
  cout<<"la taille du fichier est :"<<var.taille<<endl;
  int col;
  fil>>col>>ws;
  cout<<"Nombre de colonne :"<<col<<endl;
  
  //l'allocation dynamique 
  for(int i=0; i<var.taille; i++){
    var.tab[i]=new double [2] ;
    
  }
  
   for(int i=0;i<var.taille; i++){
     
      for(int j=0;j<2;j++){
	
	fil >>var.tab[i][j]>>ws;
      }
   }
   
for(int i=0;i<var.taille;i++){
 
      for(int j=0;j<2;j++){
	
	cout<<var.tab[i][j]<<" ";
      }
      cout<<endl;
   }
fil.close();

//le calcul des distances
 
double distCordx=0,distCordy=0;

 var.dist=new int *[var.taille];
 
for (int i=0;i<var.taille;i++){
 var.dist[i]=new int[var.taille] ;
 }

 int X,Y;

 for (int i=0;i<var.taille;i++){
   for(int j=0;j<var.taille;j++){
    
     
     distCordx=var.tab[j][0]-var.tab[i][0];
     cout<<"dist x:"<<distCordx<<endl;
     
     distCordy=var.tab[j][1]-var.tab[i][1];
     cout<<"dist y:"<<distCordy<<endl;
     X=(int)(distCordx*distCordx);
     Y=(int)(distCordy*distCordy);
     var.dist[i][j]=(int)(sqrt(X+Y)+0.5);

    
   cout<<" la distance depuis la ville i vers la j est : "<<var.dist[i][j] <<endl;
   
 }
 }
 cout<<endl;
 cout<<"les distances entre les villes sont données par la matrice suivante :"<<endl;
 
 for (int i=0;i<var.taille ;i++){
   for(int j=0;j<var.taille ;j++){
     
     cout<<var.dist[i][j]<<"  ";
   
   }
    cout<<endl;
 }

 //trouver le plus court chemin entre les villes 
 int Vdep;
 cout<<"ville de depart :" ;
 cin>>Vdep ;
 
 int* villeEvite;
 
 villeEvite =new int[var.taille];

 
 int chemin=0;

bool existe=false;		
long int min=1e10;
villeEvite[0]=Vdep;
int l=0;

int pos=0;
int k=0;
 for(int i=0;i<var.taille-1;i++){
	for(int j=0;j<var.taille;j++){
	 
		while(( existe==false ) && (k<=l)){
		  
			if(j==villeEvite[k]){
				existe=true;
				
			}
			k++;
		}
		k=0;
		
		if(existe==false){
		  

		  if((min>var.dist[Vdep][j])&&(min!=0)){
				min= var.dist[Vdep][j];
				pos=j;}
			
			}else{ 
				existe=false;}
				
}

    
   chemin+=min;
   cout<<"le chemin est "<<chemin<<endl;
   Vdep=pos;
   l++;
   villeEvite[l]=Vdep;


min=1e10;
}
 cout<<"le chemin est "<<chemin<<endl;
 //cela permet d'afficher les villes parcourus depuis la plus petite distance 
 
 	for(int j=0;j<var.taille;j++){

	  cout<< villeEvite[j]  <<" ";
}

//liberation de la mémoire
 for (int i=0;i<var.taille ;i++){
  
    delete [] var.dist[i];
   }
   delete [] var.dist;

 
return 0;

}

