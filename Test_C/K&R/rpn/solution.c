// Copyright 2014 Bruno D'Amato <?>
//libs
#include<stdio.h>

    //inicialize variables
    int stack[10];
    int pointer = 0;
    char in ;
    int trash, operand;
    int length = sizeof(stack) / sizeof(stack[0]);

void operator_all(char in_c){
for (; pointer > 1; pointer--) {
	if(in_c == '+'){
		//problem on this line
		//printf("%i += %i\n",stack[pointer - 2],stack[pointer - 1]);
		//stack[pointer - 2] = stack[pointer - 2] + stack[pointer - 1]; //dont use =+
		stack[pointer - 2] += stack[pointer - 1]; //dont use =+
	}else{
		if(in_c == '-'){
			stack[pointer - 2] -= stack[pointer - 1]; //dont use =+
		}else{
				if(in_c == '*'){
					stack[pointer - 2] *= stack[pointer - 1]; //dont use =+
				}else{
					stack[pointer - 2] /= stack[pointer - 1]; //dont use =+
				}
		}
	}
    stack[pointer - 1] = 0;
    pointer--;
}
pointer = 1;


}

void operand_all(char in_o){
    for (; operand > 1; operand--) {
	if(in_o == '+'){
		stack[pointer - 2] += stack[pointer - 1]; //dont use =+
	}else{
		if(in_o == '-'){
			stack[pointer - 2] -= stack[pointer - 1]; //dont use =+
		}else{
				if(in_o == '*'){
					stack[pointer - 2] *= stack[pointer - 1]; //dont use =+
				}else{
					stack[pointer - 2] /= stack[pointer - 1]; //dont use =+
				}
		}
	}
    stack[pointer - 1] = 0;
    pointer--;
    }
}

int main() {


    for (trash = 0; trash < 10; trash++) {
      stack[trash] = 0;
    }
    operand = 0;

    //program
    while (scanf("%c", & in ) != EOF) {
      if ( in > 47 && in < 58) {
        //    push it
        stack[pointer] = (int) in -48; //atoi and (int) dont convert
        operand++;
        pointer++;
	printf("number:pointer: %i operator: %i\n", pointer,operand);
      } else {
        if ( in == '+' || in == '-' || in == '*' || in == '/') {
          /*
                pop operands
                do operation
                push result
          */
          if ( in == '+') {
            if (operand == 0) {
				operator_all(in);
            } else {
              operand_all(in);
            }
          }
          if ( in == '*') {
            if (operand == 0) {
				operator_all(in);
            } else {
              operand_all(in);
            }
          }
          if ( in == '/') {
            if (operand == 0) {
				operator_all(in);
            } else {
              for (; operand > 1; operand--) {
                operand_all(in);
              }
            }
          }
          if ( in == '-') {
            if (operand == 0) {
				operator_all(in);
            } else {
				operand_all(in);
            }
          }
          operand = 0;
          printf("operator:pointer: %i operator: %i\n", pointer,operand);
        } else {
          if ( in == '\n') {
            //pop and print top of stack
            for (trash = 0; trash < length; trash++) {
              printf("%i\t", stack[trash]);
            }
            printf("\n");
			printf("line break:pointer: %i operator: %i\n", pointer,operand);
          } else {
            printf("Error.\n");
          }
        }
      }
    }
    return 0;
  }
