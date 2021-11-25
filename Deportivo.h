#ifndef DEPORTIVO_H
#define DEPORTIVO_H

#include "Carro.h"

class Deportivo: public Carro{
  
  private: 
  bool descapotable;

  public: 
  Deportivo(float gas): Carro(2,gas,false){
    descapotable = false;
  }

  bool get_modo_convertible();
  void set_modo_convertible_on();
  void set_modo_convertible_off();
  
};

bool Deportivo::get_modo_convertible(){
  return descapotable;
}

void Deportivo::set_modo_convertible_on(){
  descapotable = true;
}

void Deportivo::set_modo_convertible_off(){
  descapotable = true;
}


#endif