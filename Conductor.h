#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Carro.h"
#include "Motor.h"

class Conductor{
private:
  float gasto;
	int miembros_familia;
  Carro carrito;

public:
  Conductor():gasto(1600), miembros_familia(0){}; 
  Conductor(float gast, int miem): gasto(gast), miembros_familia(miem){};

  float get_gasto();
  int get_miembros_familia();

  void set_gasto(float );
  void set_miembros_familia(int);
  void crea_carro();

  Carro get_carro();

};

Carro Conductor::get_carro(){
  return carrito;
}
void Conductor::crea_carro() {
  Carro m1(4,1600,false);
  carrito = m1;
}

float Conductor::get_gasto(){
  return gasto;
}

int Conductor::get_miembros_familia(){
  return miembros_familia;
}

void Conductor::set_gasto(float gast){
  gasto = gast;
}

void Conductor::set_miembros_familia(int miem){
  miembros_familia = miem;
}


#endif