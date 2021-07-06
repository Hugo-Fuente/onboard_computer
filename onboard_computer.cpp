#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <windows.h>
#include <locale.h>
#include <chrono>
#include <bits/stdc++.h>

auto start = std::chrono::high_resolution_clock::now();

using namespace std;

/*
SI300 B - Programa��o Orientada � Objetos - Exerc�cio Programa 5
Hugo Gomes de La Fuente
this text was made in VSCode and published to github with sucess !
*/

class Carro{
    bool ligado = false;
    bool parado = true;
    double velocidade = 0.0;
    double Distancia = 0.0;
    double recebe_Distancia = 0.0;

    public:
    bool ligar_Carro();
    bool desligar_Carro();
    void velocidade_Carro();
    bool parar_Carro();
    double Distancia_Carro();
    void consumo_Carro();

};

bool Carro::ligar_Carro(){
    system("cls");
    if(ligado == true){
        cout << "O carro j� est� ligado";
    }else{
        cout << "O carro foi ligado com sucesso";
    }

    cout << "\n\n\nRetornando ao menu...";
    Sleep(2000);
    return ligado = true;
    }

bool Carro::desligar_Carro(){
    system("cls");
    if(ligado == false){
        cout << "O carro j� est� desligado";
    }else{
        cout << "O carro foi desligado com sucesso";
    }

    cout << "\n\n\nRetornando ao menu...";
    velocidade = 0.0;
    Sleep(2000);
    return ligado = false;
    }


void Carro:: velocidade_Carro(){
    char ch;
    char ch2;
    system("cls");
    if(ligado == true){
        if(parado == true){
            cout << "O ve�culo est� parado no momento. Deseja mov�-lo? (S/N)";
            cin >> ch;
            if(ch == 's' or ch == 'S'){
                velocidade = 20.0;
                do{

                    parado = false;

                    int c_start = clock();
                    start = std::chrono::high_resolution_clock::now();

                    system("cls");
                    cout << "Velocidade atual: " << velocidade << " KM/H                                                Velocidade m�xima: 200 KM/H";

                    cout << "\n\nAcelerar? (S/N)";
                    cin >> ch2;
                    if(ch2 == 's' or ch2 == 'S'){
                        if(velocidade < 200){
                            velocidade = velocidade + 20.0;
                        }else{
                            cout << "\nO carro est� na velocidade m�xima. Desacelerar? (S/N)";
                            cin >> ch2;
                            if(ch2 == 's' or ch2 == 'S'){
                                velocidade = velocidade - 20.0;
                            }else{
                                break;
                            }
                        }
                    }else{
                        cout << "Desacelerar? (S/N)";
                        cin >> ch2;
                        if(ch2 == 's' or ch2 == 'S'){
                            velocidade = velocidade - 20.0;
                        }else{
                            system("cls");
                            cout << "Velocidade atual: " << velocidade;

                            cout << "\n\n\nPressione ENTER para continuar.";
                            std::cin.sync(); std::cin.get();
                        }
                    }
                }while(ch2 == 's' or ch2 == 'S');
            }
        }else{
            do{
                    parado = false;
                    system("cls");
                    cout << "Velocidade atual: " << velocidade << " KM/H                                                Velocidade m�xima: 200 KM/H";

                    cout << "\n\nAcelerar? (S/N)";
                    cin >> ch2;
                    if(ch2 == 's' or ch2 == 'S'){
                        if(velocidade < 200){
                            velocidade = velocidade + 20.0;
                        }else{
                            cout << "\nJ� est� na velocidade m�xima, desacelerar? (S/N)";
                            cin >> ch2;
                            if(ch2 == 's' or ch2 == 'S'){
                                velocidade = velocidade - 20.0;
                            }else{
                                break;
                            }
                        }
                    }else{
                        cout << "Desacelerar? (S/N)";
                        cin >> ch2;
                        if(ch2 == 's' or ch2 == 'S'){
                            velocidade = velocidade - 30.0;
                        }else{
                            system("cls");
                            cout << "Velocidade atual: " << velocidade;

                            cout << "\n\n\nPressione ENTER para continuar.";
                            std::cin.sync(); std::cin.get();
                        }
                    }
                }while(ch2 == 's' or ch2 == 'S');
        }
    }else{
        cout << "O carro est� desligado. Por favor, ligue o carro antes.";

        cout << "\n\n\nRetornando ao MENU...";
        Sleep(2000);
    }
}

