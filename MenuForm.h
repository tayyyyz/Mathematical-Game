#pragma once
#include "MyForm2.h"
#include "InstruccionesForm.h"
#include "CreditosForm.h"
#include "MyForm.h"

namespace TRABAJOFINALALGORITMOS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:
		MenuForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Button^ Nivel1BTN;
	private: System::Windows::Forms::Button^ Nivel2BTN;
	private: System::Windows::Forms::Button^ InstruccionesBTN;
	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Nivel1BTN = (gcnew System::Windows::Forms::Button());
			this->Nivel2BTN = (gcnew System::Windows::Forms::Button());
			this->InstruccionesBTN = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-8, -2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1024, 1024);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// Nivel1BTN
			// 
			this->Nivel1BTN->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Nivel1BTN->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nivel1BTN->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Nivel1BTN.Image")));
			this->Nivel1BTN->Location = System::Drawing::Point(203, 443);
			this->Nivel1BTN->Name = L"Nivel1BTN";
			this->Nivel1BTN->Size = System::Drawing::Size(607, 90);
			this->Nivel1BTN->TabIndex = 1;
			this->Nivel1BTN->Text = L"PRIMER NIVEL";
			this->Nivel1BTN->UseVisualStyleBackColor = true;
			this->Nivel1BTN->Click += gcnew System::EventHandler(this, &MenuForm::Nivel1BTN_Click);
			// 
			// Nivel2BTN
			// 
			this->Nivel2BTN->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Nivel2BTN->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nivel2BTN->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Nivel2BTN.Image")));
			this->Nivel2BTN->Location = System::Drawing::Point(242, 572);
			this->Nivel2BTN->Name = L"Nivel2BTN";
			this->Nivel2BTN->Size = System::Drawing::Size(528, 90);
			this->Nivel2BTN->TabIndex = 2;
			this->Nivel2BTN->Text = L"SEGUNDO NIVEL";
			this->Nivel2BTN->UseVisualStyleBackColor = true;
			this->Nivel2BTN->Click += gcnew System::EventHandler(this, &MenuForm::Nivel2BTN_Click);
			// 
			// InstruccionesBTN
			// 
			this->InstruccionesBTN->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->InstruccionesBTN->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InstruccionesBTN->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"InstruccionesBTN.Image")));
			this->InstruccionesBTN->Location = System::Drawing::Point(242, 701);
			this->InstruccionesBTN->Name = L"InstruccionesBTN";
			this->InstruccionesBTN->Size = System::Drawing::Size(528, 93);
			this->InstruccionesBTN->TabIndex = 3;
			this->InstruccionesBTN->Text = L"INSTRUCCIONES";
			this->InstruccionesBTN->UseVisualStyleBackColor = true;
			this->InstruccionesBTN->Click += gcnew System::EventHandler(this, &MenuForm::InstruccionesBTN_Click);
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(203, 833);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(607, 101);
			this->button1->TabIndex = 4;
			this->button1->Text = L"CRÉDITOS";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MenuForm::button1_Click);
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 749);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->InstruccionesBTN);
			this->Controls->Add(this->Nivel2BTN);
			this->Controls->Add(this->Nivel1BTN);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MenuForm";
			this->Text = L"MenuForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Nivel1BTN_Click(System::Object^ sender, System::EventArgs^ e) {
		TRABAJOFINALALGORITMOS::MyForm^ Nivel1 = gcnew TRABAJOFINALALGORITMOS::MyForm();
		this->Visible = false;
		Nivel1->ShowDialog();
		this->Visible = true;
	}
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		TRABAJOFINALALGORITMOS::CreditosForm^ Creditos = gcnew TRABAJOFINALALGORITMOS::CreditosForm();
		this->Visible = false;
		Creditos->ShowDialog();
		this->Visible = true;
     
    }
    private: System::Void InstruccionesBTN_Click(System::Object^ sender, System::EventArgs^ e) {
		TRABAJOFINALALGORITMOS::InstruccionesForm^ Instrucciones = gcnew TRABAJOFINALALGORITMOS::InstruccionesForm();
		this->Visible = false;
		Instrucciones->ShowDialog();
		this->Visible = true;
    }
	private: System::Void Nivel2BTN_Click(System::Object^ sender, System::EventArgs^ e) {
		TRABAJOFINALALGORITMOS::MyForm2^ Nivel2 = gcnew TRABAJOFINALALGORITMOS::MyForm2();
		this->Visible = false;
		Nivel2->ShowDialog();
		this->Visible = true;
	}
};
}
