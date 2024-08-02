#pragma once
#include "OperacionMatematica.h"

namespace TRABAJOFINALALGORITMOS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de ExerciseForm
	/// </summary>
	public ref class ExerciseForm : public System::Windows::Forms::Form
	{
	public:
		ExerciseForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			

			double resultado = operacion->generarEjercicio();
			String^ ejercicio = String::Format("{0} {1} {2} = {3}", operacion->getNum1(), Char::ToString(operacion->getSimbolo()), operacion->getNum2(), " ?");

			MostrarEjercicio(ejercicio, resultado);
		}
		OperacionMatematica* getOperacion() {
			return operacion;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~ExerciseForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnVerificar;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;
		OperacionMatematica* operacion=new OperacionMatematica();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnVerificar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnVerificar
			// 
			this->btnVerificar->Location = System::Drawing::Point(122, 240);
			this->btnVerificar->Name = L"btnVerificar";
			this->btnVerificar->Size = System::Drawing::Size(150, 23);
			this->btnVerificar->TabIndex = 0;
			this->btnVerificar->Text = L"Verificar";
			this->btnVerificar->UseVisualStyleBackColor = true;
			this->btnVerificar->Click += gcnew System::EventHandler(this, &ExerciseForm::btnVerificar_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(174, 89);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &ExerciseForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(143, 162);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &ExerciseForm::textBox1_TextChanged);
			// 
			// ExerciseForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(450, 299);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnVerificar);
			this->Name = L"ExerciseForm";
			this->Text = L"ExerciseForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		// Variable para almacenar el resultado correcto del ejercicio
		int resultadoCorrecto;

	public:
		// Método para mostrar el ejercicio en el formulario
		void MostrarEjercicio(String^ ejercicio, double resultado) {
			label1->Text = ejercicio;
			resultadoCorrecto = resultado; // Guardar el resultado correcto para verificar más tarde
		}

	private: System::Void btnVerificar_Click(System::Object^ sender, System::EventArgs^ e) {
		int respuestaUsuario = Double::Parse(textBox1->Text);
		if (respuestaUsuario == resultadoCorrecto) {
			operacion->setLlave(true);
			MessageBox::Show("¡Respuesta correcta!");
			this->Close(); // Cerrar el formulario si la respuesta es correcta
		}
		else {
			MessageBox::Show("Respuesta incorrecta. Inténtalo de nuevo.");
			textBox1->Clear();
		}

	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
