#include <stdio.h>
#include <string.h>
#include<stdlib.h>



void init(int drink[][3]){
    for(int i = 0; i < 5; i++){
        drink[i][0] = 100; //total
    }

    drink[0][1] = 1000; // moneys
    drink[1][1] = 5000;
    drink[2][1] = 800;
    drink[3][1] = 2000;
    drink[4][1] = 2500;






}

void menu(int drink[][3], int money){

        printf("음료수 선택 창\n\n");
        printf("----------------------------------\n\n");
    
        printf("1. 맥콜 선택 (count: %d, moeny: %d)\n", drink[0][0], drink[0][1]);
        printf("2. 민트초코 선택 (count: %d, moeny: %d) \n", drink[1][0], drink[1][1]);
        printf("3. 마라맛 무언가 선택 (count: %d, moeny: %d) \n", drink[2][0], drink[2][1]);
        printf("4. 솔의 눈 선택 (count: %d, moeny: %d) \n", drink[3][0], drink[2][1]);
        printf("5. 펩시 제로 선택 (count: %d, moeny: %d) \n\n", drink[4][0], drink[4][1]);

        printf("----------------------------------(money : %d )\n\n", money);


        
}




int main (){
    int m = 0;
    int all[2] = {0,};
    int drink[5][3] = {0,};
    unsigned int pick;
    char *buf[10000] = {0, };
    init(&drink);
    FILE* fp1 = fopen("finish.txt","r"); 

    fgets( buf, sizeof( buf), fp1);
    char * temp = strtok(buf, " ");
    all[0] = atoi(temp);//printf("%s", temp);
    temp = strtok(NULL, " ");
    all[1] = atoi(temp);

    temp = strtok(NULL, " ");
    drink[0][0] = atoi(temp);
    temp = strtok(NULL, " ");
    drink[1][0] = atoi(temp);
    temp = strtok(NULL, " ");
    drink[2][0] = atoi(temp);
    temp = strtok(NULL, " ");
    drink[3][0] = atoi(temp);
    temp = strtok(NULL, " ");
    drink[4][0] = atoi(temp);

    fclose(fp1);


    //printf("%d %d %d", all[0], all[1]);



    

    while(1){
        printf("\n\n\n\n");
        printf("자판기 프로그램\n");
        printf("돈틀 투입하시겠습니다..?(종료 = -1)\n\n>>> ");
        scanf("%d", &m);
        if(m < 0)
            break;

        all[0] += m; //total input --> [0]
        menu(&drink, m);
        
        
        while(1){
            printf(">>> (1~5)");
            scanf("%u", &pick);
            if(pick <= 0 || pick > 5){
                continue;
            }else{
                break;
            }
        }
        pick -= 1;  

        if(m < drink[pick][1]){
            printf("Err: 투입된 돈이 부족합니다...\n");
            
            printf("반환 된 돈: %d \n", m);
            all[1] += 0; //earn 
            continue;

        }else if(drink[pick][0] < 1){
            printf("Err: 음료수가 부족합니다....\n");
            printf("반환 된 돈: %d \n", m);
            all[1] += 0; //earn 
            continue;




        }

        --drink[pick][0];
        m -= drink[pick][1];
        all[1] += drink[pick][1];
        printf("반환 된 돈: %d\n ", m);


        

    }
    FILE* fp = fopen("finish.txt","w"); 


    printf("자판기 최종 결산\n\n\n");

    menu(&drink, 0);
    printf("번돈:::%d\n", all[1]);
    printf("투입된 돈(total):::%d\n", all[0]);


    fprintf(fp, "%d %d %d %d %d %d %d %d %d %d", all[0], all[1], drink[0][0], drink[1][0],drink[2][0], drink[3][0], drink[4][0]); //문자열 입력

    fclose(fp);




    return 0;
}