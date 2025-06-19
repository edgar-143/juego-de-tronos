#include <iostream>
#include <cstdlib>
#include<ctime>
#include "inicio de juego.h"
#include "estadisticas_casa.h"


using namespace std;

void SeleccionarCasa(string &casa_seleccionada, int &opcion)
{
    while ( true)
    {
        cout << "Selecciona tu casa:\n1. Lannister\n2. Stark\n3. Targaryen\n4. Baratheon\nOpcion: ";
        cin >> opcion;


        if (opcion==1)
        {
            casa_seleccionada = "LANNISTER";
            break;
        }


        else if (opcion==2)
        {
            casa_seleccionada = "STARK";

            break;
        }
        else if (opcion==3)
        {
            casa_seleccionada = "TARGARYEN";

            break;
        }
        else if (opcion==4)
        {
            casa_seleccionada = "BARATHEON";

            break;
        }


        else
        {
            system("cls");
            cout<< "SELECCIONE UNA OPCION CORRECTA\n";
            system("pause");
            system("cls");

        }

    }



}



int mostrarMenu(int batalla_actual, int estadisticas[], string casa_seleccionada)
{
    int opcion;
    system("cls");
    cout << "---------- Juego de Tronos ----------\n";
    cout << casa_seleccionada << "\n";
    cout << "| Batallas: " << batalla_actual << "\n";
    cout << "| Presupuesto: " << estadisticas[0] << "\n";
    cout << "| Oro: " << estadisticas[2] << "\n";
    cout << "| Comida: " << estadisticas[3] << "\n";
    cout << "| Soldados: " << estadisticas[4] << "\n";
    cout << "| habilidad: " << estadisticas[1]<<"%" << "\n";
    cout << "-------------------------------------\n";
    cout << "1. Batalla\n2. Tienda\n3. Salir\nOpcion: ";
    cin >> opcion;
    return opcion;
}

void menuTienda(int estadisticas[], string casa_seleccionada)
{
    int opcion;
    do
    {
        system("cls");
        cout << "---------- TIENDA - " << casa_seleccionada << " ----------\n";
        cout << "| Oro: " << estadisticas[2] << "\n";
        cout <<". soldados - " << estadisticas[4] << "\n";
        cout << ". comida    - " << estadisticas[3] << "\n";
        cout << ". habilidad    - " << estadisticas[1]/ 100.0f << "\n";
        cout << "1. soldados - $" << estadisticas[5] << "\n";
        cout << "2. comida    - $" << estadisticas[6] << "\n";
        cout << "3. Mejorar habilidad    - $" << estadisticas[7] << "\n";
        cout << "4. Volver\nOpcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            if (estadisticas[2] >= estadisticas[5])
            {
                estadisticas[4] += 10000;
                estadisticas[2] -= estadisticas[5];
            }
            else cout << "No tienes oro suficiente.\n";
            break;
        case 2:
            if (estadisticas[2] >= estadisticas[6])
            {
                estadisticas[3] += 10000;
                estadisticas[2] -= estadisticas[6];
            }
            else cout << "No tienes oro suficiente.\n";
            break;
        case 3:
            if (estadisticas[2] >= estadisticas[7])
            {
                estadisticas[1] += 5;
                estadisticas[2] -= estadisticas[7];
            }
            else cout << "No tienes oro suficiente.\n";
            break;
        case 4:
            break;
        default:
            cout << "Opción inválida.\n";
            break;
        }
        system("pause");
    }
    while (opcion != 4);
}

