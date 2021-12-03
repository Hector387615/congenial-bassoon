/*
 * Proyecto Simulador_Auto
 * Héctor Manuel Cervantes Rodríguez
 * A01571242
 * 02/12/2021
 */

/*
 * Clase Motor, composición de carro, contiene getters y setters para obtener la información del motor o establecer nuevos.
 */
#ifndef MOTOR_H
#define MOTOR_H

class Motor{

  private:
    //Declara las variables de instancia
    int cilindros;
    int valvulas;

  public:
    //Constuctor predeterminado del objeto Motor.
    Motor():cilindros(4), valvulas(16){};
    //Constuctor a partir de parámetros introducidos.
    Motor(int cilin, int val): cilindros(cilin), valvulas(val){};
    // Metodos miembros de la clase
    int get_cilindros();
    float get_valvulas();
    void set_cilindros(int );
    void set_valvulas(int );
    
};

//Gettters

/**
*getter clindros
*
*Devuelve la variable cilindros.
*/
int Motor::get_cilindros(){

  return cilindros;

}

/**
*getter valvulas
*
*Devuelve la variable valvulas.
*/
float Motor::get_valvulas(){

  return valvulas;

}

//Setters

/**
*Setter cilindros
*Permite cambiar el valor de tipo int cilindros.
*/
void Motor::set_cilindros(int cilin){

  cilindros = cilin;

}

/**
*Setter valvulas
*Permite cambiar el valor de tipo int valvulas.
*/
void Motor::set_valvulas(int val){

  valvulas = val;
  
}


#endif