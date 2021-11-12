
class Conductor{
private:
  float gasto;
	int miembros_familia;

public:
  Conductor():gasto(1600), miembros_familia(0){}; 
  Conductor(int miem, float gast): miembros_familia(miem), gasto(gast){};

  float get_gasto();
  int get_miembros_familia();

  void set_gasto(float );
  void set_miembros_familia(int);

};


float Conductor::get_gasto(){
  return gasto;
}

int Conductor::get_miembros_familia(){
  return miembros_familia;
}

void Conductor::set_gasto(float gast){
  gasto = gast;
}

void Conductor::set_miembros_familia(int miem){
  miembros_familia = miem;
}
