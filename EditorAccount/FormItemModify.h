#pragma once

#include <iostream>

using namespace std;

namespace EditorAccount {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Runtime::InteropServices;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Button^ btnClear;
	private:
		int index;
		int effect0;
		int value0;
		int effect1;
		int value1;
		int effect2;
		int value2;

		String^ currentdir;

	public:
		
		Form2(String^ dir, int index, int effect0, int value0, int effect1, int value1, int effect2, int value2)
		{
			InitializeComponent();

			currentdir = dir;

			this->index = index;
			this->effect0 = effect0;
			this->value0 = value0;
			this->effect1 = effect1;
			this->value1 = value1;
			this->effect2 = effect2;
			this->value2 = value2;

			txtIndex->Text = index + "";
			txtEffect0->Text = effect0 + "";
			txtValue0->Text = value0 + "";
			txtEffect1->Text = effect1 + "";
			txtValue1->Text = value1 + "";
			txtEffect2->Text = effect2 + "";
			txtValue2->Text = value2 + "";
			//
			//TODO: Add the constructor code here
			//
		}
		Form2()
		{
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblEffect0;
	protected:
	private: System::Windows::Forms::TextBox^ txtEffect0;
	private: System::Windows::Forms::TextBox^ txtValue0;
	private: System::Windows::Forms::Label^ lblValue0;
	private: System::Windows::Forms::TextBox^ txtEffect1;
	private: System::Windows::Forms::Label^ lblEffect1;
	private: System::Windows::Forms::TextBox^ txtEffect2;
	private: System::Windows::Forms::Label^ lblEffect2;
	private: System::Windows::Forms::TextBox^ txtValue1;
	private: System::Windows::Forms::Label^ lblValue1;
	private: System::Windows::Forms::TextBox^ txtValue2;
	private: System::Windows::Forms::Label^ lblValue2;
	private: System::Windows::Forms::TextBox^ txtIndex;
	private: System::Windows::Forms::Label^ lblIndex;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblEffect0 = (gcnew System::Windows::Forms::Label());
			this->txtEffect0 = (gcnew System::Windows::Forms::TextBox());
			this->txtValue0 = (gcnew System::Windows::Forms::TextBox());
			this->lblValue0 = (gcnew System::Windows::Forms::Label());
			this->txtEffect1 = (gcnew System::Windows::Forms::TextBox());
			this->lblEffect1 = (gcnew System::Windows::Forms::Label());
			this->txtEffect2 = (gcnew System::Windows::Forms::TextBox());
			this->lblEffect2 = (gcnew System::Windows::Forms::Label());
			this->txtValue1 = (gcnew System::Windows::Forms::TextBox());
			this->lblValue1 = (gcnew System::Windows::Forms::Label());
			this->txtValue2 = (gcnew System::Windows::Forms::TextBox());
			this->lblValue2 = (gcnew System::Windows::Forms::Label());
			this->txtIndex = (gcnew System::Windows::Forms::TextBox());
			this->lblIndex = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// lblEffect0
			// 
			this->lblEffect0->AutoSize = true;
			this->lblEffect0->Location = System::Drawing::Point(12, 89);
			this->lblEffect0->Name = L"lblEffect0";
			this->lblEffect0->Size = System::Drawing::Size(44, 13);
			this->lblEffect0->TabIndex = 0;
			this->lblEffect0->Text = L"Effect0:";
			// 
			// txtEffect0
			// 
			this->txtEffect0->Location = System::Drawing::Point(72, 84);
			this->txtEffect0->Name = L"txtEffect0";
			this->txtEffect0->Size = System::Drawing::Size(100, 20);
			this->txtEffect0->TabIndex = 1;
			// 
			// txtValue0
			// 
			this->txtValue0->Location = System::Drawing::Point(248, 82);
			this->txtValue0->Name = L"txtValue0";
			this->txtValue0->Size = System::Drawing::Size(100, 20);
			this->txtValue0->TabIndex = 3;
			// 
			// lblValue0
			// 
			this->lblValue0->AutoSize = true;
			this->lblValue0->Location = System::Drawing::Point(188, 87);
			this->lblValue0->Name = L"lblValue0";
			this->lblValue0->Size = System::Drawing::Size(43, 13);
			this->lblValue0->TabIndex = 2;
			this->lblValue0->Text = L"Value0:";
			// 
			// txtEffect1
			// 
			this->txtEffect1->Location = System::Drawing::Point(72, 121);
			this->txtEffect1->Name = L"txtEffect1";
			this->txtEffect1->Size = System::Drawing::Size(100, 20);
			this->txtEffect1->TabIndex = 5;
			// 
			// lblEffect1
			// 
			this->lblEffect1->AutoSize = true;
			this->lblEffect1->Location = System::Drawing::Point(12, 126);
			this->lblEffect1->Name = L"lblEffect1";
			this->lblEffect1->Size = System::Drawing::Size(44, 13);
			this->lblEffect1->TabIndex = 4;
			this->lblEffect1->Text = L"Effect1:";
			// 
			// txtEffect2
			// 
			this->txtEffect2->Location = System::Drawing::Point(72, 160);
			this->txtEffect2->Name = L"txtEffect2";
			this->txtEffect2->Size = System::Drawing::Size(100, 20);
			this->txtEffect2->TabIndex = 7;
			// 
			// lblEffect2
			// 
			this->lblEffect2->AutoSize = true;
			this->lblEffect2->Location = System::Drawing::Point(12, 165);
			this->lblEffect2->Name = L"lblEffect2";
			this->lblEffect2->Size = System::Drawing::Size(44, 13);
			this->lblEffect2->TabIndex = 6;
			this->lblEffect2->Text = L"Effect2:";
			// 
			// txtValue1
			// 
			this->txtValue1->Location = System::Drawing::Point(249, 123);
			this->txtValue1->Name = L"txtValue1";
			this->txtValue1->Size = System::Drawing::Size(100, 20);
			this->txtValue1->TabIndex = 9;
			// 
			// lblValue1
			// 
			this->lblValue1->AutoSize = true;
			this->lblValue1->Location = System::Drawing::Point(189, 128);
			this->lblValue1->Name = L"lblValue1";
			this->lblValue1->Size = System::Drawing::Size(43, 13);
			this->lblValue1->TabIndex = 8;
			this->lblValue1->Text = L"Value1:";
			// 
			// txtValue2
			// 
			this->txtValue2->Location = System::Drawing::Point(249, 162);
			this->txtValue2->Name = L"txtValue2";
			this->txtValue2->Size = System::Drawing::Size(100, 20);
			this->txtValue2->TabIndex = 11;
			// 
			// lblValue2
			// 
			this->lblValue2->AutoSize = true;
			this->lblValue2->Location = System::Drawing::Point(189, 167);
			this->lblValue2->Name = L"lblValue2";
			this->lblValue2->Size = System::Drawing::Size(43, 13);
			this->lblValue2->TabIndex = 10;
			this->lblValue2->Text = L"Value2:";
			// 
			// txtIndex
			// 
			this->txtIndex->Location = System::Drawing::Point(72, 44);
			this->txtIndex->Name = L"txtIndex";
			this->txtIndex->Size = System::Drawing::Size(100, 20);
			this->txtIndex->TabIndex = 13;
			this->txtIndex->TextChanged += gcnew System::EventHandler(this, &Form2::txtIndex_TextChanged);
			// 
			// lblIndex
			// 
			this->lblIndex->AutoSize = true;
			this->lblIndex->Location = System::Drawing::Point(12, 47);
			this->lblIndex->Name = L"lblIndex";
			this->lblIndex->Size = System::Drawing::Size(36, 13);
			this->lblIndex->TabIndex = 12;
			this->lblIndex->Text = L"Index:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(268, 10);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(56, 54);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
			// 
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(143, 198);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(75, 23);
			this->btnClear->TabIndex = 15;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &Form2::btnClear_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(368, 233);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->txtIndex);
			this->Controls->Add(this->lblIndex);
			this->Controls->Add(this->txtValue2);
			this->Controls->Add(this->lblValue2);
			this->Controls->Add(this->txtValue1);
			this->Controls->Add(this->lblValue1);
			this->Controls->Add(this->txtEffect2);
			this->Controls->Add(this->lblEffect2);
			this->Controls->Add(this->txtEffect1);
			this->Controls->Add(this->lblEffect1);
			this->Controls->Add(this->txtValue0);
			this->Controls->Add(this->lblValue0);
			this->Controls->Add(this->txtEffect0);
			this->Controls->Add(this->lblEffect0);
			this->Name = L"Form2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Item Modify";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	public: String^ GetIndex() {
		return txtIndex->Text;
	}

	public: String^ GetEffect0() {
		return txtEffect0->Text;
	}

	public: String^ GetValue0() {
		return txtValue0->Text;
	}

	public: String^ GetEffect1() {
		return txtEffect1->Text;
	}

	public: String^ GetValue1() {
		return txtValue1->Text;
	}

	public: String^ GetEffect2() {
		return txtEffect2->Text;
	}

	public: String^ GetValue2() {
		return txtValue2->Text;
	}
#pragma endregion

	String^ GetValidPath(String^ path) {
		string cPath = (const char*)Marshal::StringToHGlobalAnsi(path).ToPointer();

		struct stat fileInfo;

		if (stat(cPath.c_str(), &fileInfo) == 0) {
			return path;
		}

		return currentdir + "unknown.png";
	}

	private: System::Void txtIndex_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		pictureBox1->ImageLocation = GetValidPath(currentdir + txtIndex->Text + ".png");
	}
		   
	private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
		txtIndex->Text = "0";
		txtEffect0->Text = "0";
		txtEffect1->Text = "0";
		txtEffect2->Text = "0";
		txtValue0->Text = "0";
		txtValue1->Text = "0";
		txtValue2->Text = "0";
	}
private: System::Void Form2_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
