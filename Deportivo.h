/*
 * Proyecto Simulador_Auto
 * Héctor Manuel Cervantes Rodríguez
 * A01571242
 * 02/12/2021
 */

 /*
 * Clase hija Deportivo, descendiente de la clase Carro, tiene un nuevo método, permite que el auto sea descapotable.
 */

#ifndef DEPORTIVO_H
#define DEPORTIVO_H

#include "Carro.h"

class Deportivo: public Carro{
  
  private: 
  //Declara las variables de instancia
  bool descapotable;

  public: 
    //Constuctor de la clase heredada de Carro, Deportivo. Como parametro pide el rendimiento.
    Deportivo(float rend): Carro(2,rend,false,0,false, 100){
      //declaramos la variable de instancia descapotable a false
      descapotable = false;

    }
    // Metodos miembros de la clase
    bool get_modo_convertible();
    float get_velocidad_promedio(); 
    float get_rendimiento_por_litro();
    void set_modo_convertible_on();
    void set_modo_convertible_off();
  
};

//Gettters

/**
*getter descapotable
*
*Devuelve la variable descapotable.
*/

bool Deportivo::get_modo_convertible(){

  return descapotable;

}

/**
*getter velocidad_promedio
*
*Devuelve la velocidad_promedio.
*/
float Deportivo::get_velocidad_promedio(){

  return velocidad_promedio;

}

/**
*getter rendimiento
*
*Devuelve la variable rendimiento.
*/
float Deportivo::get_rendimiento_por_litro(){
  
  return rendimiento;

}

//Setters

/**
*Setter descapotable a true
*Permite cambiar el valor de tipo bool descapotable a true.
*/
void Deportivo::set_modo_convertible_on(){

  descapotable = true;

}

/**
*Setter descapotable a false
*Permite cambiar el valor de tipo bool descapotable a true.
*/
void Deportivo::set_modo_convertible_off(){

  descapotable = false;
  
}


#endif