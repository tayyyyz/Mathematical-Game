#pragma once

#include <cstdlib> 
#include <ctime> 

class OperacionMatematica {
private:
    int num1, num2;
    char simbolo;
    bool llave;

public:
    OperacionMatematica();
    ~OperacionMatematica();

    void setNum1(double num1);
    void setNum2(double num2);

    bool getLlave();
    void setLlave(bool llave);

    double generarNumero3();

    double getNum1();
    double getNum2();

    double generarEjercicio();
    void setSimbolo(char simbolo);
    char getSimbolo();
};

// Implementacion 

OperacionMatematica::OperacionMatematica() {
    srand(static_cast<unsigned int>(time(0)));
    num1 = num2 = 0;
    llave = false;
}

OperacionMatematica::~OperacionMatematica() {

}

void OperacionMatematica::setNum1(double num1) {
    this->num1 = num1;
}
void OperacionMatematica::setNum2(double num2) {
    this->num2 = num2;
}

void OperacionMatematica::setSimbolo(char simbolo) {
    this->simbolo = simbolo;
}

char OperacionMatematica::getSimbolo() {
    return simbolo;
}

double OperacionMatematica::getNum1() {
    return num1;
}
double OperacionMatematica::getNum2() {
    return num2;
}

void OperacionMatematica::setLlave(bool llave) {
    this->llave = llave;
}

bool OperacionMatematica::getLlave() {
    return llave;
}


double OperacionMatematica::generarEjercicio() {
    num1 = rand() % 100;
    num2 = rand() % 100;
    double num3 = generarNumero3();

    // (1: suma, 2: resta, 3: multiplicación, 4: división)
    int operacion = rand() % 4 + 1;

    double resultado = 0.0;

    switch (operacion) {
    case 1: // Suma
        setSimbolo('+');
        resultado = num1 + num2;
        break;
    case 2: // Resta
        setSimbolo('-');
        resultado = num1 - num2;
        break;
    case 3: // Multiplicación
        setSimbolo('*');
        resultado = num1 * num2;
        break;
    case 4: // División
        num1 = num3;
        num2 = 2;
        setSimbolo('/');
        resultado = num1 / num2;       
        break;
    default:
        break;
    }

    return resultado;
}

double OperacionMatematica::generarNumero3() {
    int n3;
    n3 = rand() % 100 - 1; // Número aleatorio entre 1 y 100
    if (n3 % 2 == 0) {
        return n3;
    }
    else {
        generarNumero3();
    }
}

