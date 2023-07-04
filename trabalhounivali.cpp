#include <iostream>
#include <unistd.h>
#include <ctime> // para utilizar a função de números aleátorios

using namespace std;

int main(){
    setlocale(LC_ALL,"Portuguese");
  //Trabalho feito por: Vinicius Germann, João V. de Paula, Bruno Schmidt Dal Paz, Rafael Schmidt Dal Paz, Carlos Eduardo S.Costa
  int  inicio;
  int n1, n2, n3, n4;
  int digitadototal,digitado1, digitado2, digitado3, digitado4;
  int contavit=0,contader=10,contain=0;
  //variaves
  do{

     cout<<"================"<<endl<<"MASTERMIND/SENHA"<<endl<<"================"<<endl;

  cout<<endl<<"1: Jogar.\n2: Sobre.\n3: Sair.\n";    // menu do jogo
  cout<<endl<<"(Digite a opção): ";
  cin>>inicio;

  switch(inicio){  //usado para fazer o sistema de escolha
case 1:  // primeira escolha: jogar
      system("CLS");//deixa só as informações essencias
      srand(time(NULL)); // Gera números aleatorios
        contavit=0;
        contader=10;
        contain=0;

      do
      {
        n1=(rand()%6)+1;   //gera 4 numeros aleatoios de 1 a 6
        n2=(rand()%6)+1;
        n3=(rand()%6)+1;
        n4=(rand()%6)+1;
      }while(n1==n2||n1==n3||n1==n4||n2==n3||n2==n4||n3==n4); // condicoes para que os numeros nao sejam iguais

      do{
      system("CLS");
      cout<< "\n\n insira 4 digitos, entre 1 a 6,sem poder repetir os numeros, para descobrir a senha \n\n ";
      cout<< "voce tem "<<contader<<" chances para descobrir a senha  \n\n ";
      cout<< "voce tem "<<contavit<<" numeros certos no lugar certo para descobrir a senha  \n\n "; //comandos que aparecem na tela do jogador
      cout<< "voce tem "<<contain<<" numeros certos no lugar errado\n\n ";
      if(contader<=9){
           cout<< "a senha que vc digitou era:"<<digitadototal<< endl;// mostra sua senha digitada no comando anterior
      }
      cout<<" A Senha: " <<n1<<n2<<n3<<n4<<endl;
      cin>>digitadototal;

      contader--;//diminui suas chances por tentativas

      if(digitadototal<=6543){
        digitado1=digitadototal/1000;   //exemplo se o numero escolhido for 6543 ao dividir por 1000 ficara =  6,543 ou seja o resultado sera = 6.
        //cout<<endl<<digitado1;
        digitado2=(digitadototal/100)%10; //exemplo se o numero escolhido for 6543 ao dividir por 100 ficara =  65,43 depois dividindo por 10 ficara =  6,543
        //cout<<endl<<digitado2;             pegando seu resto o resultado é = 5 .
        digitado3=(digitadototal/10)%10;  //exemplo se o numero escolhido for 6543 ao dividir por 10 ficara = 654,3 depois dividindo novamente por 10 ficara
        //cout<<endl<<digitado3;            = 65,43 pegando seu resto o resultado é = 4.
        digitado4=digitadototal%10;    // exemplo  se o numero escolhido for 6543 ao dividir por 10 ficara =654,3 pegando seu resto o resultado é = 3.
        //cout<<endl<<digitado4;

        contavit=0;
        contain=0;

        if(digitado1==n1){
          contavit++;
        }
        if(digitado2==n2){
          contavit++;
        }
        if(digitado3==n3){             //condicoes de acertos para que o jogador ganhe ao igualar o numeor digitado com o numero sorteado
          contavit++;
        }
        if(digitado4==n4){
          contavit++;
        }

        if(digitado1==n2||digitado1==n3||digitado1==n4){
          contain++;
        }
        if(digitado2==n1||digitado2==n3||digitado2==n4){
          contain++;
        }
        if(digitado3==n2||digitado3==n1||digitado3==n4){
          contain++;
        }
        if(digitado4==n2||digitado4==n3||digitado4==n1){
          contain++;
        }


      }else{
        cout<< "digite um numero de até 4 digitos, de 1 até 6.\n"; // comando para mostrar oque o jogador deve fazer
      }

      }while(contavit!=4&&contader!=0);//mostra as condioces de vitoria e derrota


      if(contavit==4){ // condicao de vitoria
        system("CLS");
        cout<< "parabens, vc ganhou\n";
        system("pause");
        system("CLS");
      }
      if(contader==0){ // condicao de derrota
        system("CLS");
        cout<< "parabens, vc perdeu\n";
        system("pause");
        system("CLS");
      }


    break;//quebra de linha para a proxima escolha

    case 2: // segunda escolha: sobre
      system("CLS"); //deixa só as informações essencias
      cout<<endl<<"Trabalho 2 Algoritmos e Programação.\n\n Feito por: Vinicius Germann\n\n João V. de Paula\n\n Bruno Schmidt Dal Paz\n\n Rafael Schmidt Dal Paz\n\n Carlos Eduardo Souza Costa.  \n\n Data: 10/05/2023.\n\n Professor: Rafael Ballottin Martins\n";
      cout << "\nDigite qualquer tecla para voltar ao menu.\n\n"; //Pede um comando para voltar pro menu
      system("pause");// pausa e reinicia o comando
      system("CLS"); // deixa só as informações essencias
    break;//quebra de linha para a próxima escolha

    case 3: // terceira escolha: sair
       system("CLS");
       cout << "Você saiu do jogo." << endl;

    break;//quebra de linha para a proxima escolha

    default: // condicao caso nao seja antendida nenhuma das anteriores
    system("CLS");//deixa só as informações essencias
    cout<<"\nOpção inválida.\n";
    }

}while(inicio != 3); //caso escolha umas opcao que nao esta no inicio
    return 0;
}
