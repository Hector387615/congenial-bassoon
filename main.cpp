
#include <iostream>
#include "Motor.h"
#include "Carro.h"
#include "Conductor.h"

int main(){
  Carro carrito(4,1600,false);  
  std::cout << carrito.get_motor_descompuesto();
  carrito.crea_motor();
  Motor motor_del_carro = carrito.get_motor();
  std::cout << motor_del_carro.get_cilindros();

  std::cout << "acaba";
  Conductor chofer(1600,0);
  std::cout << chofer.get_gasto();
  chofer.crea_carro();
  Carro carro_creado = chofer.get_carro();
  std::cout << carro_creado.get_gasto_gasolina();
  
  
  
  
}