void ejecutarJuego()
{
    string Casa_seleccionada;
    int Seleccion_casa;
    int estadisticas[9] = {};
    int batalla_actual = 0;

    SeleccionarCasa(Casa_seleccionada, Seleccion_casa);
    cargarEstadisticas(estadisticas, Seleccion_casa);

    bool continuar = true;
    while (continuar)
    {
        int opcion = mostrarMenu(batalla_actual, estadisticas, Casa_seleccionada);
        switch (opcion)
        {
        case 1:
        {
            if (batalla_actual >= 10)
            {
                cout << "No hay más batallas.\n";
                system("pause");
                break;
            }
            srand(time(NULL));
                int probabilidad_habilidad=rand()%100;
                int probabilidad=rand()% 100;
               int recompensa_habilidad=0;
               if (Casa_seleccionada=="LANNISTER" and estadisticas[1]<=probabilidad_habilidad){
                    estadisticas[2]= estadisticas[2]+recompensa_habilidad*1.30;

                }
            cout << "Batalla #" << (batalla_actual + 1) << "\n";
            cout << "Soldados: " << estadisticas[4] << ", Comida: " << estadisticas[3]
                 << "habiliad: " << estadisticas[1]<<"%"<< "\n";
            cout << "¿Deseas continuar? 1(Sí) / 2(No): ";
            int decision;
            cin >> decision;
            if( decision== 1 and estadisticas[4]==0){
                    system("cls");
                cout<<"necesitas soldados para ir a la batalla\n";
                system("pause");}
          else  if (decision == 1 && estadisticas[3]>=estadisticas[4])
            {
                batalla_actual++;





                if (Casa_seleccionada=="LANNISTER" && probabilidad_habilidad<=estadisticas[1]){
                        estadisticas[2]= estadisticas[2]+recompensa_habilidad*0.30;

                }

                if (estadisticas[4]>6500*10)
                {
                    probabilidad-=90;
                    cout<<"\n";
                }
                else if (estadisticas[4]>6500*9)
                {
                    probabilidad-=80;
                    cout<<"\n";
                }
                else if (estadisticas[4]>6500*8)
                {
                    probabilidad-=70;
                    cout<<"\n";
                }
                else if (estadisticas[4]>6500*7)
                {
                    probabilidad-=10;
                    cout<<"\n";
                }
                else  if (estadisticas[4]>6500*6)
                {
                    probabilidad-=60;
                    cout<<"\n";
                }
                else  if (estadisticas[4]>6500*5)
                {
                    probabilidad-=50;
                    cout<<"\n";
                }
                else   if (estadisticas[4]>6500*4)
                {
                    probabilidad-=40;
                    cout<<"\n";
                }
                if (estadisticas[4]>6500*3)
                {
                    probabilidad-=30;
                    cout<<"\n";
                }
                else  if (estadisticas[4]>6500*2)
                {
                    probabilidad-=20;
                    cout<<"\n";
                }
                else  if (estadisticas[4]>6500)
                {
                    probabilidad-=10;
                    cout<<"\n";
                }


                switch (batalla_actual)
                {
                case 1:
                {

                    if (probabilidad<= 50)
                    {
                        estadisticas[4]=estadisticas[4]*0.95;
                        cout << "Batalla 1 ganada (100%)\n";
                        estadisticas[2]=estadisticas[2]+15000;
                        recompensa_habilidad=15000;
                        estadisticas[3]=0;
                        system("pause");
                        system("cls");
                        break;
                    }
                    else
                    {

                        cout << "Batalla 1 perdida\n";
                        system("pause");
                        continuar=false;
                        break;
                    }
                }

                case 2:
                {


                    if (probabilidad <= 45)
                    {

                        estadisticas[4]=estadisticas[4]*0.90;
                        system("cls");
                        cout << "Batalla 2 ganada (90%)\n";
                         estadisticas[2]=estadisticas[2]+20000;
                         recompensa_habilidad=20000;
                          estadisticas[3]=0;
                        system("pause");
                        system("cls");
                        break;
                    }
                    else
                    {
                        system("cls");
                        cout << "Batalla 2 perdida\n";
                        system("pause");
                        continuar=false;
                        break;
                    }
                }
                case 3:
                {


                    if (probabilidad <= 40)
                    {
                        estadisticas[4]=estadisticas[4]*0.85;
                        system("cls");
                        cout << "Batalla 3 ganada (80%)\n";
                         estadisticas[2]=estadisticas[2]+25000;
                         recompensa_habilidad=25000;
                          estadisticas[3]=0;
                        system("pause");
                        break;
                    }
                    else
                    {
                        system("cls");
                        cout << "Batalla 3 perdida\n";
                        system("pause");
                        system("cls");
                        continuar=false;
                        break;
                    }
                }


                case 4:
                {

                    if ( probabilidad <= 35)
                    {
                        estadisticas[4]=estadisticas[4]*0.70;
                        system("cls");
                        cout << "Batalla 4 ganada (70%)\n";
                         estadisticas[2]=estadisticas[2]+30000;
                         recompensa_habilidad=30000;
                          estadisticas[3]=0;
                        system("pause");
                        break;
                    }
                    else
                    {
                        system("cls");
                        cout << "Batalla 4 perdida\n";
                        system("pause");
                        system("cls");
                        continuar=false;
                        break;
                    }
                }
                case 5:
                {

                    if (probabilidad <= 30)
                    {
                        estadisticas[4]=estadisticas[4]*0.65;
                        system("cls");
                        cout << "Batalla 5 ganada (60%)\n";
                         estadisticas[2]=estadisticas[2]+35000;
                         recompensa_habilidad=35000;
                          estadisticas[3]=0;
                        system("pause");
                        system("cls");
                        break;
                    }
                    else
                    {
                        system("cls");
                        cout << "Batalla 5 perdida\n";
                        system("pause");
                        continuar=false;
                        break;
                    }
                }

                case 6:
                {

                    if (probabilidad <= 25)
                    {
                        estadisticas[4]=estadisticas[4]*0.50;
                        system("cls");
                        cout << "Batalla 6 ganada (50%)\n";
                         estadisticas[2]=estadisticas[2]+40000;
                         recompensa_habilidad=40000;
                          estadisticas[3]=0;
                        system("pause");
                        break;
                    }
                    else
                    {
                        system("cls");
                        cout << "Batalla 6 perdida\n";
                        system("pause");
                        system("cls");
                        continuar=false;
                        break;

                    }
                }

                case 7:
                {

                    if (probabilidad <= 20)
                    {
                        estadisticas[4]=estadisticas[4]*0.45;
                        system("cls");
                        cout << "Batalla 7 ganada (40%)\n";
                         estadisticas[2]=estadisticas[2]+45000;
                         recompensa_habilidad=45000;
                          estadisticas[3]=0;
                        system("pause");
                        break;
                    }
                    else
                    {
                        system("cls");
                        cout << "Batalla 7 perdida\n";
                        system("pause");
                        system("cls");
                        continuar=false;
                        break;
                    }
                }

                case 8:
                {

                    if (probabilidad <= 15)
                    {
                        estadisticas[4]=estadisticas[4]*0.40;
                        system("cls");
                        cout << "Batalla 8 ganada (30%)\n";
                         estadisticas[2]=estadisticas[2]+50000;
                         recompensa_habilidad=50000;
                          estadisticas[3]=0;
                        system("pause");
                        break;
                    }
                    else
                    {
                        system("cls");
                        cout << "Batalla 8 perdida\n";
                        system("pause");
                        system("cls");
                        continuar=false;
                        break;


                    }







                }
                case 9:
                {

                    if (probabilidad <= 10)
                    {
                        estadisticas[4]=estadisticas[4]*0.35;
                        system("cls");
                        cout << "Batalla 9 ganada (20%)\n";
                         estadisticas[2]=estadisticas[2]+55000;
                         recompensa_habilidad=55000;
                          estadisticas[3]=0;
                        system("pause");
                        break;
                    }
                    else
                    {
                        system("cls");
                        cout << "Batalla 9 perdida\n";
                        system("pause");
                        system("cls");
                        continuar=false;
                        break;


                    }







                }
                case 10:
                {


                    if (probabilidad<= 5)
                    {
                        estadisticas[4]=estadisticas[4]*0.30;
                        system("cls");
                        cout << "Batalla 10 ganada (10%)\n";
                         estadisticas[2]=estadisticas[2]+60000;
                         recompensa_habilidad=60000;
                          estadisticas[3]=0;
                        system("pause");

                        break;
                    }
                    else
                    {
                        system("cls");
                        cout << "Batalla 10 perdida\n";
                        system("pause");
                        system("cls");
                        continuar=false;
                        break;



                    }







                }
                }


            }
            else if(estadisticas[2]=0 and estadisticas[3]<estadisticas[4]){
                cout<<"no tienes suficiente dinero para combatir ni alimentar a todos tus soldados";
                continuar=false;
            }

            else
            {

                cout<<"no tiene suficiente comida para todos los soldados\n";
                system("pause");
            }
            break;
        }
        case 2:
            menuTienda(estadisticas, Casa_seleccionada);
            break;
        case 3:
            continuar = false;
            break;
        default:
            cout << "Opción inválida.\n";
        }
    }
    cout << "Gracias por jugar. Hasta luego.\n";
}
