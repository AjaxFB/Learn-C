#include<stdio.h>
int main(){
int vetor[10];
char in;
int ponteiro,trash,t;
//init
ponteiro = 0;
while(scanf("%c",&in) != EOF){
if ( in > 47 && in < 58) {
vetor[ponteiro] = (int)in - 48; 
ponteiro++;
}
if(in == 'm'){//109
t = 0;
for(trash = ponteiro;trash > 0;trash--){
t += vetor[trash -1];
}
printf("Média: %i\n",t/ponteiro);
}
}
return 0;
}
