#include <stdio.h>
#include <string.h>
int main(){

    int c = 0;
    char a[5] = {0, };



    double result = 0;
    int i = 0;
    while(1){
        
        printf("학점수를 입력해주세요. >> (입력 종료 = -1) ");

        scanf("%d", &c);
        if(c < 0){
            break;
        }
        i += c;
        printf("평점을 입력해주세요. >> ");
        scanf(" %4s", &a);
        double k = 0;
        if(!(strcmp(a, "A+"))){
            k = 4.5;
        }else if(!(strcmp(a, "A"))){
            k = 4.0;
        }else if(!(strcmp(a, "B+"))){
            k = 3.5;
        }else if(!(strcmp(a, "B"))){
            k = 3.0;
        }else if(!(strcmp(a, "C+"))){
            k = 2.5;
        }else if(!(strcmp(a, "C"))){
            k = 2.0;
        }else if(!(strcmp(a, "D+"))){
            k = 1.5;
        }else if(!(strcmp(a, "D"))){
            k = 1.0;
        }else if(!(strcmp(a, "F"))){
            k = 0.0;
        }

        
        result += c*(k);

        



    }


    result /=  i;
    

    printf("평균: %.2f\n", result);

    return 0;
}