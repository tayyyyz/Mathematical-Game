#pragma once
#include "ctime"
#include "cstdlib"
#include "Entidad.h"
#include "String.h"
using namespace System::Drawing;

class Enemigo : public Entidad
{
private:

public:
	Enemigo(int W, int H);
	~Enemigo();
	void cambia_imagen(char* nombre_archivo);
	void mostrar_imagen(Graphics^ lienzo, Bitmap^ image);
	void mover_imagen(Graphics^ lienzo);
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
Enemigo::Enemigo(int W, int H)
{
	this->W = W;
	this->H = H;
	this->x = rand() % 700;
	this->y = rand() % 700 - 30;
	dx = 25;//significa que el sprite empezará moviendose a la derecha
	dy = 25;
	archivo_imagen = new char[30];//para el nombre de archivo del sprite
	indidce_filas = indice_columnas = 0;

}
Enemigo::~Enemigo()
{}



void Enemigo::cambia_imagen(char* nombre_archivo)
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

void Enemigo::mostrar_imagen(Graphics^ lienzo, Bitmap^ image)
{
	//carga la imagen
	//Bitmap^ mi_sprite = gcnew Bitmap(gcnew System::String(archivo_imagen));

	//se obtien el reactangulo
	Rectangle cuadro = Rectangle(indice_columnas * W, indidce_filas * H, W, H);

	//zoom
	Rectangle zoom = Rectangle(x, y, W / 0.4, H / 0.4);

	//Dibuja la imagen
	lienzo->DrawImage(image, zoom, cuadro, GraphicsUnit::Pixel);

}

void Enemigo::mover_imagen(Graphics^ lienzo)
{
	if (x + dx < 1)
	{
		dx *= -1;
		indidce_filas = 2;
	}
	if (x + dx + W > lienzo->VisibleClipBounds.Width) {
		dx *= -1;
		indidce_filas = 1;
	}
	if (y + dy < 37)
	{
		dy *= -1;
		indidce_filas = 0;
	}
	if (y + dy + H > lienzo->VisibleClipBounds.Height)
	{
		dy *= -1;
		indidce_filas = 3;
	}


	indice_columnas++;
	if (indice_columnas > 3) indice_columnas = 0;
	x += dx;

	y += dy;

	////mostrar
	//mostrar_imagen(lienzo);
}
Rectangle Enemigo::getRectangulo() {
	return Rectangle(x, y, W, H);
}
void Enemigo::setX(int valor) { x = valor; }
void Enemigo::setY(int valor) { y = valor; }
void Enemigo::setW(int valor) { W = valor; }
void Enemigo::setH(int valor) { H = valor; }
int  Enemigo::getX() { return x; }
int  Enemigo::getY() { return y; }
int  Enemigo::getW() { return W; }
int  Enemigo::getH() { return H; }