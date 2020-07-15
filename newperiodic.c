#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

struct element
{
    char name[20];
    char symbol[3];
    int atomicnum;
    char type[20]; //metal,metalloid,non metal
    char block;    //s,p,d,f....
    int electrons; //no of electrons
    int neutrons; //no of neutrons
    int protons; // no of protons
    float atomicwt; // atomic weight of the element
} atom[118];



extern void table()
{
FILE *fp;
    char ch;
    char  line[4096];
    char *token;
    int tokenposition=0;
    int lineposition=0;
    fp=fopen("elementDetails.txt","r");
    while(fgets(line,4096,fp) !=NULL) {
        tokenposition=0;
       // printf("%s \n",line);
        token = strtok(line,","); //
        while(token != NULL){
            switch(tokenposition) {
                case 0:
                    for(int x=0; x<strlen(token); x++){
                        token[x]=tolower(token[x]);
                    }
                    strcpy(atom[lineposition].name,token);
                    break;
                case 1:
                    strcpy(atom[lineposition].symbol,token);
                    break;
                case 2:
                    atom[lineposition].atomicnum =atoi(token);
                    break;
                case 3:
                    atom[lineposition].atomicwt=atof(token);
                    break;
                case 4:
                    strcpy(atom[lineposition].type, token);
                    break;
                case 5:
                    atom[lineposition].block =  token[0];
                    break;
                case 6:
                    atom[lineposition].electrons = atoi(token);
                    break;
                case 7:
                    atom[lineposition].neutrons = atoi(token);
                    break;
                case 8:
                    atom[lineposition].protons = atoi(token);
                    break;
                
            }
            token =strtok(NULL,",");
            tokenposition++;
        }
        if (tokenposition !=9) {
            fprintf(stderr," Error in line %s \n",line);
        }
        lineposition++;


    }
    
}


void search();

void clrscr()
{
    #if defined(__linux__)||defined(__unix__)
        system("clear");
    #endif
    #if defined(_WIN32)||defined(_WIN64)
        system("cls");
    #endif
}

void newScreen()
{
    clrscr();
    int width = 132;
    char str[] = "\033[31;1;51;4mPERIODIC TABLE\033[0m\n";
    int length = sizeof(str) - 1;
    int pad = (length >= width) ? 0 : (width - length) / 2;
    printf("%*.*s%s\n", pad, pad, " ", str);
    for (int i = 0; i < 10; i++)
    {
        printf("\n");
    }
}

void quit()
{
    newScreen();
    char ans[5];
    printf("\033[31mARE YOU SURE YOU WANT TO QUIT?\033[0m");
    scanf("%s", ans);
    if (tolower(ans[0]) == 'y')
    {
        printf("\n\n\n\n\033[35mTHANK YOU\033[0m\n\n");
    }
    else
    {
        main();
    }
}

void again()
{
    char ans1[5];
    printf("\n\n\n\n\033[32mSEARCH FOR A DIFFERENT ELEMENT? : \033[0m");
    scanf("%s", ans1);
    if (tolower(ans1[0]) == 'y')
    {
        search();
    }
    else
    {
        quit();
    }
    printf("\n\n\n\n\n\n\n\n\n\n");
}

void info1()
{
    int i;
    newScreen();
    char ele[20];
    //printf("Atom 0 %s\n",atom[0].name);
    printf("\033[32mENTER THE ELEMENT'S NAME : \033[0m");
    scanf("%s", ele);
    for (int xx=0; xx <strlen(ele); xx++){
        ele[xx]=tolower(ele[xx]);
    }
    for (i = 0; i < 118; i++)
    {
        
        if (strcmp(atom[i].name, ele) == 0)
        {
            printf("\033[34m\n\n\tELEMENT : %s\033[0m\n", atom[i].name);
            printf("\033[34m\n\n\tSYMBOL : %s\033[0m\n", atom[i].symbol);
            printf("\033[34m\n\n\tATOMIC NUMBER : %d\033[0m\n", atom[i].atomicnum);
            printf("\033[34m\n\n\tATOMIC WEIGHT : %f\033[0m\n", atom[i].atomicwt);
            printf("\033[34m\n\n\tBLOCK : %c\033[0m\n", atom[i].block);
            printf("\033[34m\n\n\tTYPE : %s\033[0m\n", atom[i].type);
            printf("\033[34m\n\n\tPROTONS : %d\033[0m\n", atom[i].protons);
            printf("\033[34m\n\n\tNEUTRON : %d\033[0m\n", atom[i].neutrons);
            printf("\033[34m\n\n\tELECTRONS : %d\033[0m\n", atom[i].electrons);
            break;
        }
    }
    again();
}

