#pragma once
using namespace System::Drawing;
enum Direccion { Arriba, Abajo, Izquierda, Derecha, Ninguno };
class Entidad {
protected:
	int x, y;
	int dx, dy;
	int W, H;
	int indidce_filas;
	int indice_columnas;
	char* archivo_imagen;
public:
	Entidad();
	~Entidad();
	virtual void cambia_imagen(char* nombre_archivo);
	virtual void mostrar_imagen(Graphics^ lienzo);
	virtual void mover_imagen(Graphics^ lienzo, Direccion teclapulsada);
};

Entidad::Entidad() { }
Entidad::~Entidad() { }
void Entidad::cambia_imagen(char* nombre_archivo) { }
void Entidad::mostrar_imagen(Graphics^ lienzo) { }
void Entidad::mover_imagen(Graphics^ lienzo, Direccion teclapulsada) { }
