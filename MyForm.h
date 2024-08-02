#pragma once
#include "Jugador.h"
#include "Moneda.h"
#include "Enemigo.h"
#include "Aliado.h"
#include "ExerciseForm.h"
#include "GameService.h"
#include "OperacionMatematica.h"
#include "MenuForm.h"
#include "GameOverForms1.h"
#include "WinForms1.h"
//ULTIMO ULTIMO
namespace TRABAJOFINALALGORITMOS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Timer^ timer1;
	private:
	    Personaje* objJugador = new Personaje();
		Aliado* objAliado = new Aliado();
		/*Enemigo* objEnemigo = new Enemigo();*/
		Bitmap^ bmpMapa1 = gcnew Bitmap("Imagenes\\MapaUnoBorde.png");
		Bitmap^ bmpMapa2 = gcnew Bitmap("Imagenes\\MapaDosBorde.png");
		Bitmap^ bmpMoneda = gcnew Bitmap("Imagenes\\moneda_2.png");
		Bitmap^ bmpEnemigo = gcnew Bitmap("Imagenes\\Enemigo.png");
		Moneda* objMoneda = new Moneda(bmpMoneda->Width, bmpMoneda->Height);
		OperacionMatematica* operacion = new OperacionMatematica();

		GameService* gameService = new GameService();
		int llavecolision = 0;
		
		


		Direccion teclapulsadaJugador;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;


		   Direccion teclapulsadaAliado;

	public:
		MyForm(void)
		{
			InitializeComponent();
			objJugador->setX(150);
			objJugador->setY(150);
			
			objJugador->cambia_imagen("Imagenes/Roke.png");
			
			objAliado->cambia_imagen("Imagenes/Aliado1.png");
			
			gameService->agregarEnemigo(bmpEnemigo->Width/4, bmpEnemigo->Height/4);
			
			objMoneda->setX(450);
			objMoneda->setY(250);
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox1->Location = System::Drawing::Point(713, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(48, 49);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox2->Location = System::Drawing::Point(790, -10);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(59, 59);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 749);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MyForm_KeyPress);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		Graphics^ lienzo = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);

		//MAPA 1 - HACER QUE LA IMAGEN SE ADAPTE AL TAMAÑO DEL FORMS
		int ancho_visible, alto_visible;
		ancho_visible = g->VisibleClipBounds.Width;
		alto_visible = g->VisibleClipBounds.Height;
		//BITMAP DEL MAPA
		buffer->Graphics->DrawImage(bmpMapa1, 0, 0, ancho_visible, alto_visible);
		gameService->pintarEstadisticas(buffer->Graphics);
		//MONEDA
		
        objMoneda->cambia_imagen(buffer->Graphics, bmpMoneda);

		//Funcionalidad de colision Personaje/Enemigo y Aliado/Enemigo
		gameService->colisionPersonajeEnemigo(buffer->Graphics, objJugador);
		if (objAliado != nullptr) {
			
			if (gameService->colisionAliadoEnemigo(buffer->Graphics, objAliado)) {
				delete objAliado;
				objAliado = nullptr;
			}
		}
		//Funcionalidad de mover todos los objetos

		if (gameService->getVidas() == 0) {
			GameOverForms1^ gameover = gcnew GameOverForms1();
			timer1->Enabled = false;
			gameover->ShowDialog();
			this->Close();
		}
		if (gameService->getPuntaje() == 30) {
			WinForms1^ wongame = gcnew WinForms1();
			timer1->Enabled = false;
			wongame->ShowDialog();
			this->Close();
		}

		gameService->moverTodo(buffer->Graphics, teclapulsadaJugador, objJugador, teclapulsadaAliado);
		
		//Funcionalidad de dibujar
		gameService->dibujarEnemigo(buffer->Graphics, bmpEnemigo);

		if (objAliado != nullptr) {
			objAliado->cambia_dx_dy(teclapulsadaAliado, buffer->Graphics);
			//mover aliado
			objAliado->mover_imagen(buffer->Graphics, teclapulsadaAliado);
		}

		//Funcionalidad con la colision de Personaje/Moneda
		if ((gameService->colisionPersonajeMoneda(buffer->Graphics, objJugador, objMoneda)==true)){
			ExerciseForm^ exerciseForm = gcnew ExerciseForm();
			timer1->Enabled = false;
			exerciseForm->ShowDialog();
			if (exerciseForm->getOperacion()->getLlave() == true)
			{
				timer1->Enabled = true;
			}
		}
		//Funcionalidad con la colision de Aliado/Moneda
		if (objAliado != nullptr && objMoneda != nullptr) {
			if ((gameService->colisionAliadoMoneda(buffer->Graphics, objAliado, objMoneda) == true)) {
				ExerciseForm^ exerciseForm = gcnew ExerciseForm();
				timer1->Enabled = false;
				exerciseForm->ShowDialog();
				if (exerciseForm->getOperacion()->getLlave() == true)
				{
					timer1->Enabled = true;
				}
			}
		}


		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;
	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Up)		teclapulsadaJugador = Direccion::Arriba;
		if (e->KeyCode == Keys::Down)	teclapulsadaJugador = Direccion::Abajo;
		if (e->KeyCode == Keys::Right)	teclapulsadaJugador = Direccion::Derecha;
		if (e->KeyCode == Keys::Left)	teclapulsadaJugador = Direccion::Izquierda;

		if (e->KeyCode == Keys::W)		teclapulsadaAliado = Direccion::Arriba;
		if (e->KeyCode == Keys::S)	teclapulsadaAliado = Direccion::Abajo;
		if (e->KeyCode == Keys::D)	teclapulsadaAliado = Direccion::Derecha;
		if (e->KeyCode == Keys::A)	teclapulsadaAliado = Direccion::Izquierda;
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		pictureBox1->Image = Image::FromFile("Imagenes\\moneda_girando.gif");
		pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;

		pictureBox2->Image = Image::FromFile("Imagenes\\corazon_girando.gif");
		pictureBox2->SizeMode = PictureBoxSizeMode::StretchImage;
	}
private: System::Void MyForm_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

}
};
}