void info2()
{
    int i;
    newScreen();
    char sym[2];
    printf("\033[32mENTER THE ELEMENT'S SYMBOL : \033[0m");
    scanf("%s", sym);
    for (i = 0; i < 118; i++)
    {
        if (strcmp(atom[i].symbol, sym) == 0)
        {
            printf("\033[34m\n\n\tELEMENT : %s\033[0m\n", atom[i].name);
            printf("\033[34m\n\n\tSYMBOL : %s\033[0m\n", atom[i].symbol);
            printf("\033[34m\n\n\tATOMIC NUMBER : %d\033[0m\n", atom[i].atomicnum);
            printf("\033[34m\n\n\tATOMIC WEIGHT : %f\033[0m\n", atom[i].atomicwt);
            printf("\033[34m\n\n\tBLOCK : %c\033[0m\n", atom[i].block);
            printf("\033[34m\n\n\tTYPE : %s\033[0m\n", atom[i].type);
            printf("\033[34m\n\n\tPROTONS : %d\033[0m\n", atom[i].protons);
            printf("\033[34m\n\n\tNEUTRON : %d\033[0m\n", atom[i].neutrons);
            printf("\033[34m\n\n\tELECTRONS : %d\033[0m\n", atom[i].electrons);
            break;
        }
    }
    again();
}

void info3()
{
    int i;
    newScreen();
    int atn;
    printf("\033[32mENTER THE ELEMENT'S ATOMIC NUMBER : \033[0m");
    scanf("%d", &atn);
    for (i = 0; i < 118; i++)
    {
        if (atom[i].atomicnum == atn)
        {
            printf("\033[34m\n\n\tELEMENT : %s\033[0m\n", atom[i].name);
            printf("\033[34m\n\n\tSYMBOL : %s\033[0m\n", atom[i].symbol);
            printf("\033[34m\n\n\tATOMIC NUMBER : %d\033[0m\n", atom[i].atomicnum);
            printf("\033[34m\n\n\tATOMIC WEIGHT : %f\033[0m\n", atom[i].atomicwt);
            printf("\033[34m\n\n\tBLOCK : %c\033[0m\n", atom[i].block);
            printf("\033[34m\n\n\tTYPE : %s\033[0m\n", atom[i].type);
            printf("\033[34m\n\n\tPROTONS : %d\033[0m\n", atom[i].protons);
            printf("\033[34m\n\n\tNEUTRON : %d\033[0m\n", atom[i].neutrons);
            printf("\033[34m\n\n\tELECTRONS : %d\033[0m\n", atom[i].electrons);
            break;
        }
    }
    again();
}

void info4()
{
    int i;
    newScreen();
    float atwt;
    printf("\033[32mENTER THE ELEMENT'S ATOMIC WEIGHT : \033[0m");
    scanf("%f", &atwt);
    for (i = 0; i < 118; i++)
    {
        if (atom[i].atomicwt == atwt)
        {
            printf("\033[34m\n\n\tELEMENT : %s\033[0m\n", atom[i].name);
            printf("\033[34m\n\n\tSYMBOL : %s\033[0m\n", atom[i].symbol);
            printf("\033[34m\n\n\tATOMIC NUMBER : %d\033[0m\n", atom[i].atomicnum);
            printf("\033[34m\n\n\tATOMIC WEIGHT : %f\033[0m\n", atom[i].atomicwt);
            printf("\033[34m\n\n\tBLOCK : %c\033[0m\n", atom[i].block);
            printf("\033[34m\n\n\tTYPE : %s\033[0m\n", atom[i].type);
            printf("\033[34m\n\n\tPROTONS : %d\033[0m\n", atom[i].protons);
            printf("\033[34m\n\n\tNEUTRON : %d\033[0m\n", atom[i].neutrons);
            printf("\033[34m\n\n\tELECTRONS : %d\033[0m\n", atom[i].electrons);
            break;
        }
    }
    again();
}

