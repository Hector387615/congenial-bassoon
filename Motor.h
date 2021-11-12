class Motor{
  private:
    int cilindros;
    float consumo_gasolina_pesos;

  public:
    Motor():cilindros(4), consumo_gasolina_pesos(1600){};
    Motor(int cilin, float consumo): cilindros(cilin), consumo_gasolina_pesos(consumo){};

    int get_cilindros();
    float get_consumo_gasolina_pesos();

    void set_cilindros(int );
    void set_consumo_gasolina_pesos(float );
};

int Motor::get_cilindros(){
  return cilindros;
}

float Motor::get_consumo_gasolina_pesos(){
  return consumo_gasolina_pesos;
}

void Motor::set_cilindros(int cilin){
  cilindros = cilin;
}

void Motor::set_consumo_gasolina_pesos(float consumo){
  consumo_gasolina_pesos = consumo;
}