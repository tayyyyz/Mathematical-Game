#pragma once
#include <vector>
#include "Moneda.h"
#include "Jugador.h"
#include "Enemigo.h"
#include "Aliado.h"

using namespace std;

class GameService {
private:
	vector<Enemigo*> enemigos;
	int cantidadEnemigos1;
	int cantidadEnemigos2;
	int vidasAliado1;
	int vidasAliado2;
	int vidasPersonaje;
	int monedasPersonaje;
	int puntaje;
public:
	GameService();
	~GameService();

	void agregarEnemigo(int width, int height);
	//void agregarMonedas(Moneda* moneda);

	void dibujarEnemigo(Graphics^ lienzo, Bitmap^ imgEnemigo);
	//void dibujarMonedas(Graphics^ lienzo, Bitmap^ imgMoneda);
	void agregarEnemigo2(int width, int height);
	void pintarEstadisticas(Graphics^ lienzo);
	void moverTodo(Graphics^ panel, Direccion tecla, Personaje* personaje, Direccion tecla2);
	bool colisionAliadoEnemigo(Graphics^ lienzo, Aliado* aliado);
	bool colisionPersonajeEnemigo(Graphics^ lienzo, Personaje* personaje);
	bool colisionPersonajeMoneda(Graphics^ lienzo, Personaje* personaje, Moneda* moneda);
	bool colisionAliadoMoneda(Graphics^ lienzo, Aliado* aliado, Moneda* moneda);
	void setVidas(int pVidas);
	void setPuntaje(int pPuntaje);
	int getVidas();
	int getPuntaje();
};

// Implementacion


GameService::GameService() {
	cantidadEnemigos1 = 2;
	cantidadEnemigos2 = 4;
	vidasPersonaje = 2;
	monedasPersonaje = 0;
	this->vidasAliado1 = 1;
	this->vidasAliado2 = 1;
	this->puntaje = 0;
}
GameService::~GameService() {

}

void GameService::pintarEstadisticas(Graphics^ lienzo) {
	Font^ vidasFont = gcnew System::Drawing::Font("PixelFontFamily", 12, FontStyle::Bold);
	Font^ monedasFont = gcnew System::Drawing::Font("PixelFontFamily", 12, FontStyle::Bold);
	//Mostrar el numero de vidas
	lienzo->DrawString("Vidas: " + (getVidas()), vidasFont, Brushes::White, 800, 50);

	//Mostrar el numero de monedas
	lienzo->DrawString("Monedas: " + (getPuntaje()), monedasFont, Brushes::White, 690, 50);
}

void GameService::agregarEnemigo(int width, int height) {
	for (int i = 0; i < cantidadEnemigos1; i++)
	{
		Enemigo* enemigo = new Enemigo(width, height);
		enemigos.push_back(enemigo);
	}
}

void GameService::agregarEnemigo2(int width, int height) {
	for (int i = 0; i < cantidadEnemigos2; i++)
	{
		Enemigo* enemigo = new Enemigo(width, height);
		enemigos.push_back(enemigo);
	}
}

void GameService::dibujarEnemigo(Graphics^ panel, Bitmap^ imageEnemy) {
	for (int i = 0; i < enemigos.size(); i++)
	{
		enemigos[i]->mostrar_imagen(panel, imageEnemy);
	}
}

void GameService::moverTodo(Graphics^ panel, Direccion tecla, Personaje* personaje, Direccion tecla2) {
	for (int i = 0; i < enemigos.size(); i++)
	{
		enemigos[i]->mover_imagen(panel);
	}

	//llama a la funcion cambiadxdy
	personaje->cambia_dx_dy(tecla, panel);

	//mover personaje
	personaje->mover_imagen(panel, tecla);
}

bool GameService::colisionPersonajeEnemigo(Graphics^ lienzo, Personaje* personaje) {
	for (int i = 0; i < enemigos.size(); i++)
	{
		if (personaje->getRectangulo().IntersectsWith(enemigos[i]->getRectangulo()))
		{
			personaje->setX(lienzo->VisibleClipBounds.Width/2); personaje->setY(lienzo->VisibleClipBounds.Height / 2);
			pintarEstadisticas(lienzo);
			setVidas(getVidas() - 1);
			return true;

		}
		if (vidasPersonaje <= 0) {
			return false;
			
		}
	}
}

bool GameService::colisionAliadoEnemigo(Graphics^ lienzo, Aliado* aliado) {
	
	for (int i = 0; i < enemigos.size(); i++)
	{
		if (aliado->getRectangulo().IntersectsWith(enemigos[i]->getRectangulo()))
		{
			return true;
			/*vidas--;*/
		}	
	}	
	return false;
}

bool GameService::colisionPersonajeMoneda(Graphics^ lienzo, Personaje* personaje, Moneda* moneda) {
	if (getPuntaje() == 30) {
		//game over
		
	}
	if (personaje->getRectangulo().IntersectsWith(moneda->getRectangulo())) {
		setPuntaje(getPuntaje()+10);
		moneda->setX(rand() % 600 - 10);
		moneda->setY(rand() % 161 + 40);
		return true;
	}
	return false;
}

bool GameService::colisionAliadoMoneda(Graphics^ lienzo, Aliado* aliado, Moneda* moneda) {
	if (aliado->getRectangulo().IntersectsWith(moneda->getRectangulo())) {
		setPuntaje(getPuntaje() + 10);
		moneda->setX(rand() % 500 - 1);
		moneda->setY(rand() % 200 - 1);
		return true;
	}
	return false;
}
void GameService::setVidas(int pVidas) {
	vidasPersonaje = pVidas;
}
int GameService::getVidas() {
	return vidasPersonaje;
}

void GameService::setPuntaje(int pMonedas) {
	monedasPersonaje = pMonedas;
}
int GameService::getPuntaje() {
	return monedasPersonaje;
}

