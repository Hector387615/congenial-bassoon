/*
 * Proyecto Simulador_Auto
 * Héctor Manuel Cervantes Rodríguez
 * A01571242
 * 02/12/2021
 */

/*
 * Clase hija Sedan, descendiente de la clase Carro, tiene un nuevo método, 
 *permite que el auto active el modo ahorar gasolina, es funcional, mejora el rendimiento del auto.
 */
#ifndef SEDAN_H
#define SEDAN_H

#include "Carro.h"

class Sedan : public Carro{

  private: 
    //Declara las variables de instancia
    bool modo_ahorro_gas; 

  public:
    //Constuctor de la clase heredada de Carro, Sedan. Como parametro pide el rendimiento.
    Sedan(float rend) : Carro(4,rend,false,0,0,80){
      //declaramos la variable de instancia modo_ahorro_gas a false
      modo_ahorro_gas = false;
    }
    // Metodos miembros de la clase
    float get_rendimiento_por_litro();
    float get_velocidad_promedio();
    bool get_modo_ahorro_gas(); 
    void set_modo_ahorro_gas_on();
    void set_modo_ahorro_gas_off();
    float resumen_viaje();

};

//Gettters

/**
*getter rendimiento
*Evalua el valor de la variable tipo bool modo_ahorro_gas y a partir de ello,
*Devuelve la variable rendimiento normal o con un rendimiento más alto.
*/
float  Sedan::get_rendimiento_por_litro(){
  //Si la variable modo_ahorro_gas == true, el rendimiento mejora, es decir, es mayor.
  if (modo_ahorro_gas == true){

    rendimiento = rendimiento + 3;
    return rendimiento;

  }
  
  //Si la variable modo_ahorro_gas == false, el rendimiento es el mismo al inicial
  else if(modo_ahorro_gas == false){

    return rendimiento;

  }
  
  return 0.0;

}

/**
*getter velocidad_promedio
*
*Devuelve la variable velocidad_promedio.
*/
float Sedan::get_velocidad_promedio(){

  return velocidad_promedio;

}

/**
*getter modo_ahorro_gas
*
*Devuelve la variable modo_ahorro_gas.
*/
bool Sedan::get_modo_ahorro_gas(){

  return modo_ahorro_gas;

}

//Setters
/**
*setter modo_ahorro_gas = false
*
*Establece el valor de la variable tipo bool modo_ahorro_gas a false.
*/
void Sedan::set_modo_ahorro_gas_off(){

  modo_ahorro_gas = false;

}

/**
*setter modo_ahorro_gas = true
*
*Establece el valor de la variable tipo bool modo_ahorro_gas a true.
*/
void Sedan::set_modo_ahorro_gas_on(){

  modo_ahorro_gas = true;

}
 
/**
*Sobreescritura del método resumen_viaje de la clase Carro.
*Despliega la distancia total recorrida por el auto y el rendimiento con el que lo hizo.
*Pide al usuario que especifique el costo por litro de la gasolina que utilizó.
*Verifica si el modo modo_ahorro_gas es true para mejorar el rendimiento y que el precio disminuya.
*Despliega el gasto total del viaje a partir de una operación matemática.
*/
float Sedan::resumen_viaje(){

  //Desplegamos la distancia total y rendimento.
  std::cout<< "\nHas recorrido " << distancia << " kilometros." << " Con un rendimiento de: "<< rendimiento << " kilometros por litro.\n";

  //Pedimos al usuario costo_litro. 
  std::cout << "\n Especifica el costo por litro de la gasolina utilizada en pesos mexicanos: ";
  float costo_litro;
  std::cin >> costo_litro;
  std::cout << "\n Con un costo por litro de: " << costo_litro << " pesos mexicanos.";

  //Checamos si el modo_ahorro_gas es true.
  if (modo_ahorro_gas == 1){

    //Mejoramos el rendimiento del auto.
    rendimiento = rendimiento + 3;

  }

  else {

    //Si no es true, el rendimiento permanece igual
    rendimiento = rendimiento;

  }  

  //operacion matematica para sacar el gasto_total_viaje.
  float gasto_total_viaje = (distancia/rendimiento) * costo_litro;
  //Desplegamos el costo.

  std::cout << "\n El gasto total del viaje fue de: "<< gasto_total_viaje << " pesos mexicanos.";

  return 0;
  
}

#endif