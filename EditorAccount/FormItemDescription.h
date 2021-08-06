#pragma once

namespace EditorAccount {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FormItemDescription : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Label^ labelIndex;
	private: cli::array<System::Windows::Forms::Label^> ^LabelArr;
	public:
		static FormItemDescription^ instance;

		int index;
		int* ceffect;
		int* cvalue;

		static FormItemDescription^ getInstance() {
			if (!instance) {
				instance = gcnew FormItemDescription();
			}

			return instance;
		}

		char* getType(int effect) {
			if (effect == 2)		return "Damage Increase";
			else if (effect == 3)	return "Shield";
			else if (effect == 43)	return "Refinement Level";
			else if (effect == 60)	return "Magic Attack Power";
			else if (effect == 69)	return "Health Regeneration Rate";
			else if (effect == 70)	return "Mana Regeneration Rate";
			else if (effect == 74)	return "Skill Mastery Increase";
			else if (effect == 106)	return "Days";
			else if (effect == 107)	return "Hours";
			else if (effect == 108)	return "Minutes";
			else if (effect == 109)	return "Years";
			else if (effect == 110)	return "Months";
			else if (effect == 120)	return "Refinement Level";		// Celestial parts

			return "Unknown";
		}

		void Reload() {
			if (this->index == 0) {
				labelIndex->Text = "Empty Slot";

				for(int i = 0; i < 3; i++)
					LabelArr[i]->Text = "";

				return;
			}

			int count = 0;
			
			labelIndex->Text = "Index: " + this->index;
			labelIndex->Location = System::Drawing::Point(this->Size.Width / 2 - labelIndex->Size.Width / 2, 10);

			for (int i = 0; i < LabelArr->Length; i++) {
				if (ceffect[i] != 0) {
					this->LabelArr[count]->Text = gcnew String(getType(ceffect[i])) + ": " + cvalue[i];
					this->LabelArr[count]->Location = System::Drawing::Point(this->Size.Width / 2 - LabelArr[count]->Size.Width / 2, 40 + count * 30);
					count++;
				}
			}

			for (int i = 0; i < LabelArr->Length - count; i++)
				this->LabelArr[LabelArr->Length - i - 1]->Text = "";
		}

		void setLocation(int x, int y) {
			instance->StartPosition = FormStartPosition::Manual;
			this->Top = y + 60;
			this->Left = x - (instance->Size.Width / 2);
		}

		void setInformation(int index, int ceffect0, int cvalue0, int ceffect1, int cvalue1, int ceffect2, int cvalue2) {
			this->index = index;

			this->ceffect[0] = ceffect0;
			this->ceffect[1] = ceffect1;
			this->ceffect[2] = ceffect2;

			this->cvalue[0] = cvalue0;
			this->cvalue[1] = cvalue1;
			this->cvalue[2] = cvalue2;

			this->Reload();
		}

		FormItemDescription(void)
		{
			index = 0;
			ceffect = new int[3];
			cvalue = new int[3];

			for (int i = 0; i < 3; i++) {
				ceffect[0] = 0;
				cvalue[0] = 0;
			}

			LabelArr = gcnew cli::array<Label^>(3);
			labelIndex = gcnew Label();
			labelIndex->AutoSize = true;
			labelIndex->ForeColor = Color::White;
			this->Controls->Add(this->labelIndex);

			for (int i = 0; i < LabelArr->Length; i++) {
				LabelArr[i] = gcnew System::Windows::Forms::Label();
				LabelArr[i]->AutoSize = true;
				LabelArr[i]->ForeColor = Color::White;
				this->Controls->Add(this->LabelArr[i]);
			}

			

			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormItemDescription()
		{
			if (components)
			{
				delete components;
				delete ceffect;
				delete cvalue;
			}
		}

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
			this->SuspendLayout();
			// 
			// FormItemDescription
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(200, 123);
			this->Name = L"FormItemDescription";
			this->Text = L"FormItemDescription";
			this->Load += gcnew System::EventHandler(this, &FormItemDescription::FormItemDescription_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FormItemDescription_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Opacity = 0.7;
		//this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
	}
	};
}

