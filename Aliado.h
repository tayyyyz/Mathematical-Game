#pragma once
#include "String.h"
#include "Entidad.h"
using namespace System::Drawing;

using namespace System::Windows::Forms;
class Aliado : public Entidad
{
private:

	Rectangle posicion; Rectangle porcionAUsar;
public:
	Aliado();
	~Aliado();
	void cambia_dx_dy(Direccion teclapulsada, Graphics^ lienzo);

	void cambia_imagen(char* nombre_archivo);
	void mostrar_imagen(Graphics^ lienzo);
	void mover_imagen(Graphics^ lienzo, Direccion teclapulsada);
	Rectangle getRectangulo();
	//metodos de acceso
	void setX(int valor);
	void setY(int valor);
	void setW(int valor);
	void setH(int valor);

	int getX();
	int getY();
	int getW();
	int getH();

};

//IMPLEMENTACION DE LA CLASE
Aliado::Aliado()
{
	x = y = 0;
	dx = 0;//significa que el sprite empezará moviendose a la derecha
	dy = 0;
	archivo_imagen = new char[30];//para el nombre de archivo del sprite
	indidce_filas = indice_columnas = 0;

}
Aliado::~Aliado()
{

}

void Aliado::cambia_dx_dy(Direccion teclapulsada, Graphics^ lienzo)
{

	switch (teclapulsada)
	{
	case Arriba:
		if (y > 34)
		{
			dy = -10; dx = 0; break;
		}
	case Abajo:
		if (y + H < lienzo->VisibleClipBounds.Height) {
			dy = 10;	 dx = 0;	break;
		}
	case Izquierda:
		if (x > 0) {
			dy = 0;  dx = -10; break;
		}
	case Derecha:
		if (x + W < lienzo->VisibleClipBounds.Width)
		{
			dy = 0;  dx = 10;	break;
		}
	case Ninguno:	dx = 0;  dy = 0; 	break;
	}


}

void Aliado::cambia_imagen(char* nombre_archivo)
{
	//copia la ruta que llega en el parametro nombre_archivo al atributo archivo_imagen
	strcpy(archivo_imagen, nombre_archivo); // "avatar.png"

	//se carga la imagen... es decir lee la imagen y la sube a memoria
	Bitmap^ mi_sprite = gcnew Bitmap(gcnew System::String(archivo_imagen));
	//por tanto mi_sprite tiene la imagen, el sprite

	//Se obtiene el W y H de cada cuadro o frame
	W = mi_sprite->Width / 4;//ancho de cada cuadro
	H = mi_sprite->Height / 4;//alto de cada cuadro

	delete mi_sprite;
}

void Aliado::mostrar_imagen(Graphics^ lienzo)
{
	//carga la imagen

	Bitmap^ mi_sprite = gcnew Bitmap(gcnew System::String(archivo_imagen));

	//se obtien el reactangulo
	Rectangle cuadro = Rectangle(indice_columnas * W, indidce_filas * H, W, H);

	//zoom
	Rectangle zoom = Rectangle(x, y, W * 1.5, H * 1.5);

	//Dibuja la imagen
	lienzo->DrawImage(mi_sprite, zoom, cuadro, GraphicsUnit::Pixel);

}

void Aliado::mover_imagen(Graphics^ lienzo, Direccion teclapulsada)
{


	if (teclapulsada == Arriba) indidce_filas = 3;
	if (teclapulsada == Abajo) indidce_filas = 0;
	if (teclapulsada == Derecha) indidce_filas = 2;
	if (teclapulsada == Izquierda) indidce_filas = 1;

	indice_columnas++;
	if (indice_columnas > 3) indice_columnas = 0;
	x += dx;

	y += dy;

	//mostrar
	mostrar_imagen(lienzo);
}
Rectangle Aliado::getRectangulo() {
	return Rectangle(x, y, W, H);
}
void Aliado::setX(int valor) { x = valor; }
void Aliado::setY(int valor) { y = valor; }
void Aliado::setW(int valor) { W = valor; }
void Aliado::setH(int valor) { H = valor; }
int  Aliado::getX() { return x; }
int  Aliado::getY() { return y; }
int  Aliado::getW() { return W; }
int  Aliado::getH() { return H; }
