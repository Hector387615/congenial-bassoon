class Carro{
  private:
    int puertas;
    float gasto_gasolina;

  public:
    Carro():puertas(2), gasto_gasolina(1600){};
    Carro(int puert, float gas): puertas(puert), gasto_gasolina(gas){};

    int get_puertas();
    float get_gasto_gasolina();

    void set_puertas(int);
    void set_gasto_gasolina(float);

    void devaluo(float);

};

int Carro::get_puertas(){
  return puertas;
}

float Carro::get_gasto_gasolina(){
  return gasto_gasolina;
}

void Carro::set_puertas(int puert){
  puertas = puert;
}

void Carro::set_gasto_gasolina(float gas){
  gasto_gasolina = gas;
}

//función devaluo
void devaluo Carro:: devaluo(float )