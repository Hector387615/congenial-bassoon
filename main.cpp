/*
 * Proyecto Simulador_Auto
 * Héctor Manuel Cervantes Rodríguez
 * A01571242
 * 02/12/2021
 */
 
#include <iostream>
#include <iostream>
#include "Motor.h"
#include "Carro.h"
#include "Conductor.h"
#include "Deportivo.h"
#include "Sedan.h"

void Descripcion_auto(float velocidad, float km_por_litro, float puertas_carro){
  std::cout << "\n-La velocidad promedio del auto es: " << velocidad << " kilometros por hora. \n";
  std::cout << "-El rendimiento es de: " << km_por_litro << " kilometros por litro.\n";
  std::cout << "-El auto tiene " << puertas_carro << " puertas.\n";
}

void Descripcion_motor(int cilindros, int valvulas){
  std::cout << "\n-El motor es de: " << cilindros << " cilindros. \n";
  std::cout << "-El motor tiene: " << valvulas << " valvulas.\n";
}

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

  float gasto_litro;
	int miembros_fam;

  std::cout << "Introduce el rendimiento kilometros por litro";
  std::cin >> gasto_litro;
  std::cout << "Introduce los miembros existentes en tu familia, incluyéndote.";
  std::cin >> miembros_fam;

  Conductor chofer(gasto_litro, miembros_fam);

  if (gasto_litro > 15 || (gasto_litro <= 15 && miembros_fam > 2)){

    std::cout << "\n La mejor opción encontrada es un auto sedan. Puede transportar más de 2 pasajeros y tiene la opción para ahorrar gasolina.";

    Sedan Nissan(gasto_litro);
    Nissan.crea_motor();
    Motor motor_Nissan = Nissan.get_motor();
    motor_Nissan.set_cilindros(4);

    std::cout << "\n Se te ha asignado un Nissan, Bienvenido. \n\n";

    int opcion;

    while (opcion != 7){
      menu_sedan();
      std::cout << "Introduce la opción deseada: ";
      std::cin >> opcion;

      if (opcion == 1){
        bool motor_encendido = Nissan.get_motor_encendido();
        int encender; 

        if (motor_encendido == 0){
          opcion = 7;
          std::cout << "\nTu motor se encuentra apagado. ¿Quieres encenderlo? \n 1. Sí \n 2. No";
          std::cin >> encender;
          
          if (encender == 1){
            Nissan.set_motor_on();
            std::cout << "\nEl motor se encendió, regresarás al menú principal\n";
            opcion = 0;
          }
          else if (encender == 2){
            std::cout << "\nEl motor se mantendrá apagado, regresarás al menú principal\n";
            opcion = 0;
          }

        }
        else if(motor_encendido == 1){
          std::cout << "\nTu motor se encuentra encendido. ¿Quieres apagarlo? \n 1. Sí \n 2. No";
          int apagar;
          std::cin >> apagar;

          if (apagar == 1){
            std::cout << "\nEl motor ha sido apagado, regresarás al menú principal.\n";
            Nissan.set_motor_off();
            opcion = 0;

          }
          else if (apagar == 2){
            std::cout << "\nEl motor se mantendrá encendido, regresarás al menú principal.\n";
            opcion = 0;
          }
        }
      }
      else if(opcion == 2){
        float velocidad = Nissan.get_velocidad_promedio();
        float km_por_litro = Nissan.get_rendimiento_por_litro();
        int puertas_carro = Nissan.get_puertas();

        Descripcion_auto(velocidad,km_por_litro,puertas_carro);

        int modificar;
        float nueva_velocidad;
        float nuevo_rendimiento;
        int nueva_puertas;

        std::cout << "\n ¿Quieres modificar alguna propiedad? \n 1. Velocidad \n 2. Rendimiento \n 3. Puertas \n 4. No";
        std::cin >> modificar;
        if (modificar == 1){
          std::cout << "Introduce la nueva velocidad promedio del auto en (km/h)";
          std::cin >> nueva_velocidad;
          Nissan.set_velocidad_promedio(nueva_velocidad);
          std::cout << "\nLa nueva velocidad del auto en (km/h) es de: " << nueva_velocidad << "\n";
          
        }
        else if(modificar == 2){
          std::cout << "Introduce el nuevo rendimiento de kilometros por litro: ";
          std::cin >> nuevo_rendimiento;
          Nissan.set_rendimiento_por_litro(nuevo_rendimiento);
          std::cout << "\nEl nuevo rendimiento del auto en (km/l) es de: " << nuevo_rendimiento << "\n";
        }

        else if(modificar == 3){
          std::cout << "Introduce el nuevo número de puertas: )";
          std::cin >> nueva_puertas;
          Nissan.set_puertas(nueva_puertas);
          std::cout << "\nAhora el auto tiene: " << nueva_puertas << " puertas\n";
        }
        
      }
      else if(opcion == 3){
        bool ahorro_modo = Nissan.get_modo_ahorro_gas();
        int activar; 

        if (ahorro_modo == 1){
          opcion = 7;
          std::cout << "\nEl auto está en modo ahorro gasolina. ¿Quieres regresar al modo normal? \n 1. Sí \n 2. No";
          std::cin >> activar;
          
          if (activar == 1){
            Nissan.set_modo_ahorro_gas_off();
            std::cout << "\nEl auto desactivó el modo ahorro gasolina, regresarás al menú principal\n";
            opcion = 0;
          }
          else if (activar == 2){
            std::cout << "\nEl auto se mantendrá en modo ahorro gasolina, regresarás al menú principal\n";
            opcion = 0;
          }

        }
        else if(ahorro_modo == 0){
          std::cout << "\nEl auto tiene desactivado el modo ahorro gasolina. ¿Quieres activarlo? \n 1. Sí \n 2. No";
          int abrir;
          std::cin >> abrir;

          if (abrir == 1){
            std::cout << "\nEl auto ahora está en modo ahorro gasolina, regresarás al menú principal.\n";
            Nissan.set_modo_ahorro_gas_on();
            opcion = 0;

          }
          else if (abrir == 2){
            std::cout << "\nEl auto se mantendrá  en estado normal, regresarás al menú principal.\n";
            opcion = 0;
          }
        }
      }

      else if (opcion == 4){
        float km_auto = Nissan.get_kilometraje();
        std::cout << "\n\nEl kilometraje del auto es: " << km_auto << " kilometros\n\n";

      }
      else if (opcion == 5){
        float km_recorrer;
        std::cout << "\nIntroduce la cantidad de kilometros a recorrer: ";
        std::cin >> km_recorrer;
        Nissan.recorri_km(km_recorrer);
        
      }

      else if (opcion == 6){
        bool estado = Nissan.get_requiere_servicio();
        int realizar_serv; 

        if (estado == 1){
          opcion = 7;
          std::cout << "\nEl auto requiere servicio. ¿Quieres realizarlo? \n 1. Sí \n 2. No";
          std::cin >> realizar_serv;
          
          if (realizar_serv == 1){
            Nissan.realizar_servicio();
            std::cout << "\nEl servicio fue realizado, regresarás al menú principal\n";
            opcion = 0;
          }
          else if (realizar_serv == 2){
            std::cout << "\nEl auto se mantendrá en el estado actual, regresarás al menú principal\n";
            opcion = 0;
          }
        }
        else if(estado == 0){
          std::cout << "\nEl auto no requiere servicio.\n"; 
        }
      }
      else if (opcion == 7){
        Nissan.resumen_viaje();
      }
      else if (opcion == 8){
        {
        int cilindros = motor_Nissan.get_cilindros();
        int valvulas = motor_Nissan.get_valvulas();

        Descripcion_motor(cilindros, valvulas);


        int modificar;
        float nuevo_cilindro;
        float nuevo_valvulas;
        

        std::cout << "\n ¿Quieres modificar alguna propiedad? \n 1. Cilindros \n 2. Valvulas \n 3. No";
        std::cin >> modificar;
        if (modificar == 1){
          std::cout << "Introduce la nueva cantidad de cilindros.";
          std::cin >> nuevo_cilindro;
          motor_Nissan.set_cilindros(nuevo_cilindro);
          std::cout << "\nEl motor ahora tiene: " << nuevo_cilindro << " cilindros. \n";
          
        }
        else if(modificar == 2){
          int nuevo_valvulas;
           std::cout << "Introduce el nuevo número de valvulas: ";
           std::cin >> nuevo_valvulas;
           motor_Nissan.set_valvulas(nuevo_valvulas);std::cout << "\nEl motor ahora tiene: " << nuevo_valvulas << " valvulas. \n";
        }
        
      }
      }
  }
  }
  ///////////////////////////////////////////////////////////////



  else if(gasto_litro <= 15 && miembros_fam <= 2){
    std::cout << "\n La mejor opción encontrada para ti es un auto deportivo. Puede transportar 2 pasajeros y es descapotable.";

    Deportivo ferrari(gasto_litro);
    ferrari.crea_motor();
    Motor motor_ferrari = ferrari.get_motor();
    motor_ferrari.set_cilindros(6);

    std::cout << "\n Se te ha asignado un ferrari, Bienvenido. \n\n";

    int opcion;

    while (opcion != 7){
      menu_deportivo();
      std::cout << "Introduce la opción deseada: ";
      std::cin >> opcion;

      if (opcion == 1){
        bool motor_encendido = ferrari.get_motor_encendido();
        int encender; 

        if (motor_encendido == 0){
          opcion = 7;
          std::cout << "\nTu motor se encuentra apagado. ¿Quieres encenderlo? \n 1. Sí \n 2. No";
          std::cin >> encender;
          
          if (encender == 1){
            ferrari.set_motor_on();
            std::cout << "\nEl motor se encendió, regresarás al menú principal\n";
            opcion = 0;
          }
          else if (encender == 2){
            std::cout << "\nEl motor se mantendrá apagado, regresarás al menú principal\n";
            opcion = 0;
          }

        }
        else if(motor_encendido == 1){
          std::cout << "\nTu motor se encuentra encendido. ¿Quieres apagarlo? \n 1. Sí \n 2. No";
          int apagar;
          std::cin >> apagar;

          if (apagar == 1){
            std::cout << "\nEl motor ha sido apagado, regresarás al menú principal.\n";
            ferrari.set_motor_off();
            opcion = 0;

          }
          else if (apagar == 2){
            std::cout << "\nEl motor se mantendrá encendido, regresarás al menú principal.\n";
            opcion = 0;
          }
        }
      }

      else if(opcion == 2){
        float velocidad = ferrari.get_velocidad_promedio();
        float km_por_litro = ferrari.get_rendimiento_por_litro();
        int puertas_carro = ferrari.get_puertas();

        Descripcion_auto(velocidad,km_por_litro,puertas_carro);

        int modificar;
        float nueva_velocidad;
        float nuevo_rendimiento;
        int nueva_puertas;

        std::cout << "\n ¿Quieres modificar alguna propiedad? \n 1. Velocidad \n 2. Rendimiento \n 3. Puertas \n 4. No";
        std::cin >> modificar;
        if (modificar == 1){
          std::cout << "Introduce la nueva velocidad promedio del auto en (km/h)";
          std::cin >> nueva_velocidad;
          ferrari.set_velocidad_promedio(nueva_velocidad);
          std::cout << "\nLa nueva velocidad del auto en (km/h) es de: " << nueva_velocidad << "\n";
          
        }
        else if(modificar == 2){
          std::cout << "Introduce el nuevo rendimiento de kilometros por litro: ";
          std::cin >> nuevo_rendimiento;
          ferrari.set_rendimiento_por_litro(nuevo_rendimiento);
          std::cout << "\nEl nuevo rendimiento del auto en (km/l) es de: " << nuevo_rendimiento << "\n";
        }

        else if(modificar == 3){
          std::cout << "Introduce el nuevo número de puertas: )";
          std::cin >> nueva_puertas;
          ferrari.set_puertas(nueva_puertas);
          std::cout << "\nAhora el auto tiene: " << nueva_puertas << " puertas\n";
        }
        
      }

      else if(opcion == 3){
        bool descap = ferrari.get_modo_convertible();
        int descapotar; 

        if (descap == 1){
          opcion = 7;
          std::cout << "\nEl auto está descapotado. ¿Quieres regresar al modo normal? \n 1. Sí \n 2. No";
          std::cin >> descapotar;
          
          if (descapotar == 1){
            ferrari.set_modo_convertible_off();
            std::cout << "\nEl techo regresó a su normalidad, regresarás al menú principal\n";
            opcion = 0;
          }
          else if (descapotar == 2){
            std::cout << "\nEl techo se mantendrá descapotado, regresarás al menú principal\n";
            opcion = 0;
          }

        }
        else if(descap == 0){
          std::cout << "\nEl techo se encuentra en estado normal. ¿Quieres descapotarlo? \n 1. Sí \n 2. No";
          int cerrar;
          std::cin >> cerrar;

          if (cerrar == 1){
            std::cout << "\nEl auto ahora está descapotado, regresarás al menú principal.\n";
            ferrari.set_modo_convertible_on();
            opcion = 0;

          }
          else if (cerrar == 2){
            std::cout << "\nEl techo se mantendrá en estado normal, regresarás al menú principal.\n";
            opcion = 0;
          }
        }
      }
      else if (opcion == 4){
        float km_auto = ferrari.get_kilometraje();
        std::cout << "\n\nEl kilometraje del auto es: " << km_auto << " kilometros\n\n";

      }
      else if (opcion == 5){
        float km_recorrer;
        std::cout << "\nIntroduce la cantidad de kilometros a recorrer: ";
        std::cin >> km_recorrer;
        ferrari.recorri_km(km_recorrer);
        
      }
      else if (opcion == 6){
        bool estado = ferrari.get_requiere_servicio();
        int realizar_serv; 

        if (estado == 1){
          opcion = 7;
          std::cout << "\nEl auto requiere servicio. ¿Quieres realizarlo? \n 1. Sí \n 2. No";
          std::cin >> realizar_serv;
          
          if (realizar_serv == 1){
            ferrari.realizar_servicio();
            std::cout << "\nEl servicio fue realizado, regresarás al menú principal\n";
            opcion = 0;
          }
          else if (realizar_serv == 2){
            std::cout << "\nEl auto se mantendrá en el estado actual, regresarás al menú principal\n";
            opcion = 0;
          }

        }
        else if(estado == 0){
          std::cout << "\nEl auto no requiere servicio.\n"; 

        }
      }
      else if (opcion == 7){
        ferrari.resumen_viaje();
      }
      else if (opcion == 8){
        {
        int cilindros = motor_ferrari.get_cilindros();
        int valvulas = motor_ferrari.get_valvulas();

        Descripcion_motor(cilindros, valvulas);

        int modificar;
        int nuevo_cilindro;
        int nuevo_valvulas;
        
        std::cout << "\n ¿Quieres modificar alguna propiedad? \n 1. Cilindros \n 2. Valvulas \n 3. No";
        
        std::cin >> modificar;
        if (modificar == 1){
          std::cout << "Introduce la nueva cantidad de cilindros.";
          std::cin >> nuevo_cilindro;
          motor_ferrari.set_cilindros(nuevo_cilindro);
          std::cout << "\nEl motor ahora tiene: " << nuevo_cilindro << " cilindros. \n";
          
        }
        else if(modificar == 2){
          std::cout << "Introduce el nuevo número de valvulas: ";
          std::cin >> nuevo_valvulas;
          motor_ferrari.set_valvulas(nuevo_valvulas);
          std::cout << "\nEl motor ahora tiene: " << nuevo_valvulas << " valvulas. \n";
        }
        
      }
      }

      }

  }
  return 0;
  
}
