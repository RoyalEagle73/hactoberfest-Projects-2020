

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>                //Used for srand((unsigned) time(NULL)) command
//#include <process.h>


#define mano 5
#define spade 197                 //Used to print spade symbol
#define club 190                  //Used to print club symbol
#define diamond 156               //Used to print diamond symbol
#define heart 184  
unsigned char arm[4]={spade,club,diamond,heart};
void menu();

typedef struct{
    short identidad; //0 jugador 1 crupier
    char mazo;
    char num;
}carta;

char cartas[4][13];
long unsigned int dinero=500;
unsigned int apuesta=0;
void Mostrar(){
    fflush(stdout);
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++)
            printf("%d",cartas[i][j]);
        printf("\n");
    }
}

void imprimirInicio(){
    system("cls");
    int choice1;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n              222                111                            ");
    printf("\n            222 222            11111                              ");
    printf("\n           222   222          11 111                            ");
    printf("\n                222              111                               ");
    printf("\n               222               111                           ");
    printf("\n");
    printf("\n%c%c%c%c%c     %c%c            %c%c         %c%c%c%c%c    %c    %c                ", club, club, club, club, club, spade, spade, diamond, diamond, heart, heart, heart, heart, heart, club, club);
    printf("\n%c    %c    %c%c           %c  %c       %c     %c   %c   %c              ", club, club, spade, spade, diamond, diamond, heart, heart, club, club);
    printf("\n%c    %c    %c%c          %c    %c     %c          %c  %c               ", club, club, spade, spade, diamond, diamond, heart, club, club);
    printf("\n%c%c%c%c%c     %c%c          %c %c%c %c     %c          %c %c              ", club, club, club, club, club, spade, spade, diamond, diamond, diamond, diamond, heart, club, club);
    printf("\n%c    %c    %c%c         %c %c%c%c%c %c    %c          %c%c %c             ", club, club, spade, spade, diamond, diamond, diamond, diamond, diamond, diamond, heart, club, club, club);
    printf("\n%c     %c   %c%c         %c      %c    %c          %c   %c               ", club, club, spade, spade, diamond, diamond, heart, club, club);
    printf("\n%c     %c   %c%c        %c        %c    %c     %c   %c    %c             ", club, club, spade, spade, diamond, diamond, heart, heart, club, club);
    printf("\n%c%c%c%c%c%c    %c%c%c%c%c%c%c   %c        %c     %c%c%c%c%c    %c     %c            ", club, club, club, club, club, club, spade, spade, spade, spade, spade, spade, spade, diamond, diamond, heart, heart, heart, heart, heart, club, club);
    printf("\n");
    printf("\n                        21                                   ");

    printf("\n     %c%c%c%c%c%c%c%c      %c%c         %c%c%c%c%c    %c    %c                ", diamond, diamond, diamond, diamond, diamond, diamond, diamond, diamond, heart, heart, club, club, club, club, club, spade, spade);
    printf("\n        %c%c        %c  %c       %c     %c   %c   %c              ", diamond, diamond, heart, heart, club, club, spade, spade);
    printf("\n        %c%c       %c    %c     %c          %c  %c               ", diamond, diamond, heart, heart, club, spade, spade);
    printf("\n        %c%c       %c %c%c %c     %c          %c %c              ", diamond, diamond, heart, heart, heart, heart, club, spade, spade);
    printf("\n        %c%c      %c %c%c%c%c %c    %c          %c%c %c             ", diamond, diamond, heart, heart, heart, heart, heart, heart, club, spade, spade, spade);
    printf("\n        %c%c      %c      %c    %c          %c   %c               ", diamond, diamond, heart, heart, club, spade, spade);
    printf("\n     %c  %c%c     %c        %c    %c     %c   %c    %c             ", diamond, diamond, diamond, heart, heart, club, spade, spade);
    printf("\n      %c%c%c      %c        %c     %c%c%c%c%c    %c     %c            ", diamond, diamond, diamond, heart, heart, club, club, club, club, club, spade, spade);
    printf("\n");
    printf("\n         222                     111                         ");
    printf("\n        222                      111                         ");
    printf("\n       222                       111                         ");
    printf("\n      222222222222222      111111111111111                       ");
    printf("\n      2222222222222222    11111111111111111                         ");
    printf("\n");
    printf("\n");

}

