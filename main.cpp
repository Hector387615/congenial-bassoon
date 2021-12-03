/*
* Proyecto Simulador_Auto
* Héctor Manuel Cervantes Rodríguez
* A01571242
* 02/12/2021
*/

/**
 * Descripcion: este es un proyecto demo para la clase de Pensamiento Computacional Orientado a Objetos.
 * Es un programa que ayuda al usuario a poder elegir la mejor opción de auto.
 * A partir de esto, permite que el usuario simule tener el auto y recorrer distancias 
 * para poder obtener el presupuesto real.
*/

//Bibliotecas
#include <iostream> //para imprimir.
#include "Motor.h" //donde estan los objetos de mi proyecto.
#include "Carro.h"
#include "Conductor.h"
#include "Deportivo.h"
#include "Sedan.h"
#include "Sedan.h"

//Función que nos permite imprimir la descripción del auto. Ejecutada cuando selecciona el usuario la opción 2.
void Descripcion_auto(float velocidad, float km_por_litro, float puertas_carro){

  std::cout << "\n-La velocidad promedio del auto es: " << velocidad << " kilometros por hora. \n";
  std::cout << "-El rendimiento es de: " << km_por_litro << " kilometros por litro.\n";
  std::cout << "-El auto tiene " << puertas_carro << " puertas.\n";

}

//Función que nos permite imprimir la descripción del motor. Ejecutada cuando selecciona el usuario la opción 8.
void Descripcion_motor(int cilindros, int valvulas){

  std::cout << "\n-El motor es de: " << cilindros << " cilindros. \n";
  std::cout << "-El motor tiene: " << valvulas << " valvulas.\n";

}

//Menu en caso de que el auto asignado sea deportivo
void menu_deportivo(){

  std::cout << "\nMenu:\n";
  std::cout << "1. Encender el auto o apagarlo (situación y conversión). \n";
  std::cout << "2. Descripción del auto y modificaciones. \n";
  std::cout << "3. Auto descapotable (estado y conversión). \n";
  std::cout << "4. Kilometraje del auto. \n";
  std::cout << "5. Recorrer distancia. \n";
  std::cout << "6. Servicio del auto (consultar estado y realizarlo cada 5000 km). \n";
  std::cout << "7. Terminar simulación (Estadísticas). \n";
  std::cout << "8. Datos del motor. \n";

}

//Menu en caso de que el auto asignado sea un Sedan
void menu_sedan(){

  std::cout << "\nMenu:\n";
  std::cout << "1. Encender el auto o apagarlo (situación y conversión). \n";
  std::cout << "2. Descripción del auto y modificaciones. \n";
  std::cout << "3. Ahorro de gasolina (estado y conversión). \n";
  std::cout << "4. Kilometraje del auto. \n";
  std::cout << "5. Recorrer distancia. \n";
  std::cout << "6. Servicio del auto (consultar estado y realizarlo cada 5000 km). \n";
  std::cout << "7. Terminar simulación (Estadísticas). \n";
  std::cout << "8. Datos del motor. \n";

}

