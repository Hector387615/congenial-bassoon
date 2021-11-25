
#include <iostream>
#include "Motor.h"
#include "Carro.h"
#include "Conductor.h"
#include "Deportivo.h"
#include "Sedan.h"

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
  
  std::cout << "acabaaaa";
  Deportivo ferrari(1300);
  std::cout << ferrari.get_motor_descompuesto();
  std::cout << ferrari.get_modo_convertible();
  ferrari.set_modo_convertible_on();
  std::cout << ferrari.get_modo_convertible();

  std::cout << "\n\n crea sedan";
  Sedan coche_normal(299);
  std::cout << coche_normal.get_modo_ahorro_gas();
  coche_normal.set_modo_ahorro_gas_on();
  std::cout << coche_normal.get_modo_ahorro_gas();
  coche_normal.crea_motor();
  Motor motor_coche2 = coche_normal.get_motor();
  std::cout << motor_coche2.get_cilindros();


  
  
}