void reglas(){
    system("cls");
    char choice;

     printf("\n           LOS MANDAMIENTOS DEL BLACKJACK");
     printf("\n          ---------------------------");
     printf("\nI.");
     printf("\n     NO CUESTIONARAS LAS REGLAS DEL JUEGO.");
     printf("\n      %c LAS CARTAS SE GENERAN ALEATORIAMENTE", spade);
     printf("\n      %c SI SIGUES PERDIENDO, RETIRATE!\n", diamond);

     printf("\nII.");
     printf("\n     CADA CARTA TIENE UN VALOR.");
     printf("\n      %c LAS CARTAS DEL 2 AL 10 VALEN LO QUE SU NUMERO.", spade);
     printf("\n      %c LAS CARTAS:J, Q, K TIENEN UN VALOR DE 10.", diamond);
     printf("\n      %c EL AS TIENE UN VALOR DE 11 O 1", club);
     printf("\n     EL OBJETIVO DEL JUEGO ES ALCANZAR EL 21.\n");

     printf("\nIII.");
     printf("\n     DESPUES DE QUE RECIBES TUS DOS PRIMERAS CARTAS DEBES DECIDIR SI SEGUIR PIDIENDO O NO.");
     //printf("\n      %c Staying will keep you safe, hitting will add a card.", spade);
     printf("\n      %cDEBES TE TENER UNA MANO MAYOR QUE EL CRUPIER.",spade);
     printf("\n     PERO CUIDADO!.");
     printf("\n      %c SI TE PASAS DE 21 PIERDES!.", diamond);
     printf("\n     PERO NO ACABA AHI, PUEDES VOLVER A JUGAR MIENTRAS TENGAS DINERO.\n");
   //  printf("\n%c%c%c YOUR RESULTS ARE RECORDED AND FOUND IN SAME FOLDER AS PROGRAM %c%c%c\n", spade, heart, club, club, heart, spade);
     printf("\n%c%c%c QUIERES REGRESAR AL MENU? (NO ACEPTO UN NO POR RESPUESTA)", spade, heart, club, club, heart, spade);
     printf("\n                  Para regresar presione 1\n                    ");
     do{scanf("\n%d",&choice);}while(choice!=1);
     system("cls");
     menu();
     
}

void llenar(){
    for(int i=0;i<4;i++)
        for(int j=0;j<13;j++)
            cartas[i][j]=1;
}
short repartir(short n,carta hand[mano],short index){//0:player  1:crupier
    short mazo,num,existe;
    srand(time(NULL));
    for(n; n>0; n--){
        do{
            mazo=rand()%4;
            num=rand()%13;
            if(cartas[mazo][num]==0)
                existe=0;
            else
                existe=1;
        }while(existe==0);
        cartas[mazo][num]=0;
        hand[index].mazo=(char)mazo;
        hand[index].num=(char)num;
        index++;
      //  printf("%d,%d\n",mazo,num);
    }
   // printf("%d %d %d %d\n",hand[0][0],hand[0][1],hand[1][0],hand[1][1]);
   //Mostrar();
    return index;
}

