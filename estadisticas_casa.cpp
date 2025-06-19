#include<iostream>
#include "estadisticas_casa.h"

void cargarEstadisticas(int estadisticas[], int casa_opcion) {
    switch (casa_opcion) {
    case 1: // Lannister
        estadisticas[0] = 75000;
        estadisticas[1] = 15; //habilidad
        estadisticas[5] = 10000; //compra soldados
        estadisticas[6] = 5000; //compra comida
        estadisticas[7] = 10000; //mejora pasiva
        break;
    case 2: // Stark
        estadisticas[0] = 50000;
        estadisticas[1] = 30;
        estadisticas[5] = 8500;
        estadisticas[6] = 5000;
        estadisticas[7] = 8500;
        break;
    case 3: // Targaryen
        estadisticas[0] = 50000;
        estadisticas[1] = 10;
        estadisticas[5] = 12500;
        estadisticas[6] = 5000;
        estadisticas[7] = 25000;
        break;

    case 4: // Baratheon
        estadisticas[0] = 50000;
        estadisticas[1] = 5;
        estadisticas[5] = 10000;
        estadisticas[6] = 3000;
        estadisticas[7] = 5000;
        break;
    }

    estadisticas[2] = estadisticas[0]; // oro inicial
    estadisticas[3] = 0; // comida
    estadisticas[4] = 0; // soldados
}
