/*
 * Proyecto Simulador_Auto
 * Héctor Manuel Cervantes Rodríguez
 * A01571242
 * 02/12/2021
 */

 /*
 * Clase Carro, crea el objeto motor (composición),
 * contiene métodos para simular el funcionamiento de un auto. 
 *Simula el recorrido de una *distancia, permite realizar el servicio al auto, 
 *ofrece un resumen al finalizar la simulacion.  
 *Tiene 2 clases hijas (Sedan y Deportivo) 
 */
 
#ifndef CARRO_H
#define CARRO_H

#include "Motor.h"

class Carro{
  

  protected: 
  /*
  * Declara las variables de tipo protected, 
  * pueden ser usadas por la herencia de la misma.
  */

    float velocidad_promedio;
    float costo_litro;
    float distancia;
    float rendimiento;
    bool motor_encendido;

  private:
    //Declara las variables de instancia
    int puertas;
    bool motor_descompuesto;
    Motor motor_carro;
    float servicio;
    
    
    

  public:
    //Constuctor Default
    Carro():puertas(4),rendimiento(8),motor_descompuesto(false), distancia(0), motor_encendido(false), velocidad_promedio(80){};
    //Constuctor a partir de parámetros introducidos.
    Carro(int puert, float rend, bool desc, float dist, bool mot, float vel):puertas(puert), rendimiento(rend), motor_descompuesto(desc), distancia(dist), motor_encendido(mot), velocidad_promedio(vel){};
    // Metodos miembros de la clase
    int get_puertas();
    bool get_requiere_servicio();
    bool get_motor_encendido();
    Motor get_motor();
    float get_rendimiento_por_litro();
    float get_velocidad_promedio();
    float get_kilometraje();
    void set_puertas(int);
    void set_motor_descompuesto(bool);
    void set_motor_on();
    void set_motor_off();
    void set_rendimiento_por_litro(float);
    void set_velocidad_promedio(float);
    void crea_motor();
    void recorri_km(float);
    void realizar_servicio();
    float resumen_viaje();

    
};

//Gettters

/**
*getter puertas
*
*Devuelve la variable puertas, parametro especificado 
*al crear el objeto Conductor.
*
*/
int Carro::get_puertas(){
  
  return puertas;

}

/**
*getter motor_descompuesto
*Devuelve la variable de tipo bool motor_descompuesto.
*/
bool Carro::get_requiere_servicio(){

  return motor_descompuesto;

}

/**
*getter motor_encendido
*Devuelve la variable de tipo bool motor_encendido.
*/
bool Carro::get_motor_encendido(){

  return motor_encendido;

}

/**
*getter motor_carro
*Devuelve el objeto Motor creado con composición.
*/
Motor Carro::get_motor(){

  return motor_carro;

}

/**
*getter rendimento
*Devuelve la variable rendimiento.
*/
float Carro::get_rendimiento_por_litro(){

  return rendimiento;
  std::cout<<"km por litro";

}

/**
*getter velocidad_promedio
*Devuelve la variable velocidad_promedio.
*/
float Carro::get_velocidad_promedio(){

  return velocidad_promedio;
  std::cout<<"km por hora";

}

/**
*getter distancia
*Devuelve la variable distancia.
*/
float Carro::get_kilometraje(){

  return distancia;

}

/**
*Permite cambiar el valor de tipo int puertas.
*/
void Carro::set_puertas(int puert){

  puertas = puert;

}

/**
*Permite cambiar el valor de tipo float rendimiento.
*/
void Carro::set_rendimiento_por_litro(float rend){

  rendimiento = rend;

}

/**
*Permite cambiar el valor de tipo bool motor_descompuesto.
*/
void Carro::set_motor_descompuesto(bool desc){

  motor_descompuesto = desc;

}

/**
*Permite cambiar el valor de tipo bool motor_encendido a true.
*/
void Carro::set_motor_on(){

  motor_encendido = true;

}

/**
*Permite cambiar el valor de tipo bool motor_descompuesto a false.
*/
void Carro::set_motor_off(){

  motor_encendido = false;

}

/**
*Permite cambiar el valor de tipo float velocidad_promedio.
*/
void Carro::set_velocidad_promedio(float vel){

  velocidad_promedio = vel;

}

/**
*Simula un viaje del auto. 
*Recibe el parametro float dist, (la distancia recorrida a simular).
*Para que el auto pueda avanzar, se valida que el motor no esté descompuesto o apagado.
*A la variable distancia, también referida como kilometraje, se le suma la nueva dist recorrida.
*A la variable servicio se le asigna el valor de distancia, esto ocurre porque cuando se realice el 
*servicio, podremos reiniciar la variable servicio sin afectar distancia o kilometraje.
*/
void Carro::recorri_km(float dist){
  //Condicional, valida que el motor no esté descompuesto o apagado.
  if (motor_descompuesto == false &&  motor_encendido == true){
    //sumamos dist a distancia para guardar la distancia total.
    distancia += dist;
    std::cout<< "has recorrido " << dist <<" km \n";
    /**
    *Asignamos servicio = distancia para cuando llamemos al método realizar_servicio(), 
    *declarar servicio = 0 sin afectar la distancia total.
    */
    servicio = distancia;
    //Si servicio excede los 5000 km, declaramos el motor como descompuesto.
   if (servicio >= 5000){
      motor_descompuesto = true;

    
    }
  }
  //Si el motor se encuentra funcional y el auto está apagado:
  else if (motor_descompuesto == false && motor_encendido == false) {
    std::cout << "\nDebes encender el motor para poder avanzar.\n";
  }

  //Si el motor se encuentra descompuesto:
  else {
    std::cout << "\nDebes realizar el servicio al auto para poder avanzar.\n";
  }

}

/**
*Reinicia la variable servicio a 0, y la varibale de tipo bool motor_descompuesto a false.
*/
void Carro::realizar_servicio(){

  servicio = 0;
  motor_descompuesto = false;

}

/**
*Constuctor por Default de mi objeto a crear de clase Motor.
*/
void Carro::crea_motor() {

  Motor m1(4,8);
  motor_carro = m1;

}

/**
*Despliega la distancia total recorrida por el auto y el rendimiento con el que lo hizo.
*Pide al usuario que especifique el costo por litro de la gasolina que utilizó
*Despliega el gasto total del viaje a partir de una operación matemática.
*/
float Carro::resumen_viaje(){
  //Desplegamos la distancia total y rendimento.
  std::cout<< "\nHas recorrido " << distancia << " kilometros." << " Con un rendimiento de: "<< rendimiento << " kilometros por litro.\n"; 
  //Pedimos al usuario costo_litro.
  std::cout << "\n Especifica el costo por litro de la gasolina utilizada en pesos mexicanos: ";
  float costo_litro;
  std::cin >> costo_litro;
  std::cout << "\n Con un costo por litro de: " << costo_litro << " pesos mexicanos.";
  //operacion matematica para sacar el gasto_total_viaje.
  float gasto_total_viaje = (distancia/rendimiento) * costo_litro;
  //Desplegamos el costo.
  std::cout << "\n El gasto total del viaje fue de: "<< gasto_total_viaje << " pesos mexicanos.";

  return 0;
  
}

#endif