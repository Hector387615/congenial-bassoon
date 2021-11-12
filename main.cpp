
#include <iostream>
#include "Conductor.h"
#include "Carro.h"
#include "Motor.h"


int main(){
  //situación 1

  //objeto 1
  Conductor chofer_1(1, 2500);

  float gasto_gas = chofer_1.get_gasto();
  int familia = chofer_1.get_miembros_familia();


  if (familia <= 4 && familia > 1 && gasto_gas >= 2000){
    //objeto 2
    Carro carro1(4,2000);
    float gasta = carro1.get_gasto_gasolina();
    int puer = carro1.get_puertas();

    //objeto 3
    Motor motor1(4, 2000);
    int cil = motor1.get_cilindros();
    float consume = motor1.get_consumo_gasolina_pesos();

    std::cout << "Tu mejor opción dado el tamaño de tu familia"<< "\n" <<  "es un auto con "<< puer << " puertas " << "y "<<cil << " cilindros," << "\n"<<"con un consumo de gasolina de " << gasta << " pesos mensuales.";

    
  }
  //situación 2
  else if (familia <= 2 && gasto_gas > 2000){
    Carro carro2(2,3000);
    float gasta = carro2.get_gasto_gasolina();
    int puer = carro2.get_puertas();

    //objeto 3
    Motor motor2(6, 3000);
    int cil = motor2.get_cilindros();
    float consume = motor2.get_consumo_gasolina_pesos();

    std::cout << "Tu mejor opción dado el tamaño de tu familia"<< "\n" <<  "es un auto con "<< puer << " puertas " << "y "<<cil << " cilindros," << "\n"<<"con un consumo de gasolina de " << gasta << " pesos mensuales.";
  }
  
}