int main(){

  //Variables que nos permitirán seleccionar la mejor opción de auto.
  float gasto_litro;
	int miembros_fam;

  //Pedimos al usuario que introduzca el valor de cada una de las variables.
  std::cout << "Introduce el rendimiento kilometros por litro de tu auto ideal:";
  std::cin >> gasto_litro;
  std::cout << "Introduce los miembros existentes en tu familia, incluyéndote.";
  std::cin >> miembros_fam;

  //Se crea el objeto chofer de la clase Conductor con los parámetros especificados por el usuario.
  Conductor chofer(gasto_litro, miembros_fam);

  //Evaluamos las variables del objeto Conductor para elegir su auto.
  if (gasto_litro > 15 || (gasto_litro <= 15 && miembros_fam > 2)){

    std::cout << "\n La mejor opción encontrada es un auto sedan. Puede transportar más de 2 pasajeros y tiene la opción para ahorrar gasolina.";
    
    //si se cumple esta condicional, se crea el objeto Nissan de la clase Sedan el parámetro requerido.
    Sedan Nissan(gasto_litro);

    //se crea con composición el motor.
    Nissan.crea_motor();

    //guardamos en una variable el motor.
    Motor motor_Nissan = Nissan.get_motor();

    //establecemos los cilindros del motor a 4 puesto que es un sedan.
    motor_Nissan.set_cilindros(4);

    std::cout << "\n Se te ha asignado un Nissan, Bienvenido. \n\n";

    //declaramos la var donde se guardará la opción introducida por el usuario
    int opcion;

    //mientras la opción no sea == 7, el menú continuará imprimiéndose.
    while (opcion != 7){

      //impresión menú
      menu_sedan();
      std::cout << "Introduce la opción deseada: ";

      //usuario introduce la opción
      std::cin >> opcion;

      //Opción 1, encender o apagar auto.
      if (opcion == 1){

        //variable tipo bool asiganda a un getter para verificar si está prendido el motor 
        bool motor_encendido = Nissan.get_motor_encendido();

        //Variable encargada de guardar la opción introducida por el usuario.
        int encender; 

        //si el motor se encuentra apagado:
        if (motor_encendido == 0){

          //opcion = 7 para que el menú principal no se imprima más
          opcion = 7;
          std::cout << "\nTu motor se encuentra apagado. ¿Quieres encenderlo? \n 1. Sí \n 2. No";

          //usuario introduce opción del menú
          std::cin >> encender;
          
          //si el usuario decide prender el motor
          if (encender == 1){

            //Usamos método setter para poner motor_encendido = true
            Nissan.set_motor_on();
            std::cout << "\nEl motor se encendió, regresarás al menú principal\n";

            //opción = 0 para que el menú principal se imprima
            opcion = 0;

          }

          //Si el usuario decide no prender el motor:
          else if (encender == 2){

            std::cout << "\nEl motor se mantendrá apagado, regresarás al menú principal\n";

            //opción = 0 para que el menú principal se imprima
            opcion = 0;

          }

        }

        //Si el motor se encuentra encendido:
        else if(motor_encendido == 1){

          std::cout << "\nTu motor se encuentra encendido. ¿Quieres apagarlo? \n 1. Sí \n 2. No";

          //guarda valor numérico introducido por el usuario. Decide si quiere apagar el motor.
          int apagar;

          //usuario introduce opción del menú
          std::cin >> apagar;

          //Si decide apagar el motor:
          if (apagar == 1){

            std::cout << "\nEl motor ha sido apagado, regresarás al menú principal.\n";

            //Usamos método setter para poner motor_encendido = false
            Nissan.set_motor_off();

            //opción = 0 para que el menú principal se imprima
            opcion = 0;

          }

          //Si decide no apagar el motor:
          else if (apagar == 2){

            std::cout << "\nEl motor se mantendrá encendido, regresarás al menú principal.\n";

            //opción = 0 para que el menú principal se imprima
            opcion = 0;

          }
        }
      }

      //Si el usuario selecciona la segunda opción del menú principal, descripción del auto
      else if(opcion == 2){

        //variables asignadas a métodos getters para obtener la información del auto.
        float velocidad = Nissan.get_velocidad_promedio();
        float km_por_litro = Nissan.get_rendimiento_por_litro();
        int puertas_carro = Nissan.get_puertas();

        /*
        *Se llama la función con los datos del auto, 
        *esta función se encarga de imprimir la descripción del auto.
        */
        Descripcion_auto(velocidad,km_por_litro,puertas_carro);

        //Variable que guarda la decisión del usuario conforme si quiere modificar al auto y qué parte.
        int modificar;

        //Si el usuario quiere modificar la velocidad, esta variable almacena el nuevo valor.
        float nueva_velocidad;

        //Si el usuario quiere modificar el rendimiento, esta variable almacena el nuevo rendimiento.
        float nuevo_rendimiento;

        //Si el usuario quiere modificar la cantidad de puertas, esta variable almacena la nueva cantidad.
        int nueva_puertas;

        std::cout << "\n ¿Quieres modificar alguna propiedad? \n 1. Velocidad \n 2. Rendimiento \n 3. Puertas \n 4. No";

        //pide al usuario que seleccione la opción del menú
        std::cin >> modificar;

        //Si el usuario decide modificar la velocidad
        if (modificar == 1){

          std::cout << "Introduce la nueva velocidad promedio del auto en (km/h)";

          //Pide al usuario que introduzca la nueva velocidad
          std::cin >> nueva_velocidad;

          //Usa el método setter para establecer nueva velocidad.
          Nissan.set_velocidad_promedio(nueva_velocidad);
          std::cout << "\nLa nueva velocidad del auto en (km/h) es de: " << nueva_velocidad << "\n";
          
        }

        //Si el usuario decide modificar el rendimiento
        else if(modificar == 2){

          std::cout << "Introduce el nuevo rendimiento de kilometros por litro: ";

          //Pide al usuario que introduzca el nuevo rendimiento
          std::cin >> nuevo_rendimiento;

          //Usa el método setter para establecer un nuevo rendimiento.
          Nissan.set_rendimiento_por_litro(nuevo_rendimiento);
          std::cout << "\nEl nuevo rendimiento del auto en (km/l) es de: " << nuevo_rendimiento << "\n";

        }

        //Si el usuario decide modificar el número de puertas
        else if(modificar == 3){

          std::cout << "Introduce el nuevo número de puertas: )";

          //Pide al usuario que introduzca la nueva cantidad de puertas 
          std::cin >> nueva_puertas;

          //Usa el método setter para establecer un nuevo número de puertas.
          Nissan.set_puertas(nueva_puertas);
          std::cout << "\nAhora el auto tiene: " << nueva_puertas << " puertas\n";

        }
        
      }

      //Si el usuario selecciona la opción 3 del menú principal, ahorro gasolina.
      else if(opcion == 3){

        //variable tipo bool guarda el estado del ahorro gasolina 
        bool ahorro_modo = Nissan.get_modo_ahorro_gas();

        //variable guarda opción introducida por el usuario a partir del menú
        int activar; 

        //ahorro_modo == 1, se encuentra activado el ahorro gasolina
        if (ahorro_modo == 1){

          opcion = 7;
          std::cout << "\nEl auto está en modo ahorro gasolina. ¿Quieres regresar al modo normal? \n 1. Sí \n 2. No";

          //pide al usuario la opción después de desplegar el menú
          std::cin >> activar;

          //si el usuario decide desactivar el modo ahorro gasolina
          if (activar == 1){

            //llama al método setter para poner el get_modo_ahorro_gas a false
            Nissan.set_modo_ahorro_gas_off();
            std::cout << "\nEl auto desactivó el modo ahorro gasolina, regresarás al menú principal\n";
            opcion = 0;

          }

          //si el usuario decide no apagar el modo ahorro gasolina
          else if (activar == 2){

            std::cout << "\nEl auto se mantendrá en modo ahorro gasolina, regresarás al menú principal\n";
            opcion = 0;

          }

        }

        //Si el auto tiene el modo ahorro gasolina desactivado 
        else if(ahorro_modo == 0){

          std::cout << "\nEl auto tiene desactivado el modo ahorro gasolina. ¿Quieres activarlo? \n 1. Sí \n 2. No";

          //Variable que guarda la opción introducida por el usuario
          int abrir;

          //Pide al usuario la opción después de desplegar el menú
          std::cin >> abrir;

          //opción 1, Si el usuario decide prender el modo ahorro gasolina
          if (abrir == 1){

            std::cout << "\nEl auto ahora está en modo ahorro gasolina, regresarás al menú principal.\n";

            //método setter encargado de poner modo_ahorro_gas = true
            Nissan.set_modo_ahorro_gas_on();
            opcion = 0;

          }

          //opción 2, si el usuario decide no activa el modo_ahorro_gas
          else if (abrir == 2){

            std::cout << "\nEl auto se mantendrá  en estado normal, regresarás al menú principal.\n";
            opcion = 0;

          }
        }
      }

      //Si el usuario selecciona la opción 4 del menú principal, obtiene kilometraje
      else if (opcion == 4){

        //km_auto guarda el valor de método getter el cual hace return a la distancia total
        float km_auto = Nissan.get_kilometraje();
        std::cout << "\n\nEl kilometraje del auto es: " << km_auto << " kilometros\n\n";

      }

      //Si el usuario selecciona la opción 5 del menú principal, simula recorrer una distancia.
      else if (opcion == 5){

        //Variable guarda la distancia a simular introducida por el usuario
        float km_recorrer;
        std::cout << "\nIntroduce la cantidad de kilometros a recorrer: ";

        //Pide al usuario la distancia a recorrer 
        std::cin >> km_recorrer;

        //Llama al método .recorri_km(kilometros a recorrer).
        Nissan.recorri_km(km_recorrer);
        
      }

      //Si el usuario selecciona la opción 6, realiza el servicio al carro.
      else if (opcion == 6){

        //Variable bool encargada de guardar true o false dependiendo de si requiere o no servicio.
        bool estado = Nissan.get_requiere_servicio();

        //variable que guarda la opción true o false después de desplegar el menú
        int realizar_serv; 

        //si el estado == 1, el auto sí requiere servicio
        if (estado == 1){

          opcion = 7;
          std::cout << "\nEl auto requiere servicio. ¿Quieres realizarlo? \n 1. Sí \n 2. No";
          
          //Pide al usuario la variable si decide o no realizar servicio.
          std::cin >> realizar_serv;
          
          //si la la opción == 1, decide realizar servicio
          if (realizar_serv == 1){

            //Llama al método .realizar_servicio(), encargado de realizar el servicio
            Nissan.realizar_servicio();
            std::cout << "\nEl servicio fue realizado, regresarás al menú principal\n";
            opcion = 0;

          }

          //si el usuario decide no realizar el servicio
          else if (realizar_serv == 2){

            std::cout << "\nEl auto se mantendrá en el estado actual, regresarás al menú principal\n";
            opcion = 0;

          }
        }

        //Si el auto no requiere servicio
        else if(estado == 0){

          std::cout << "\nEl auto no requiere servicio.\n"; 

        }
      }

      /*
      *Si el usuario selecciona la opción 7, termina la simulación contemplando la cantidad total *recorrida
      */
      else if (opcion == 7){

        Nissan.resumen_viaje();

      }

      //Si el usuario selecciona la opción 8, despliega la descripción del motor
      else if (opcion == 8){

        //variables las cuales con métodos getters 
        int cilindros = motor_Nissan.get_cilindros();
        int valvulas = motor_Nissan.get_valvulas();

        //Llama la función, encargada de desplegar la descripción del motor.
        Descripcion_motor(cilindros, valvulas);

        //variable que guarda la opción introducida por usuario después de desplegar el menú
        int modificar;

        //variable que guarda el nuevo valor de los cilindros introducidos por el usuario
        float nuevo_cilindro;

        //variable que guarda el nuevo valor de valvulas introducidos por el usuario
        float nuevo_valvulas;
        
        std::cout << "\n ¿Quieres modificar alguna propiedad? \n 1. Cilindros \n 2. Valvulas \n 3. No";

        //pide al usuario la opción que quiere del menú
        std::cin >> modificar;

        //si decide modificar la cantidad de cilindros
        if (modificar == 1){

          std::cout << "Introduce la nueva cantidad de cilindros.";

          //pide al usuario la nueva cantidad de cilindros 
          std::cin >> nuevo_cilindro;

          //método setter, establece la nueva cantidad de cilindros
          motor_Nissan.set_cilindros(nuevo_cilindro);
          std::cout << "\nEl motor ahora tiene: " << nuevo_cilindro << " cilindros. \n";
          
        }

        //Si se decide modificar el número de valvulas 
        else if(modificar == 2){

          //cantidad que almacena la nueva cantidad de valvulas introducidas
          int nuevo_valvulas;
           std::cout << "Introduce el nuevo número de valvulas: ";

           //Pide al usuario la nueva cantidad de valvulas
           std::cin >> nuevo_valvulas;

           //método setter, establece la nucve cantidad de valvulas
           motor_Nissan.set_valvulas(nuevo_valvulas);std::cout << "\nEl motor ahora tiene: " << nuevo_valvulas << " valvulas. \n";

        }
      }
  }
  }
  
  ///////////////////////////////////////////////////////////////


  //Evaluamos las variables del objeto Conductor para elegir su auto.
  else if(gasto_litro <= 15 && miembros_fam <= 2){

    std::cout << "\n La mejor opción encontrada para ti es un auto deportivo. Puede transportar 2 pasajeros y es descapotable.";

    //si se cumple esta condicional, se crea el objeto ferrari de la clase Deportivo con el parámetro requerido.
    Deportivo ferrari(gasto_litro);

    //se crea con composición el motor.
    ferrari.crea_motor();

    //guardamos en una variable el motor.
    Motor motor_ferrari = ferrari.get_motor();

    //establecemos los cilindros del motor a 6 puesto que es un deportivo.
    motor_ferrari.set_cilindros(6);

    std::cout << "\n Se te ha asignado un ferrari, Bienvenido. \n\n";


    //declaramos la var donde se guardará la opción introducida por el usuario
    int opcion;

    //mientras la opción no sea == 7, el menú continuará imprimiéndose.
    while (opcion != 7){

      //impresión menú
      menu_deportivo();
      std::cout << "Introduce la opción deseada: ";

      //usuario introduce la opción
      std::cin >> opcion;

      //Opción 1, encender o apagar auto.
      if (opcion == 1){

        //variable tipo bool asiganda a un getter para verificar si está prendido el motor 
        bool motor_encendido = ferrari.get_motor_encendido();

        //Variable encargada de guardar la opción introducida por el usuario.
        int encender; 

        //si el motor se encuentra apagado:
        if (motor_encendido == 0){

          //opcion = 7 para que el menú principal no se imprima más
          opcion = 7;
          std::cout << "\nTu motor se encuentra apagado. ¿Quieres encenderlo? \n 1. Sí \n 2. No";

          //usuario introduce opción del menú
          std::cin >> encender;
          
          //si el usuario decide prender el motor
          if (encender == 1){

            //Usamos método setter para poner motor_encendido = true
            ferrari.set_motor_on();
            std::cout << "\nEl motor se encendió, regresarás al menú principal\n";

            //opción = 0 para que el menú principal se imprima
            opcion = 0;

          }

          //Si el usuario decide no prender el motor:
          else if (encender == 2){

            std::cout << "\nEl motor se mantendrá apagado, regresarás al menú principal\n";

            //opción = 0 para que el menú principal se imprima
            opcion = 0;

          }

        }

        //Si el motor se encuentra encendido:
        else if(motor_encendido == 1){

          std::cout << "\nTu motor se encuentra encendido. ¿Quieres apagarlo? \n 1. Sí \n 2. No";

          //guarda valor numérico introducido por el usuario. Decide si quiere apagar el motor.
          int apagar;

          //usuario introduce opción del menú
          std::cin >> apagar;

          //Si decide apagar el motor:
          if (apagar == 1){

            std::cout << "\nEl motor ha sido apagado, regresarás al menú principal.\n";

            //Usamos método setter para poner motor_encendido = false
            ferrari.set_motor_off();

            //opción = 0 para que el menú principal se imprima
            opcion = 0;

          }

          //Si decide no apagar el motor:
          else if (apagar == 2){

            std::cout << "\nEl motor se mantendrá encendido, regresarás al menú principal.\n";

            //opción = 0 para que el menú principal se imprima
            opcion = 0;

          }
        }
      }

      //Si el usuario selecciona la segunda opción del menú principal, descripción del auto
      else if(opcion == 2){

        //variables asignadas a métodos getters para obtener la información del auto.
        float velocidad = ferrari.get_velocidad_promedio();
        float km_por_litro = ferrari.get_rendimiento_por_litro();
        int puertas_carro = ferrari.get_puertas();

        /*
        *Se llama la función con los datos del auto, 
        *esta función se encarga de imprimir la descripción del auto.
        */
        Descripcion_auto(velocidad,km_por_litro,puertas_carro);

        //Variable que guarda la decisión del usuario conforme si quiere modificar al auto y qué parte.
        int modificar;

        //Si el usuario quiere modificar la velocidad, esta variable almacena el nuevo valor.
        float nueva_velocidad;

        //Si el usuario quiere modificar el rendimiento, esta variable almacena el nuevo rendimiento.
        float nuevo_rendimiento;

        //Si el usuario quiere modificar la cantidad de puertas, esta variable almacena la nueva cantidad.
        int nueva_puertas;

        std::cout << "\n ¿Quieres modificar alguna propiedad? \n 1. Velocidad \n 2. Rendimiento \n 3. Puertas \n 4. No";

        //pide al usuario que seleccione la opción del menú
        std::cin >> modificar;

        //Si el usuario decide modificar la velocidad
        if (modificar == 1){

          std::cout << "Introduce la nueva velocidad promedio del auto en (km/h)";

          //Pide al usuario que introduzca la nueva velocidad
          std::cin >> nueva_velocidad;

          //Usa el método setter para establecer nueva velocidad.
          ferrari.set_velocidad_promedio(nueva_velocidad);
          std::cout << "\nLa nueva velocidad del auto en (km/h) es de: " << nueva_velocidad << "\n";
          
        }

        //Si el usuario decide modificar el rendimiento
        else if(modificar == 2){

          std::cout << "Introduce el nuevo rendimiento de kilometros por litro: ";

          //Pide al usuario que introduzca el nuevo rendimiento
          std::cin >> nuevo_rendimiento;

          //Usa el método setter para establecer un nuevo rendimiento.
          ferrari.set_rendimiento_por_litro(nuevo_rendimiento);
          std::cout << "\nEl nuevo rendimiento del auto en (km/l) es de: " << nuevo_rendimiento << "\n";

        }

        //Si el usuario decide modificar el número de puertas
        else if(modificar == 3){

          std::cout << "Introduce el nuevo número de puertas: )";

          //Pide al usuario que introduzca la nueva cantidad de puertas 
          std::cin >> nueva_puertas;

          //Usa el método setter para establecer un nuevo número de puertas.
          ferrari.set_puertas(nueva_puertas);
          std::cout << "\nAhora el auto tiene: " << nueva_puertas << " puertas\n";

        }
        
      }

      //Si el usuario selecciona la opción 3 del menú principal, convertir auto descapotable o a normal.
      else if(opcion == 3){

        //variable tipo bool guarda el estado del auto si está descapotado o no 
        bool descap = ferrari.get_modo_convertible();

        //variable guarda opción introducida por el usuario a partir del menú
        int descapotar; 

        //descap == 1, se encuentra descapotado el auto
        if (descap == 1){

          opcion = 7;
          std::cout << "\nEl auto está descapotado. ¿Quieres regresar al modo normal? \n 1. Sí \n 2. No";

          //pide al usuario la opción después de desplegar el menú
          std::cin >> descapotar;
          
          //si el usuario decide regresar el techo a la normalidad 
          if (descapotar == 1){

            //llama al método setter para poner el modo convertible a false
            ferrari.set_modo_convertible_off();
            std::cout << "\nEl techo regresó a su normalidad, regresarás al menú principal\n";
            opcion = 0;

          }

          //si el usuario decide no regresar al modo normal
          else if (descapotar == 2){

            std::cout << "\nEl techo se mantendrá descapotado, regresarás al menú principal\n";
            opcion = 0;

          }

        }

        //Si el auto tiene el modo descapotado desactivado
        else if(descap == 0){

          std::cout << "\nEl techo se encuentra en estado normal. ¿Quieres descapotarlo? \n 1. Sí \n 2. No";

          //Variable que guarda la opción introducida por el usuario
          int cerrar;

          //Pide al usuario la opción después de desplegar el menú
          std::cin >> cerrar;

          //opción 1, Si el usuario decide descapotar el auto 
          if (cerrar == 1){

            std::cout << "\nEl auto ahora está descapotado, regresarás al menú principal.\n";

            //método setter encargado de poner modo_descapotado = true
            ferrari.set_modo_convertible_on();
            opcion = 0;

          }

          //opción 2, si el usuario decide no descapotar el auto
          else if (cerrar == 2){

            std::cout << "\nEl techo se mantendrá en estado normal, regresarás al menú principal.\n";
            opcion = 0;

          }
        }
      }

      //Si el usuario selecciona la opción 4 del menú principal, obtiene kilometraje
      else if (opcion == 4){

        //km_auto guarda el valor de método getter el cual hace return a la distancia total
        float km_auto = ferrari.get_kilometraje();
        std::cout << "\n\nEl kilometraje del auto es: " << km_auto << " kilometros\n\n";

      }

      //Si el usuario selecciona la opción 5 del menú principal, simula recorrer una distancia.
      else if (opcion == 5){

        //Variable guarda la distancia a simular introducida por el usuario
        float km_recorrer;
        std::cout << "\nIntroduce la cantidad de kilometros a recorrer: ";

        //Pide al usuario la distancia a recorrer 
        std::cin >> km_recorrer;

        //Llama al método .recorri_km(kilometros a recorrer).
        ferrari.recorri_km(km_recorrer);
        
      }

      //Si el usuario selecciona la opción 6, realiza el servicio al carro.
      else if (opcion == 6){

        //Variable bool encargada de guardar true o false dependiendo de si requiere o no servicio.
        bool estado = ferrari.get_requiere_servicio();

        //variable que guarda la opción true o false después de desplegar el menú
        int realizar_serv; 

        //si el estado == 1, el auto sí requiere servicio
        if (estado == 1){

          opcion = 7;
          std::cout << "\nEl auto requiere servicio. ¿Quieres realizarlo? \n 1. Sí \n 2. No";
          
          //Pide al usuario la variable si decide o no realizar servicio.
          std::cin >> realizar_serv;
          
          //si la la opción == 1, decide realizar servicio
          if (realizar_serv == 1){

            //Llama al método .realizar_servicio(), encargado de realizar el servicio
            ferrari.realizar_servicio();
            std::cout << "\nEl servicio fue realizado, regresarás al menú principal\n";
            opcion = 0;

          }

          //si el usuario decide no realizar el servicio
          else if (realizar_serv == 2){

            std::cout << "\nEl auto se mantendrá en el estado actual, regresarás al menú principal\n";
            opcion = 0;

          }
        }

        //Si el auto no requiere servicio
        else if(estado == 0){

          std::cout << "\nEl auto no requiere servicio.\n"; 

        }
      }

       /*
      *Si el usuario selecciona la opción 7, termina la simulación contemplando la cantidad total recorrida
      */
      else if (opcion == 7){

        ferrari.resumen_viaje();

      }

      else if (opcion == 8){

        //variables las cuales con métodos getters 
        int cilindros = motor_ferrari.get_cilindros();
        int valvulas = motor_ferrari.get_valvulas();

        //Llama la función, encargada de desplegar la descripción del motor.
        Descripcion_motor(cilindros, valvulas);

        //variable que guarda la opción introducida por usuario después de desplegar el menú
        int modificar;

        //variable que guarda el nuevo valor de los cilindros introducidos por el usuario
        float nuevo_cilindro;

        //variable que guarda el nuevo valor de valvulas introducidos por el usuario
        float nuevo_valvulas;
        
        std::cout << "\n ¿Quieres modificar alguna propiedad? \n 1. Cilindros \n 2. Valvulas \n 3. No";

        //pide al usuario la opción que quiere del menú
        std::cin >> modificar;

        //si decide modificar la cantidad de cilindros
        if (modificar == 1){

          std::cout << "Introduce la nueva cantidad de cilindros.";

          //pide al usuario la nueva cantidad de cilindros 
          std::cin >> nuevo_cilindro;

          //método setter, establece la nueva cantidad de cilindros
          motor_ferrari.set_cilindros(nuevo_cilindro);
          std::cout << "\nEl motor ahora tiene: " << nuevo_cilindro << " cilindros. \n";
          
        }

        //Si se decide modificar el número de valvulas 
        else if(modificar == 2){

          //cantidad que almacena la nueva cantidad de valvulas introducidas
          int nuevo_valvulas;
           std::cout << "Introduce el nuevo número de valvulas: ";

           //Pide al usuario la nueva cantidad de valvulas
           std::cin >> nuevo_valvulas;

           //método setter, establece la nucve cantidad de valvulas
           motor_ferrari.set_valvulas(nuevo_valvulas);std::cout << "\nEl motor ahora tiene: " << nuevo_valvulas << " valvulas. \n";

        }
      }

      }

  }
  return 0;
  
}