bool Carro:: parar_Carro(){
    system("cls");
    if(parado == true){
        cout << "O carro j� est� parado";
    }else{
        cout << "Parando o carro...";
        velocidade = 0.0;
    }

    cout << "\n\n\nRetornando ao MENU...";
    Sleep(2000);
    return parado = true;
}

double Carro:: Distancia_Carro(){
    system("cls");
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;

    if(velocidade != 0){
        double velocidadems = velocidade / 3.6;
        double Distancia = velocidadems * elapsed.count();
        recebe_Distancia = recebe_Distancia + Distancia;

        cout << "Velocidade atual: " << velocidade << " KM/H                                                Velocidade M/S: " << velocidadems;
        cout << "\nTempo decorrido: " << elapsed.count() << " seg.";

        cout.precision(3);
        cout << "\nDistancia percorrida: " << recebe_Distancia / 1000 << " Km";

        cout << "\n\n\nPressione ENTER para continuar.";
        std::cin.sync(); std::cin.get();

        return recebe_Distancia;
    }else{
        cout << "\nDist�ncia percorrida: " << recebe_Distancia / 1000 << " Km";

        cout << "\n\n\nPressione ENTER para continuar.";
        std::cin.sync(); std::cin.get();
    }
}

void Carro:: consumo_Carro(){
    system("cls");
    double consumo = recebe_Distancia / 10000;

    cout << "M�dia de consumo: 10Km/L" << endl;
    cout.precision(3);
    cout << "\nGasolina consumida: " << consumo << " L";
    cout << "\n\n\nPressione ENTER para continuar.";
    std::cin.sync(); std::cin.get();
}

void dataehora();

void dataehora(){
    system("cls");
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();


    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << std::ctime(&end_time);


    cout << "\n\n\nPressione ENTER para continuar.";
    std::cin.sync(); std::cin.get();
}

void ajuda();

void ajuda(){
    system("cls");
	    cout << "\n\n + -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-= Ajuda -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+";
		cout << "\n\n | - No menu principal do aplicativo est�o listadas as a��es que o mesmo � capaz de realizar.                           |";
	    cout << "\n\n | - Para realizar uma a��o dentro do Car9000 basta inserir o numero listado correspondente � a��o que deseja realizar. |";
	    cout << "\n\n | - Pressione ENTER para retornar ao menu principal.                                                                   |";
	    cout << "\n\n +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+";
    std::cin.sync(); std::cin.get();
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    Carro Carro;
    int opc;


    do{


        system("cls");
		cout<<"\n\n\n\t +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+";
		cout<<"\n\t | Bem vindo ao Car9000!                           |";
		cout<<"\n\t |            ~o seu computador pessoal de bordo~  |";
		cout<<"\n\t +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+";
		cout<<"\n\t | 1.  Ligar                                       |" << endl;
		cout<<"\t | 2.  Desligar                                    |" << endl;
		cout<<"\t | 3.  Velocidade Atual                            |" << endl;
		cout<<"\t | 4.  Parar                                       |" << endl;
		cout<<"\t | 5.  Dist�ncia Percorrida                        |" << endl;
		cout<<"\t | 6.  Consumo                                     |" << endl;
		cout<<"\t | 7.  Temperatura do �leo                         |" << endl;
		cout<<"\t | 8.  Voltagem da Bateria                         |" << endl;
		cout<<"\t | 9.  Press�o do �leo                             |" << endl;
		cout<<"\t | 10. Temperatura do Motor                        |" << endl;
		cout<<"\t | 11. Rota��es por Minuto do Motor                |" << endl;
		cout<<"\t | 12. Data e Hora                                 |" << endl;
		cout<<"\t | 13. Ajuda                                       |" << endl;
		cout<<"\t | 0.  Sair                                        |" << endl;
		cout<<"\t +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+";
		cout<<"\n\n\t O que deseja fazer hoje?: ";
		cin >> opc;

        switch (opc){
            case 1:
            Carro.ligar_Carro();
            break;
        case 2:
            Carro.desligar_Carro();
            break;
        case 3:
            Carro.velocidade_Carro();
            break;
        case 4:
            Carro.parar_Carro();
            break;
        case 5:
            Carro.Distancia_Carro();
            break;
        case 6:
            Carro.consumo_Carro();
            break;
        case 12:
            dataehora();
            break;
        case 13:
        	ajuda();
        	break;
        case 0:
            system("cls");
            cout << "\n-=- Obrigado por utilizar o Car9000 -=-\n";
            break;
        default:
            cout << "Algo deu errado, por favor tente novamente.";
            break;
        }
    }while(opc != 0);


    return 0;
}

