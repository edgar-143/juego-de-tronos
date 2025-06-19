#ifndef INICIO_DE_JUEGO_H
#define INICIO_DE_JUEGO_H

#include <string>

void ejecutarJuego();
void SeleccionarCasa(std::string &casa_seleccionada, int &opcion, bool continuar);
int probabilidades(int batalla_actual);
int mostrarMenu(int batalla_actual, int estadisticas[], std::string casa_seleccionada);
void menuTienda(int estadisticas[], std::string casa);

#endif
