#pragma once
#include "String.h"
using namespace System::Drawing;

class Moneda
{
private:
    int x, y;
    int W, H; //W=width H=Height
    int indice_columnas;//para las columnas del sprite
    char* archivo_imagen;//para el nombre de archivo de la imagen
public:
    Moneda(int width, int height);
    ~Moneda();
    void cambia_imagen(Graphics^ lienzo, Bitmap^ imagen);

    //metodos de acceso
    void setX(int valor);
    void setY(int valor);
    void setW(int valor);
    void setH(int valor);

    Rectangle getRectangulo();

    int getX();
    int getY();
    int getW();
    int getH();

};

//IMPLEMENTACION DE LA CLASE
Moneda::Moneda(int W, int H)
{
    this->W = W;
    this->H = H;
    x = y = 0;
    archivo_imagen = new char[30];//para el nombre de archivo del sprite
    indice_columnas = 0;
}

Moneda::~Moneda()
{

}

void Moneda::cambia_imagen(Graphics^ lienzo, Bitmap^ imagen)
{
    lienzo->DrawImage(imagen, x, y, W*0.08, H*0.08);
}

Rectangle Moneda::getRectangulo() {
    return Rectangle(x, y, W*0.08, H * 0.02);
}

void Moneda::setX(int valor) { x = valor; }
void Moneda::setY(int valor) { y = valor; }
void Moneda::setW(int valor) { W = valor; }
void Moneda::setH(int valor) { H = valor; }
int  Moneda::getX() { return x; }
int  Moneda::getY() { return y; }
int  Moneda::getW() { return W; }
int  Moneda::getH() { return H; }