void info5()
{
    int i;
    newScreen();
    char typ[20];
    //printf("%s,%s\n",atom[0].type,atom[1].type);
    printf("\033[32mENTER THE ELEMENT'S TYPE : \033[0m");
    fgetc(stdin);
    fgets(typ,20,stdin);
    typ[strcspn(typ,"\n")]=0;
    for (i = 0; i < 118; i++)
    {
        //printf(" %d,%d \n",strlen(atom[0].type),strlen(typ));
        if (strcmp(atom[i].type, typ) == 0)
        {
            printf("\033[34m\n\n\tELEMENT : %s\033[0m\n", atom[i].name);
            printf("\033[34m\n\n\tSYMBOL : %s\033[0m\n", atom[i].symbol);
            printf("\033[34m\n\n\tATOMIC NUMBER : %d\033[0m\n", atom[i].atomicnum);
            printf("\033[34m\n\n\tATOMIC WEIGHT : %f\033[0m\n", atom[i].atomicwt);
            printf("\033[34m\n\n\tBLOCK : %c\033[0m\n", atom[i].block);
            printf("\033[34m\n\n\tTYPE : %s\033[0m\n", atom[i].type);
            printf("\033[34m\n\n\tPROTONS : %d\033[0m\n", atom[i].protons);
            printf("\033[34m\n\n\tNEUTRON : %d\033[0m\n", atom[i].neutrons);
            printf("\033[34m\n\n\tELECTRONS : %d\033[0m\n", atom[i].electrons);
        }
    }
    again();
}

void info6()
{
    int i;
    newScreen();
    char blk[2];
    printf("\033[32mENTER THE ELEMENT'S BLOCK : \033[0m");
    //
    //printf("s\n");
    fgetc(stdin);
    fgets(blk,2,stdin);
    blk[strcspn(blk,"\n")]=0;
    //scanf("%c", &blk);
    //printf("%c",blk[0]);
    for (i = 0; i < 118; i++)
    {
        //printf("Block is %c Blk is %c\n",atom[i].block,blk[0]);
        if (atom[i].block == blk[0])
        {
            printf("\033[34m\n\n\tELEMENT : %s\033[0m\n", atom[i].name);
            printf("\033[34m\n\n\tSYMBOL : %s\033[0m\n", atom[i].symbol);
            printf("\033[34m\n\n\tATOMIC NUMBER : %d\033[0m\n", atom[i].atomicnum);
            printf("\033[34m\n\n\tATOMIC WEIGHT : %f\033[0m\n", atom[i].atomicwt);
            printf("\033[34m\n\n\tBLOCK : %c\033[0m\n", atom[i].block);
            printf("\033[34m\n\n\tTYPE : %s\033[0m\n", atom[i].type);
            printf("\033[34m\n\n\tPROTONS : %d\033[0m\n", atom[i].protons);
            printf("\033[34m\n\n\tNEUTRON : %d\033[0m\n", atom[i].neutrons);
            printf("\033[34m\n\n\tELECTRONS : %d\033[0m\n", atom[i].electrons);
        }
    }
    again();
}

void search()
{
    newScreen();
    printf("\033[33mSREACH BY :- \033[0m\n\n");
    printf("\033[34m\t1 -> ELEMENT\033[0m\n");
    printf("\033[34m\t2 -> SYMBOL\033[0m\n");
    printf("\033[34m\t3 -> ATOMIC NUMBER\033[0m\n");
    printf("\033[34m\t4 -> ATOMIC WEIGHT\033[0m\n");
    printf("\033[34m\t5 -> TYPE\033[0m\n");
    printf("\033[34m\t6 -> BLOCK\033[0m\n\n\n\n");
    int choice2;
    printf("\033[32mYOUR CHOICE : \033[0m");
    scanf("%d", &choice2);
    if (choice2 == 1)
    {
        info1();
    }
    else if (choice2 == 2)
    {
        info2();
    }
    else if (choice2 == 3)
    {
        info3();
    }
    else if (choice2 == 4)
    {
        info4();
    }
    else if (choice2 == 5)
    {
        info5();
    }
    else if (choice2 == 6)
    {
        info6();
    }
    else
    {
        search();
    }
}


void main()
{
    newScreen();
    printf("\033[34m1 -> EXPLORE\033[0m\n");
    printf("\033[34m2 -> QUIT\033[0m\n\n\n\n");
    int choice1;
    printf("\033[32mYOUR CHOICE : \033[0m");
    scanf("%d", &choice1);
    table();
    
    if (choice1 == 1)
    {
        search();
    }
    else if (choice1 == 2)
    {
        quit();
    }
    else
    {
        main();
    }
    
}