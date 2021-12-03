/*
 * Proyecto Simulador_Auto
 * Héctor Manuel Cervantes Rodríguez
 * A01571242
 * 02/12/2021
 */

/*
 * Clase Conductor, crea el carro, ya sea Deportivo o Sedan. 
 */

#ifndef CONDUCTOR_H
#define CONDUCTOR_H
#include "Carro.h"
#include "Motor.h"
#include "Deportivo.h"

class Conductor{


private:
  //Declara las variables de instancia
  float gasto_por_litro;
	int miembros_familia;
  Carro carrito;

public:
  //Constuctor Default
  Conductor():gasto_por_litro(8), miembros_familia(0){}; 
  //Constuctor a partir de parámetros introducidos.
  Conductor(float gast, int miem): gasto_por_litro(gast), miembros_familia(miem){};
  // Metodos miembros de la clase
  Carro get_carro();
  float get_gasto_por_litro();
  int get_miembros_familia();
  void set_gasto_por_litro(float );
  void set_miembros_familia(int);
  void crea_carro();


};

//Getters
/**
*getter carrito
*Devuelve el objeto Carro creado.
*/

Carro Conductor::get_carro(){

  return carrito;

}

/**
*getter gasto_por_litro
*Devuelve el gasto_por_litro especificado 
*al crear el objeto Condcutor.
*/

float Conductor::get_gasto_por_litro(){

  return gasto_por_litro;

}

/**
*getter miembros_familia
*Devuelve miembros_familia, parametro especificado 
*al crear el objeto Conductor.
*/

int Conductor::get_miembros_familia(){

  return miembros_familia;

}

//Setters
/**
*setter gasto_por_litro
*Permite cambiar el valor de la variable gasto_por_litro; 
parametro especificado al crear el objeto Conductor.
*/

void Conductor::set_gasto_por_litro(float gast){

  gasto_por_litro = gast;

}

/**
*setter miembros_familia
*Permite cambiar el valor de la variable miembros_familia; 
parametro especificado al crear el objeto Conductor.
*/

void Conductor::set_miembros_familia(int miem){

  miembros_familia = miem;

}

/**
*Crear el tipo de objeto Carro (composición).
*/

void Conductor::crea_carro() {
  
  Carro m1(4,8,false,0,0,80);
  carrito = m1;
  
}

#endif
