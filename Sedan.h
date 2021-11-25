#ifndef SEDAN_H
#define SEDAN_H

class Sedan : public Carro{

  private: 
    bool modo_ahorro_gas; 

  public:
    Sedan(float gas) : Carro(4,gas,false){
      modo_ahorro_gas = false;
    }

    bool get_modo_ahorro_gas();
    void set_modo_ahorro_gas_on();
    void set_modo_ahorro_gas_off();

};

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