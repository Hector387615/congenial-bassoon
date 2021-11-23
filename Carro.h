#ifndef CARRO_H
#define CARRO_H

#include "Motor.h"

class Carro{
  private:
    int puertas;
    float gasto_gasolina;
    bool motor_descompuesto;
    Motor motor_carro;
    

  public:
    Carro():puertas(4),gasto_gasolina(1600),motor_descompuesto(false){};

    Carro(int puert, float gas, bool desc):puertas(puert), gasto_gasolina(gas), motor_descompuesto(desc){};

    int get_puertas();
    float get_gasto_gasolina();
    bool get_motor_descompuesto();
    Motor get_motor();

    void set_puertas(int);
    void set_gasto_gasolina(float);
    void set_motor_descompuesto(bool);
    void crea_motor();

    
};

Motor Carro::get_motor(){
  return motor_carro;
}

int Carro::get_puertas(){
  return puertas;
}

float Carro::get_gasto_gasolina(){
  return gasto_gasolina;
}

bool Carro::get_motor_descompuesto(){
  return motor_descompuesto;
}

void Carro::set_puertas(int puert){
  puertas = puert;
}

void Carro::set_gasto_gasolina(float gas){
  gasto_gasolina = gas;
}

void Carro::set_motor_descompuesto(bool desc){
  motor_descompuesto = desc;
}

void Carro::crea_motor() {
  Motor m1(4,1600,false);
  motor_carro = m1;
}


#endif