/*
 * Proyecto Simulador_Auto
 * Héctor Manuel Cervantes Rodríguez
 * A01571242
 * 02/12/2021
 */

/*
 * Clase Conductor, crea el carro, ya sea Deportivo o Sedan. 
 */
#ifndef MOTOR_H
#define MOTOR_H

class Motor{


  private:
    int cilindros;
    int valvulas;

  public:
    Motor():cilindros(4), valvulas(16){};
    Motor(int cilin, int val): cilindros(cilin), valvulas(val){};

    int get_cilindros();
    float get_valvulas();
    void set_cilindros(int );
    void set_valvulas(int );
    
};

int Motor::get_cilindros(){

  return cilindros;

}

float Motor::get_valvulas(){

  return valvulas;

}

void Motor::set_cilindros(int cilin){

  cilindros = cilin;

}

void Motor::set_valvulas(int val){

  valvulas = val;
  
}


#endif