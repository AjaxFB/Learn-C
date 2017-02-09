//#include <iostream>//cin
#include<stdio.h>//printf
#include<string>//string
#include<vector>
//############################################
using namespace std;
//############################################
//###############Global Functions and var
//############################################
vector<string> escala;//C C#/Db...
char notas[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C'};
vector<string> tons;//dim m M aum
char semitom[] = {'b', '\0', '#'};
//############################################

void make_escala(){

//############################################
//###########Inicia Programa produzindo vetor escala
//############################################


string str = "";
//printf("\nPrograma iniciado..%s..\n",str.c_str());
//str = "";
//cin >> str;

//scanf("%*s",&str);
//scanf nao funciona com string
//printf("String:%s\n",str.c_str());

for(int semi = 0;semi < 1;semi++){
for(int nota  = 0;nota < 8;nota++){//{'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C'};
for(int x  = 0;x < 3;x++){//{'b', '\0', '#'};
//printf("nota:%i:\n",nota); monitor
//if(!(notas[nota] == 'E' && semitom[x] == '#') ou Fb ou B# ou Cb ou Cb_inicial){ logica explicada
if( !( 
(nota == 2 && x == 2) || //E#
(nota == 3 && x == 0) || //Fb
(nota == 6 && x == 2) || //B#
(nota == 7 && x == 0) || //C_finalb
(nota == 0 && x == 0) || //Cb inicial
(nota == 7 && x == 2) //C_final#(para no adiantar nota no existente e gerar erro) 
) ){
str = "";
//printf("%c",notas[nota]);
//cout<<semitom[x];

str += notas[nota];str += semitom[x];

if( (x == 2 && ((nota+1 != 3) || (nota+1 != 7)) ) ){
//se nota atual tiver sustenido(#) e a nota da frente tiver bemol(F ou C_final)
//C_final# vai querer adiantar//if(nota++ == 8){break;}
nota++;x = 0;//adianta nota
//cout<<"/"<<notas[nota]<<semitom[x]<<" \n";

str += "/";
str += notas[nota];
str += semitom[x];

}else{
//cout<<"\n";
}
///////////////insere no vetor
escala.push_back(str);
}
}
//printf("\n");//separa as notas
}
}

}

//############################################
void imprimi_esc(int pon,char scale){
//7 modos gregos
int maior[] = {0,2,2,1,2,2,2,1};//jonico
int dorico[] = {0,2,1,2,2,2,1,2};
int frigio[] = {0,1,2,2,2,1,2,2};
int lidio[] =  {0,2,2,2,1,2,2,1};
int mixolidio[] = {0,2,2,1,2,2,1,2};
int menor[] = {0,2,1,2,2,1,2,2};//eolico
int locrio[] = {0,1,2,2,1,2,2,2};
int pentatonicaM[] = {0,2,2,3,2,3};//est dentro do jonico sem as notas sem bemols
int pentatonicam[] = {0,3,2,2,3,2};//dentro do menor eolico
int pentaBlues[] = {0,3,2,1,1,3,2};//3 2 1*(blue note 5dim) - alteraço pentam

int pont = pon;
switch(scale){

case 'm':
printf("\nImprimindo escala menor %s...\n",escala[pon].c_str());
for(int x  = 0;x < 8;x++){
printf("%i\t",menor[x]);
}printf("\n");
for(int x  = 0;x < 8;x++){
pont = (pont + menor[x])%12;
printf("%s\t",escala[pont].c_str());

}printf("\n");
break;
case 'M':

printf("\nImprimindo escala maior %s...\n",escala[pon].c_str());
for(int x  = 0;x < 8;x++){
printf("%i\t",maior[x]);
}printf("\n");
for(int x  = 0;x < 8;x++){
pont = (pont + maior[x])%12;
printf("%s\t",escala[pont].c_str());
}printf("\n");
break;
default:
printf("\nNot found char scale equivalent:%c\n",scale);break;
}
}
//############################################
void escalas(string note,char scale){

bool ok = false;
for(int x = 0;x < 12 && ok == false ;x++){
//printf("\n%s == %s ?\n",escala[x].c_str(),note.c_str());
if(escala[x].c_str() == note){
imprimi_esc(x,scale);
ok = true;
}
}
if(ok == false){
printf("\nNot found char note equivalent:%s\n",note.c_str());
}


}
//############################################
int main() {

//############################################
//###########Inicia Variiveis e vetores - Construtor
//############################################
//vetor global notas
for(int x  = 0;x < 8;x++){
printf(":%c: ",notas[x]);
}
printf("\n");
//############################################
//vetor gloval semitom
for(int x  = 0;x < 3;x++){
printf(":%c: ",semitom[x]);
}
printf("\n");
//############################################
//vetor global tons
tons.push_back("dim");
tons.push_back("m");
tons.push_back("M");
tons.push_back("aum");// = {"dim", "m", "M", "aum"};
//vector< && {"", (space)""}

for(int x  = 0;x < 4;x++){
printf(":%s: ",tons[x].c_str()); //outra formataço de impresso
}
printf("\n");
//############################################

make_escala();

//############################################
//###########Imprimindo escala cromtica
//############################################
//printf("\nImprimindo escala cromtica...\n");
for(int x  = 0;x < escala.size();x++){
//printf("%i:\t%s\n",x+1,escala[x].c_str());
printf(":%s ",escala[x].c_str());
}
printf("\n");
//############################################

/*escalas("C",'M');//note,scala(M or m)
escalas("C",'m');
escalas("C#/Db",'M');
escalas("D",'M');
escalas("H",'M');
escalas("D",'H');*/

/*for(int x = 0;x < 12;x++){
escalas(escala[x].c_str(),'M');
}
for(int x = 0;x < 12;x++){
escalas(escala[x].c_str(),'m');
}*/

return 0;
}


/* LIXO
//############################################
//###########Imprimindo escala maior de C
//############################################
int maior[] = {0,2,2,1,2,2,2,1};
int pont = 0;
printf("\nImprimindo escala maior C...\n");
for(int x  = 0;x < 8;x++){
cout<<maior[x]<<"\t";
}printf("\n");
for(int x  = 0;x < 8;x++){
pont = pont + maior[x];
cout<<escala[pont]<<"\t";
}printf("\n");
//############################################
//###########Imprimindo escala maior de D
//############################################
//int maior[] = {0,2,2,1,2,2,2,1};
pont = 2;
printf("\nImprimindo escala maior D...\n");
for(int x  = 0;x < 8;x++){
cout<<maior[x]<<"\t";
}printf("\n");
for(int x  = 0;x < 8;x++){
pont = (pont + maior[x])%12;
cout<<escala[pont]<<"\t";
}printf("\n");
//############################################
//###########Imprimindo escala menor de C
//############################################
int menor[] = {0,2,1,2,2,1,2,2};
pont = 0;
printf("\nImprimindo escala menor C...\n");
for(int x  = 0;x < 8;x++){
cout<<menor[x]<<"\t";
}printf("\n");
for(int x  = 0;x < 8;x++){
pont = pont + menor[x];
cout<<escala[pont]<<"\t";
}printf("\n");
*/

/*switch( string(note) ){
case "C":
imprimi_esc(0,scale);break;
case "D":
imprimi_esc(2,scale);break;
case "E":
imprimi_esc(4,scale);break;
case "F":
imprimi_esc(5,scale);break;
case "G":
imprimi_esc(7,scale);break;
case "A":
imprimi_esc(9,scale);break;
case "B":
imprimi_esc(11,scale);break;

default:
cout<<"\nNot found char note equivalent:"<<note<<"\n";
break;
}*/
