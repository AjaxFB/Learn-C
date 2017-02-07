// Copyright 2014 Bruno D'Amato <?>
//libs
#include<stdio.h>
main(){
//inicialize variables
int stack[10];
int pointer = 0;
char in;
int trash,operand;
int length = sizeof(stack)/sizeof(stack[0]);

for(trash = 0;trash < 10;trash++){
stack[trash] = 0;
}
operand = 0;

//program
while(scanf("%c",&in) != EOF){
if(in > 47 && in < 58){
//    push it
stack[pointer] = (int)in - 48;//atoi and (int) dont convert
operand++;pointer++;
}else{
if(in == '+' || in == '-' || in == '*' || in == '/'){
/*
      pop operands
      do operation
      push result
*/
if(in == '+'){
if(operand == 0){
}else{
for(;operand > 1;operand--){
//printf("%i += %i\n",stack[pointer - 2],stack[pointer - 1]);
stack[pointer - 2] += stack[pointer - 1];//dont use =+
stack[pointer - 1] = 0;
pointer--;
}
}
}


printf("value:\t%i\n",stack[pointer]);

operand = 0;
}else{
if(in == '\n'){
//pop and print top of stack
for(trash = 0; trash < length;trash++){
printf("%c\t",stack[trash] + 48);
}
printf("\n");
}else{
printf("Error.\n");
}
}
}
}
return 0;
}