void imprimirCartas(carta Hand[mano],short index){
    char letra;
    short i;
  //  printf("\nDinero: %d\n",dinero);
    if(Hand[0].identidad==0)
        printf("\nJugador:\n");
    else if(Hand[0].identidad==1)
        printf("\nCrupier:\n");
    for(i=0;i<index;i++)
    	    printf("-------\t");
    printf("\n");
    for(i=0;i<index;i++)
    		printf("|%c    |\t", /*Hand[i].mazo+1*/arm[Hand[i].mazo]);
    printf("\n");
    for(i=0;i<index;i++){
		if(Hand[i].num<10&&Hand[i].num>0){
			printf("| %2d  |\t", Hand[i].num+1);
		}
		else{
			switch(Hand[i].num){
				case 0:
					letra='A';
					break;
				case 10:
					letra='J';
					break;
				case 11:
					letra='Q';
					break;
				case 12:
					letra='K';
					break;
				default:
					letra='X';
			}
			printf("|  %c  |\t", letra);
		}
    }
    printf("\n");
    for(i=0;i<index;i++)
    		printf("|    %c|\t", /*Hand[i].mazo+1*/arm[Hand[i].mazo]);
    printf("\n");
    for(i=0;i<index;i++)
    		printf("-------\t");
    printf("\n");
    printf("\n----------------------------------------------------------------\n");
}
char contar(carta Hand[mano],short index){
    short cuenta=0,ace=0;
    for(int i=0;i<index;i++){
        if(Hand[i].num==0){
                cuenta+=11;
                ace++;
        }   
        else if(Hand[i].num>=9)
            cuenta+=10;
        else
            cuenta+=Hand[i].num+1;
    }
    if(cuenta>21&&ace>0){
        while(cuenta>21&&ace>0){
            cuenta-=10;
        }
        ace=0;
    }
    return cuenta;
}
void pensar(carta playerHand[mano],carta crupierHand[mano],short iplayer,short icrupier){
    short jugador=0,crupier=0,ace=0;
   
    jugador=contar(playerHand,iplayer);
   // printf("\n%djjj",jugador);
   
    crupier=contar(crupierHand,icrupier);  
   // printf("\n%dccc",crupier);
    while(crupier<jugador&&crupier<17){
        icrupier=repartir(1,crupierHand,icrupier);
        
        crupier=0;
        
        crupier=contar(crupierHand,icrupier); 
     //   printf("\n%dccc",crupier);
    }
    system("cls");
    imprimirCartas(playerHand,iplayer);
    imprimirCartas(crupierHand,icrupier);
    if(jugador>21){
        printf("\nperdiste");
        dinero-=apuesta;
    }
    else{
        if(jugador>crupier){
            printf("\nganaste");
            dinero+=apuesta;
        }
        else if(jugador<crupier){
             printf("\nperdiste");
            dinero-=apuesta;
        }
        else if(jugador==crupier){
            printf("\nempate");
        }
    }
    
}
void jugar(){
    short retry=0,total=0;
   
    do{
        system("cls");
        do{
            printf("Dinero:%d",dinero);
            printf("\nIngrese Apuesta:");
            scanf("%d",&apuesta);
        }while(apuesta<=0||apuesta>dinero);
        int opcion;
        short ip=0,ic=0;
        carta playerHand[mano];
        playerHand[0].identidad=0;
        carta crupierHand[mano];
        crupierHand[0].identidad=1;
        llenar();
        ip=repartir(2,playerHand,ip);
        ic=repartir(2,crupierHand,ic);
        imprimirCartas(playerHand,ip);
        imprimirCartas(crupierHand,ic);
        
        printf("\n1.Hit 2.Stay");
        scanf("%d",&opcion);
        while(opcion==1){
            system("cls");
            ip=repartir(1,playerHand,ip);
            imprimirCartas(crupierHand,ic);
            imprimirCartas(playerHand,ip);
            total=contar(playerHand,ip);
            if(total>=21) break;
            printf("\n1.Hit 2.Stay");
            scanf("%d",&opcion);
        }
        pensar(playerHand,crupierHand,ip,ic);
        printf("\nVolver a jugar? 1:Si,0:No\n");
        scanf("%d",&retry);
    }while(retry&&dinero!=0);
    printf("TE QUEDASTE SIN DINERO VUELVE LUEGO");
}
void menu(){
    imprimirInicio();
    printf("\n1.Empezar a jugar");
    printf("\n2.Reglas");
    printf("\n0.Salir\n");
    int respuesta;
    scanf("%d",&respuesta);
    switch(respuesta){
        case 1:
            jugar();
            break;
        case 2:
            reglas();
            break;
    }
}

int main(){
    menu();
  
    return 0;
}

