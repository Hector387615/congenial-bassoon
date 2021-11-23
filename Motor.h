#ifndef MOTOR_H
#define MOTOR_H

class Motor{
  private:
    int cilindros;
    float consumo_gasolina_pesos;
    bool motor_encendido;

  public:
    Motor():cilindros(4), consumo_gasolina_pesos(1600), motor_encendido(false){};
    Motor(int cilin, float consumo, bool mot): cilindros(cilin), consumo_gasolina_pesos(consumo), motor_encendido(mot){};

    int get_cilindros();
    float get_consumo_gasolina_pesos();
    bool get_motor_encendido();

    void set_cilindros(int );
    void set_consumo_gasolina_pesos(float );
    void set_motor_encendido(bool);
};

int Motor::get_cilindros(){
  return cilindros;
}

float Motor::get_consumo_gasolina_pesos(){
  return consumo_gasolina_pesos;
}

bool Motor::get_motor_encendido(){
  return motor_encendido;
}

void Motor::set_cilindros(int cilin){
  cilindros = cilin;
}

void Motor::set_consumo_gasolina_pesos(float consumo){
  consumo_gasolina_pesos = consumo;
}

void Motor::set_motor_encendido(bool mot){
  motor_encendido = mot;
}
#endif