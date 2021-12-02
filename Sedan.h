/*
 * Proyecto Simulador_Auto
 * Héctor Manuel Cervantes Rodríguez
 * A01571242
 * 02/12/2021
 */

/*
 * Clase Conductor, crea el carro, ya sea Deportivo o Sedan. 
 */
#ifndef SEDAN_H
#define SEDAN_H

#include "Carro.h"

class Sedan : public Carro{

  private: 
    bool modo_ahorro_gas; 

  public:
    Sedan(float rend) : Carro(4,rend,false,0,0,80){
      modo_ahorro_gas = false;
    }
    bool get_modo_ahorro_gas();
    float get_velocidad_promedio(); 
    float get_rendimiento_por_litro();
    void set_modo_ahorro_gas_on();
    void set_modo_ahorro_gas_off();
    float resumen_viaje();

};

//Sobre escritura
float Sedan::resumen_viaje(){

  std::cout<< "\nHas recorrido " << distancia << " kilometros." << " Con un rendimiento de: "<< rendimiento << " kilometros por litro.\n"; 

  std::cout << "\n Especifica el costo por litro de la gasolina utilizada en pesos mexicanos: ";
  float costo_litro;
  std::cin >> costo_litro;
  std::cout << "\n Con un costo por litro de: " << costo_litro << " pesos mexicanos.";

  if (modo_ahorro_gas == 1){

    rendimiento = rendimiento + 3;
  }
  else {
    rendimiento = rendimiento;
  }  

  float gasto_total_viaje = (distancia/rendimiento) * costo_litro;
  
  std::cout << "\n El gasto total del viaje fue de: "<< gasto_total_viaje << " pesos mexicanos.";

  return 0;
  
}

float  Sedan::get_rendimiento_por_litro(){

  if (modo_ahorro_gas == true){
    rendimiento = rendimiento + 3;
    return rendimiento;
  }
  else if(modo_ahorro_gas == false){
    return rendimiento;

  }
  return 0.0;

}

float Sedan::get_velocidad_promedio(){

  return velocidad_promedio;

}

bool Sedan::get_modo_ahorro_gas(){

  return modo_ahorro_gas;

}

void Sedan::set_modo_ahorro_gas_off(){

  modo_ahorro_gas = false;

}

void Sedan::set_modo_ahorro_gas_on(){

  modo_ahorro_gas = true;

}


#endif