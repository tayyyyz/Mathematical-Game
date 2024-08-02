#pragma once
#include "String.h"
#include "Entidad.h"
using namespace System::Drawing;
using namespace System::Windows::Forms;

class Personaje : public Entidad
{
private:
	Rectangle posicion; Rectangle porcionAUsar;
	int vidas;
	int monedas;
public:
	Personaje();
	~Personaje();
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

	void setVidas(int vidas);
	int getVidas();

	void setMonedas(int monedas);
	int getMonedas();

	int getX();
	int getY();
	int getW();
	int getH();

};

//IMPLEMENTACION DE LA CLASE
Personaje::Personaje()
{
	x = y = 0;
	dx = 0;//significa que el sprite empezará moviendose a la derecha
	dy = 0;
	archivo_imagen = new char[30];//para el nombre de archivo del sprite
	indidce_filas = indice_columnas = 0;
	vidas = 3;
	monedas = 0;

}
Personaje::~Personaje()
{}

void Personaje::cambia_dx_dy(Direccion teclapulsada, Graphics^ lienzo)
{

	switch (teclapulsada)
	{
	case Arriba:
		if (y > 35)
		{
			dy = -15; dx = 0; break;
		}
	case Abajo:
		if (y + H < lienzo->VisibleClipBounds.Height) {
			dy = 15;	 dx = 0;	break;
		}
	case Izquierda:
		if (x > 0) {
			dy = 0;  dx = -15; break;
		}
	case Derecha:
		if (x + W < lienzo->VisibleClipBounds.Width)
		{
			dy = 0;  dx = 15;	break;
		}
	case Ninguno:	dx = 0;  dy = 0; 	break;
	}


}

void Personaje::cambia_imagen(char* nombre_archivo)
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

void Personaje::mostrar_imagen(Graphics^ lienzo)
{
	//carga la imagen
	Bitmap^ mi_sprite = gcnew Bitmap(gcnew System::String(archivo_imagen));

	//se obtien el reactangulo
	Rectangle cuadro = Rectangle(indice_columnas * W, indidce_filas * H, W, H);

	//zoom
	Rectangle zoom = Rectangle(x, y, W * 1.5, H * 1.5);

	//Dibuja la imagen
	lienzo->DrawImage(mi_sprite, zoom, cuadro, GraphicsUnit::Pixel);
	//Negrita texto

}

void Personaje::mover_imagen(Graphics^ lienzo, Direccion teclapulsada)
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
Rectangle Personaje::getRectangulo() {
	return Rectangle(x, y, W, H);
}
void Personaje::setX(int valor) { x = valor; }
void Personaje::setY(int valor) { y = valor; }
void Personaje::setW(int valor) { W = valor; }
void Personaje::setH(int valor) { H = valor; }
void Personaje::setVidas(int value) {
	this->vidas += vidas;
}
int Personaje::getVidas() {
	return vidas;
}

void Personaje::setMonedas(int monedas) {
	this->monedas += monedas;
}
int Personaje::getMonedas() {
	return monedas;
}
int  Personaje::getX() { return x; }
int  Personaje::getY() { return y; }
int  Personaje::getW() { return W; }
int  Personaje::getH() { return H; }
