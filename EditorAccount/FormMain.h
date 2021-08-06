#pragma once

#include <fstream>
#include <sys/stat.h>
#include "FormItemModify.h"
#include "FormItemDescription.h"
#include "Base.h"

using namespace std;

#define INVENTORY_SIZE	15
#define INVENTORY_COUNT 4
#define CARGO_SIZE		40
#define CARGO_COUNT		3

namespace EditorAccount {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Runtime::InteropServices;
	using namespace System::Reflection;
	using namespace Resources;

	public ref class FormMain : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::TextBox^ txtDonate;
	private: System::Windows::Forms::TextBox^ txtAccountName;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::TextBox^ txtExperience;
	private: System::Windows::Forms::TextBox^ txtCoin;
	private: System::Windows::Forms::TextBox^ txtLevel;
	private: System::Windows::Forms::TextBox^ txtPosX;
	private: System::Windows::Forms::TextBox^ txtPosY;
	private: System::Windows::Forms::TextBox^ txtStr;
	private: System::Windows::Forms::TextBox^ txtDex;
	private: System::Windows::Forms::TextBox^ txtInt;
	private: System::Windows::Forms::TextBox^ txtCon;
	private: System::Windows::Forms::TextBox^ txtSpecial0;
	private: System::Windows::Forms::TextBox^ txtSpecial1;
	private: System::Windows::Forms::TextBox^ txtSpecial2;
	private: System::Windows::Forms::TextBox^ txtSpecial3;
	private: System::Windows::Forms::TextBox^ txtCode;
	private: System::Windows::Forms::TextBox^ txtMaxHP;
	private: System::Windows::Forms::TextBox^ txtMaxMP;

	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripDropDownButton1;
	private: System::Windows::Forms::ToolStripMenuItem^ aaToolStripMenuItem;

	private: System::Windows::Forms::Label^ lblDonate;
	private: System::Windows::Forms::Label^ lblAccountName;
	private: System::Windows::Forms::Label^ lblPassword;
	private: System::Windows::Forms::Label^ lblPickCharacter;
	private: System::Windows::Forms::Label^ lblExp;
	private: System::Windows::Forms::Label^ lblCoin;
	private: System::Windows::Forms::Label^ lblLevel;
	private: System::Windows::Forms::Label^ lblClass;
	private: System::Windows::Forms::Label^ lblPosX;
	private: System::Windows::Forms::Label^ lblCoordsY;
	private: System::Windows::Forms::Label^ lblStr;
	private: System::Windows::Forms::Label^ lblDex;
	private: System::Windows::Forms::Label^ lblInt;
	private: System::Windows::Forms::Label^ lblCon;
	private: System::Windows::Forms::Label^ lblSpecial0;
	private: System::Windows::Forms::Label^ lblSpecial1;
	private: System::Windows::Forms::Label^ lblSpecial2;
	private: System::Windows::Forms::Label^ lblSpecial3;
	private: System::Windows::Forms::Label^ lblCode;
	private: System::Windows::Forms::Label^ lblMaxHP;
	private: System::Windows::Forms::Label^ lblMaxMP;

	private: System::Windows::Forms::ComboBox^ comboBoxCharacter;
	private: System::Windows::Forms::ComboBox^ comboBoxClass;

	private: System::ComponentModel::Container^ components;
	
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	private: System::Windows::Forms::GroupBox^ gbCharacterInfo;
	private: System::Windows::Forms::GroupBox^ gbAccountInfo;
	private: System::Windows::Forms::GroupBox^ gbCharacterStats;
	private: System::Windows::Forms::GroupBox^ gbInventory;
	private: System::Windows::Forms::GroupBox^ gbVault;

	private: cli::array<System::Windows::Forms::PictureBox^>^ pbArrEquip;
	private: cli::array<System::Windows::Forms::PictureBox^>^ pbArrCarry;
	private: cli::array<System::Windows::Forms::PictureBox^>^ pbArrVault;
	private: cli::array<System::Windows::Forms::PictureBox^>^ pbButtonCarry;
	private: cli::array<System::Windows::Forms::PictureBox^>^ pbButtonVault;

	private: System::Windows::Forms::PictureBox^ pbEquip;
	private: System::Windows::Forms::PictureBox^ pbCarry;
	private: System::Windows::Forms::PictureBox^ pbVault;

	public:
		int charIndex;
		int carryIndex;

		String^ filepath;
		String^ currentdir = gcnew String(imagesPath.c_str());

		STRUCT_ACCOUNTFILE* account;

	public:
		FormItemDescription^ fid;

		void InitialisePictureBox() {
			/* Starting from 0 instead of 1 unlike the server files */
			pbArrEquip		= gcnew cli::array<PictureBox^>(MAX_EQUIP-1);
			pbArrCarry		= gcnew cli::array<PictureBox^>(INVENTORY_SIZE);
			pbArrVault		= gcnew cli::array<PictureBox^>(CARGO_SIZE);
			pbButtonCarry	= gcnew cli::array<PictureBox^>(INVENTORY_COUNT);
			pbButtonVault	= gcnew cli::array<PictureBox^>(CARGO_COUNT);

			for (int i = 0; i < pbArrEquip->Length; i++) {
				pbArrEquip[i] = gcnew System::Windows::Forms::PictureBox();
				pbArrEquip[i]->BackColor = Color::Red;
				pbArrEquip[i]->Size = System::Drawing::Size(50, 50);
				pbArrEquip[i]->ImageLocation = currentdir + "0.png";
				pbArrEquip[i]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				pbArrEquip[i]->Click += gcnew System::EventHandler(this, &FormMain::pbClickHandler);
				pbArrEquip[i]->TabIndex = i;
				pbArrEquip[i]->MouseLeave += gcnew System::EventHandler(this, &FormMain::pbArrMouseLeave);
				pbArrEquip[i]->MouseHover += gcnew System::EventHandler(this, &FormMain::pbArrMouseHover);
				pbArrEquip[i]->Tag = "Equip";

				this->Controls->Add(this->pbArrEquip[i]);
			}

			for (int i = 0; i < pbArrCarry->Length; i++) {
				pbArrCarry[i] = gcnew System::Windows::Forms::PictureBox();
				pbArrCarry[i]->BackColor = Color::Red;
				pbArrCarry[i]->Size = System::Drawing::Size(50, 50);
				pbArrCarry[i]->ImageLocation = currentdir + "0.png";
				pbArrCarry[i]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				pbArrCarry[i]->Click += gcnew System::EventHandler(this, &FormMain::pbClickHandler);
				pbArrCarry[i]->TabIndex = i;
				pbArrCarry[i]->MouseLeave += gcnew System::EventHandler(this, &FormMain::pbArrMouseLeave);
				pbArrCarry[i]->MouseHover += gcnew System::EventHandler(this, &FormMain::pbArrMouseHover);
				pbArrCarry[i]->Tag = "Carry";

				this->Controls->Add(this->pbArrCarry[i]);

				int index1 = i % 5;
				int index2 = i / 5;
				int offset = 58;

				pbArrCarry[i]->Location = System::Drawing::Point(398 + offset * index1, 363 + offset * index2);
			}

			for (int i = 0; i < pbArrVault->Length; i++) {
				pbArrVault[i] = gcnew System::Windows::Forms::PictureBox();
				pbArrVault[i]->BackColor = Color::Red;
				pbArrVault[i]->Size = System::Drawing::Size(50, 50);
				pbArrVault[i]->ImageLocation = currentdir + "0.png";
				pbArrVault[i]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				pbArrVault[i]->Click += gcnew System::EventHandler(this, &FormMain::pbClickHandler);
				pbArrVault[i]->TabIndex = i;
				pbArrVault[i]->MouseLeave += gcnew System::EventHandler(this, &FormMain::pbArrMouseLeave);
				pbArrVault[i]->MouseHover += gcnew System::EventHandler(this, &FormMain::pbArrMouseHover);
				pbArrVault[i]->Tag = "Cargo";

				this->Controls->Add(this->pbArrVault[i]);

				int index1 = i % 5;
				int index2 = i / 5;
				int offsetx = 59;
				int offsety = 58;

				pbArrVault[i]->Location = System::Drawing::Point(724 + offsetx * index1, 110 + offsety * index2);
			}

			for (int i = 0; i < pbButtonCarry->Length; i++) {
				pbButtonCarry[i] = gcnew System::Windows::Forms::PictureBox();
				pbButtonCarry[i]->BackColor = Color::Red;
				pbButtonCarry[i]->Size = System::Drawing::Size(50, 50);
				pbButtonCarry[i]->ImageLocation = currentdir + ((i == 0) ? "bag_selected.png" : "bag.png");
				pbButtonCarry[i]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				pbButtonCarry[i]->Click += gcnew System::EventHandler(this, &FormMain::pbButtonClickHandler);
				pbButtonCarry[i]->TabIndex = i;
				pbButtonCarry[i]->Tag = "Carry";

				this->Controls->Add(this->pbButtonCarry[i]);

				int offset = 58;

				pbButtonCarry[i]->Location = System::Drawing::Point(398 + offset * i, 549);
			}

			for (int i = 0; i < pbButtonVault->Length; i++) {
				pbButtonVault[i] = gcnew System::Windows::Forms::PictureBox();
				pbButtonVault[i]->BackColor = Color::Red;
				pbButtonVault[i]->Size = System::Drawing::Size(25, 25);
				pbButtonVault[i]->ImageLocation = currentdir + ((i == 0) ? "cargo_button1_selected.png" : ("cargo_button" + (i+1) + ".png"));
				pbButtonVault[i]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				pbButtonVault[i]->Click += gcnew System::EventHandler(this, &FormMain::pbButtonClickHandler);
				pbButtonVault[i]->TabIndex = i;
				pbButtonVault[i]->Tag = "Cargo";

				this->Controls->Add(this->pbButtonVault[i]);

				int offset = 40;

				pbButtonVault[i]->Location = System::Drawing::Point(885 + offset * i, 582);
			}

			pbArrEquip[0]->Location = System::Drawing::Point(516, 94);
			pbArrEquip[1]->Location = System::Drawing::Point(516, 175);
			pbArrEquip[2]->Location = System::Drawing::Point(516, 257);
			pbArrEquip[3]->Location = System::Drawing::Point(455, 219);
			pbArrEquip[4]->Location = System::Drawing::Point(576, 293);
			pbArrEquip[5]->Location = System::Drawing::Point(455, 128);
			pbArrEquip[6]->Location = System::Drawing::Point(575, 128);
			pbArrEquip[7]->Location = System::Drawing::Point(395, 226);
			pbArrEquip[8]->Location = System::Drawing::Point(636, 226);
			pbArrEquip[9]->Location = System::Drawing::Point(395, 293);
			pbArrEquip[10]->Location = System::Drawing::Point(636, 293);
			pbArrEquip[11]->Location = System::Drawing::Point(395, 158);
			pbArrEquip[12]->Location = System::Drawing::Point(636, 158);
			pbArrEquip[13]->Location = System::Drawing::Point(395, 94);
			pbArrEquip[14]->Location = System::Drawing::Point(636, 94);
		}

		FormMain(void)
		{
			charIndex = -1;

			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;

			InitialisePictureBox();
			InitializeComponent();
		}

	protected:
		~FormMain()
		{
			if (components)
			{
				delete components;

				if (account) {
					free(account);
					account = NULL;
				}
			}
		}

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMain::typeid));
			this->lblAccountName = (gcnew System::Windows::Forms::Label());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripDropDownButton1 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->aaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->txtAccountName = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->lblPickCharacter = (gcnew System::Windows::Forms::Label());
			this->txtExperience = (gcnew System::Windows::Forms::TextBox());
			this->lblExp = (gcnew System::Windows::Forms::Label());
			this->txtCoin = (gcnew System::Windows::Forms::TextBox());
			this->lblCoin = (gcnew System::Windows::Forms::Label());
			this->txtLevel = (gcnew System::Windows::Forms::TextBox());
			this->lblLevel = (gcnew System::Windows::Forms::Label());
			this->lblClass = (gcnew System::Windows::Forms::Label());
			this->txtPosX = (gcnew System::Windows::Forms::TextBox());
			this->lblPosX = (gcnew System::Windows::Forms::Label());
			this->txtPosY = (gcnew System::Windows::Forms::TextBox());
			this->lblCoordsY = (gcnew System::Windows::Forms::Label());
			this->comboBoxCharacter = (gcnew System::Windows::Forms::ComboBox());
			this->txtStr = (gcnew System::Windows::Forms::TextBox());
			this->lblStr = (gcnew System::Windows::Forms::Label());
			this->txtDex = (gcnew System::Windows::Forms::TextBox());
			this->lblDex = (gcnew System::Windows::Forms::Label());
			this->txtInt = (gcnew System::Windows::Forms::TextBox());
			this->lblInt = (gcnew System::Windows::Forms::Label());
			this->txtCon = (gcnew System::Windows::Forms::TextBox());
			this->lblCon = (gcnew System::Windows::Forms::Label());
			this->txtSpecial0 = (gcnew System::Windows::Forms::TextBox());
			this->lblSpecial0 = (gcnew System::Windows::Forms::Label());
			this->txtSpecial1 = (gcnew System::Windows::Forms::TextBox());
			this->lblSpecial1 = (gcnew System::Windows::Forms::Label());
			this->txtSpecial2 = (gcnew System::Windows::Forms::TextBox());
			this->lblSpecial2 = (gcnew System::Windows::Forms::Label());
			this->txtSpecial3 = (gcnew System::Windows::Forms::TextBox());
			this->lblSpecial3 = (gcnew System::Windows::Forms::Label());
			this->lblCode = (gcnew System::Windows::Forms::Label());
			this->txtCode = (gcnew System::Windows::Forms::TextBox());
			this->txtMaxHP = (gcnew System::Windows::Forms::TextBox());
			this->lblMaxHP = (gcnew System::Windows::Forms::Label());
			this->txtMaxMP = (gcnew System::Windows::Forms::TextBox());
			this->lblMaxMP = (gcnew System::Windows::Forms::Label());
			this->pbEquip = (gcnew System::Windows::Forms::PictureBox());
			this->comboBoxClass = (gcnew System::Windows::Forms::ComboBox());
			this->txtDonate = (gcnew System::Windows::Forms::TextBox());
			this->lblDonate = (gcnew System::Windows::Forms::Label());
			this->gbCharacterInfo = (gcnew System::Windows::Forms::GroupBox());
			this->gbAccountInfo = (gcnew System::Windows::Forms::GroupBox());
			this->gbCharacterStats = (gcnew System::Windows::Forms::GroupBox());
			this->pbCarry = (gcnew System::Windows::Forms::PictureBox());
			this->pbVault = (gcnew System::Windows::Forms::PictureBox());
			this->gbInventory = (gcnew System::Windows::Forms::GroupBox());
			this->gbVault = (gcnew System::Windows::Forms::GroupBox());
			this->toolStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbEquip))->BeginInit();
			this->gbCharacterStats->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbCarry))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVault))->BeginInit();
			this->gbVault->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblAccountName
			// 
			this->lblAccountName->AutoSize = true;
			this->lblAccountName->Location = System::Drawing::Point(12, 55);
			this->lblAccountName->Name = L"lblAccountName";
			this->lblAccountName->Size = System::Drawing::Size(81, 13);
			this->lblAccountName->TabIndex = 1;
			this->lblAccountName->Text = L"Account Name:";
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripDropDownButton1 });
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1030, 25);
			this->toolStrip1->TabIndex = 2;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripDropDownButton1
			// 
			this->toolStripDropDownButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripDropDownButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->aaToolStripMenuItem,
					this->saveToolStripMenuItem
			});
			this->toolStripDropDownButton1->Name = L"toolStripDropDownButton1";
			this->toolStripDropDownButton1->Size = System::Drawing::Size(38, 22);
			this->toolStripDropDownButton1->Text = L"File";
			// 
			// aaToolStripMenuItem
			// 
			this->aaToolStripMenuItem->Name = L"aaToolStripMenuItem";
			this->aaToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->aaToolStripMenuItem->Text = L"Open";
			this->aaToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::OpenToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::SaveToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &FormMain::openFileDialog1_FileOk);
			// 
			// txtAccountName
			// 
			this->txtAccountName->Location = System::Drawing::Point(134, 50);
			this->txtAccountName->Name = L"txtAccountName";
			this->txtAccountName->Size = System::Drawing::Size(150, 20);
			this->txtAccountName->TabIndex = 3;
			this->txtAccountName->TextChanged += gcnew System::EventHandler(this, &FormMain::txtAccountName_TextChanged);
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(134, 80);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(150, 20);
			this->txtPassword->TabIndex = 5;
			this->txtPassword->TextChanged += gcnew System::EventHandler(this, &FormMain::txtPassword_TextChanged);
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Location = System::Drawing::Point(12, 85);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(56, 13);
			this->lblPassword->TabIndex = 4;
			this->lblPassword->Text = L"Password:";
			// 
			// lblPickCharacter
			// 
			this->lblPickCharacter->AutoSize = true;
			this->lblPickCharacter->Location = System::Drawing::Point(12, 145);
			this->lblPickCharacter->Name = L"lblPickCharacter";
			this->lblPickCharacter->Size = System::Drawing::Size(80, 13);
			this->lblPickCharacter->TabIndex = 6;
			this->lblPickCharacter->Text = L"Pick Character:";
			// 
			// txtExperience
			// 
			this->txtExperience->Location = System::Drawing::Point(135, 206);
			this->txtExperience->Name = L"txtExperience";
			this->txtExperience->Size = System::Drawing::Size(150, 20);
			this->txtExperience->TabIndex = 9;
			this->txtExperience->TextChanged += gcnew System::EventHandler(this, &FormMain::txtExperience_TextChanged);
			// 
			// lblExp
			// 
			this->lblExp->AutoSize = true;
			this->lblExp->Location = System::Drawing::Point(12, 211);
			this->lblExp->Name = L"lblExp";
			this->lblExp->Size = System::Drawing::Size(63, 13);
			this->lblExp->TabIndex = 8;
			this->lblExp->Text = L"Experience:";
			// 
			// txtCoin
			// 
			this->txtCoin->Location = System::Drawing::Point(135, 236);
			this->txtCoin->Name = L"txtCoin";
			this->txtCoin->Size = System::Drawing::Size(150, 20);
			this->txtCoin->TabIndex = 11;
			this->txtCoin->TextChanged += gcnew System::EventHandler(this, &FormMain::txtCoin_TextChanged);
			// 
			// lblCoin
			// 
			this->lblCoin->AutoSize = true;
			this->lblCoin->Location = System::Drawing::Point(12, 241);
			this->lblCoin->Name = L"lblCoin";
			this->lblCoin->Size = System::Drawing::Size(31, 13);
			this->lblCoin->TabIndex = 10;
			this->lblCoin->Text = L"Coin:";
			// 
			// txtLevel
			// 
			this->txtLevel->Location = System::Drawing::Point(135, 266);
			this->txtLevel->Name = L"txtLevel";
			this->txtLevel->Size = System::Drawing::Size(150, 20);
			this->txtLevel->TabIndex = 13;
			this->txtLevel->TextChanged += gcnew System::EventHandler(this, &FormMain::txtLevel_TextChanged);
			// 
			// lblLevel
			// 
			this->lblLevel->AutoSize = true;
			this->lblLevel->Location = System::Drawing::Point(12, 271);
			this->lblLevel->Name = L"lblLevel";
			this->lblLevel->Size = System::Drawing::Size(36, 13);
			this->lblLevel->TabIndex = 12;
			this->lblLevel->Text = L"Level:";
			// 
			// lblClass
			// 
			this->lblClass->AutoSize = true;
			this->lblClass->Location = System::Drawing::Point(12, 301);
			this->lblClass->Name = L"lblClass";
			this->lblClass->Size = System::Drawing::Size(35, 13);
			this->lblClass->TabIndex = 14;
			this->lblClass->Text = L"Class:";
			// 
			// txtPosX
			// 
			this->txtPosX->Location = System::Drawing::Point(135, 326);
			this->txtPosX->Name = L"txtPosX";
			this->txtPosX->Size = System::Drawing::Size(150, 20);
			this->txtPosX->TabIndex = 17;
			this->txtPosX->TextChanged += gcnew System::EventHandler(this, &FormMain::txtPosX_TextChanged);
			// 
			// lblPosX
			// 
			this->lblPosX->AutoSize = true;
			this->lblPosX->Location = System::Drawing::Point(12, 331);
			this->lblPosX->Name = L"lblPosX";
			this->lblPosX->Size = System::Drawing::Size(53, 13);
			this->lblPosX->TabIndex = 16;
			this->lblPosX->Text = L"Coords X:";
			// 
			// txtPosY
			// 
			this->txtPosY->Location = System::Drawing::Point(135, 356);
			this->txtPosY->Name = L"txtPosY";
			this->txtPosY->Size = System::Drawing::Size(150, 20);
			this->txtPosY->TabIndex = 19;
			this->txtPosY->TextChanged += gcnew System::EventHandler(this, &FormMain::txtPosY_TextChanged);
			// 
			// lblCoordsY
			// 
			this->lblCoordsY->AutoSize = true;
			this->lblCoordsY->Location = System::Drawing::Point(12, 361);
			this->lblCoordsY->Name = L"lblCoordsY";
			this->lblCoordsY->Size = System::Drawing::Size(53, 13);
			this->lblCoordsY->TabIndex = 18;
			this->lblCoordsY->Text = L"Coords Y:";
			// 
			// comboBoxCharacter
			// 
			this->comboBoxCharacter->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxCharacter->FormattingEnabled = true;
			this->comboBoxCharacter->Location = System::Drawing::Point(134, 140);
			this->comboBoxCharacter->Name = L"comboBoxCharacter";
			this->comboBoxCharacter->Size = System::Drawing::Size(150, 21);
			this->comboBoxCharacter->TabIndex = 22;
			this->comboBoxCharacter->SelectedIndexChanged += gcnew System::EventHandler(this, &FormMain::comboBoxCharacter_SelectedIndexChanged);
			// 
			// txtStr
			// 
			this->txtStr->Location = System::Drawing::Point(255, 19);
			this->txtStr->Name = L"txtStr";
			this->txtStr->Size = System::Drawing::Size(100, 20);
			this->txtStr->TabIndex = 24;
			this->txtStr->TextChanged += gcnew System::EventHandler(this, &FormMain::txtStr_TextChanged);
			// 
			// lblStr
			// 
			this->lblStr->AutoSize = true;
			this->lblStr->Location = System::Drawing::Point(180, 24);
			this->lblStr->Name = L"lblStr";
			this->lblStr->Size = System::Drawing::Size(50, 13);
			this->lblStr->TabIndex = 23;
			this->lblStr->Text = L"Strength:";
			// 
			// txtDex
			// 
			this->txtDex->Location = System::Drawing::Point(255, 49);
			this->txtDex->Name = L"txtDex";
			this->txtDex->Size = System::Drawing::Size(100, 20);
			this->txtDex->TabIndex = 26;
			this->txtDex->TextChanged += gcnew System::EventHandler(this, &FormMain::txtDex_TextChanged);
			// 
			// lblDex
			// 
			this->lblDex->AutoSize = true;
			this->lblDex->Location = System::Drawing::Point(180, 54);
			this->lblDex->Name = L"lblDex";
			this->lblDex->Size = System::Drawing::Size(51, 13);
			this->lblDex->TabIndex = 25;
			this->lblDex->Text = L"Dexterity:";
			// 
			// txtInt
			// 
			this->txtInt->Location = System::Drawing::Point(255, 79);
			this->txtInt->Name = L"txtInt";
			this->txtInt->Size = System::Drawing::Size(100, 20);
			this->txtInt->TabIndex = 28;
			this->txtInt->TextChanged += gcnew System::EventHandler(this, &FormMain::txtInt_TextChanged);
			// 
			// lblInt
			// 
			this->lblInt->AutoSize = true;
			this->lblInt->Location = System::Drawing::Point(180, 84);
			this->lblInt->Name = L"lblInt";
			this->lblInt->Size = System::Drawing::Size(64, 13);
			this->lblInt->TabIndex = 27;
			this->lblInt->Text = L"Intelligence:";
			// 
			// txtCon
			// 
			this->txtCon->Location = System::Drawing::Point(255, 109);
			this->txtCon->Name = L"txtCon";
			this->txtCon->Size = System::Drawing::Size(100, 20);
			this->txtCon->TabIndex = 30;
			this->txtCon->TextChanged += gcnew System::EventHandler(this, &FormMain::txtCon_TextChanged);
			// 
			// lblCon
			// 
			this->lblCon->AutoSize = true;
			this->lblCon->Location = System::Drawing::Point(180, 114);
			this->lblCon->Name = L"lblCon";
			this->lblCon->Size = System::Drawing::Size(65, 13);
			this->lblCon->TabIndex = 29;
			this->lblCon->Text = L"Constitotion:";
			// 
			// txtSpecial0
			// 
			this->txtSpecial0->Location = System::Drawing::Point(69, 21);
			this->txtSpecial0->Name = L"txtSpecial0";
			this->txtSpecial0->Size = System::Drawing::Size(100, 20);
			this->txtSpecial0->TabIndex = 32;
			this->txtSpecial0->TextChanged += gcnew System::EventHandler(this, &FormMain::txtSpecial0_TextChanged);
			// 
			// lblSpecial0
			// 
			this->lblSpecial0->AutoSize = true;
			this->lblSpecial0->Location = System::Drawing::Point(8, 26);
			this->lblSpecial0->Name = L"lblSpecial0";
			this->lblSpecial0->Size = System::Drawing::Size(51, 13);
			this->lblSpecial0->TabIndex = 31;
			this->lblSpecial0->Text = L"Special0:";
			// 
			// txtSpecial1
			// 
			this->txtSpecial1->Location = System::Drawing::Point(69, 51);
			this->txtSpecial1->Name = L"txtSpecial1";
			this->txtSpecial1->Size = System::Drawing::Size(100, 20);
			this->txtSpecial1->TabIndex = 34;
			this->txtSpecial1->TextChanged += gcnew System::EventHandler(this, &FormMain::txtSpecial1_TextChanged);
			// 
			// lblSpecial1
			// 
			this->lblSpecial1->AutoSize = true;
			this->lblSpecial1->Location = System::Drawing::Point(8, 56);
			this->lblSpecial1->Name = L"lblSpecial1";
			this->lblSpecial1->Size = System::Drawing::Size(51, 13);
			this->lblSpecial1->TabIndex = 33;
			this->lblSpecial1->Text = L"Special1:";
			// 
			// txtSpecial2
			// 
			this->txtSpecial2->Location = System::Drawing::Point(69, 81);
			this->txtSpecial2->Name = L"txtSpecial2";
			this->txtSpecial2->Size = System::Drawing::Size(100, 20);
			this->txtSpecial2->TabIndex = 36;
			this->txtSpecial2->TextChanged += gcnew System::EventHandler(this, &FormMain::txtSpecial2_TextChanged);
			// 
			// lblSpecial2
			// 
			this->lblSpecial2->AutoSize = true;
			this->lblSpecial2->Location = System::Drawing::Point(8, 86);
			this->lblSpecial2->Name = L"lblSpecial2";
			this->lblSpecial2->Size = System::Drawing::Size(48, 13);
			this->lblSpecial2->TabIndex = 35;
			this->lblSpecial2->Text = L"Special2";
			// 
			// txtSpecial3
			// 
			this->txtSpecial3->Location = System::Drawing::Point(69, 111);
			this->txtSpecial3->Name = L"txtSpecial3";
			this->txtSpecial3->Size = System::Drawing::Size(100, 20);
			this->txtSpecial3->TabIndex = 38;
			this->txtSpecial3->TextChanged += gcnew System::EventHandler(this, &FormMain::txtSpecial3_TextChanged);
			// 
			// lblSpecial3
			// 
			this->lblSpecial3->AutoSize = true;
			this->lblSpecial3->Location = System::Drawing::Point(8, 116);
			this->lblSpecial3->Name = L"lblSpecial3";
			this->lblSpecial3->Size = System::Drawing::Size(51, 13);
			this->lblSpecial3->TabIndex = 37;
			this->lblSpecial3->Text = L"Special3:";
			// 
			// lblCode
			// 
			this->lblCode->AutoSize = true;
			this->lblCode->Location = System::Drawing::Point(12, 115);
			this->lblCode->Name = L"lblCode";
			this->lblCode->Size = System::Drawing::Size(35, 13);
			this->lblCode->TabIndex = 39;
			this->lblCode->Text = L"Code:";
			// 
			// txtCode
			// 
			this->txtCode->Location = System::Drawing::Point(134, 110);
			this->txtCode->Name = L"txtCode";
			this->txtCode->Size = System::Drawing::Size(150, 20);
			this->txtCode->TabIndex = 40;
			this->txtCode->TextChanged += gcnew System::EventHandler(this, &FormMain::txtCode_TextChanged);
			// 
			// txtMaxHP
			// 
			this->txtMaxHP->Location = System::Drawing::Point(135, 386);
			this->txtMaxHP->Name = L"txtMaxHP";
			this->txtMaxHP->Size = System::Drawing::Size(150, 20);
			this->txtMaxHP->TabIndex = 44;
			this->txtMaxHP->TextChanged += gcnew System::EventHandler(this, &FormMain::txtMaxHP_TextChanged);
			// 
			// lblMaxHP
			// 
			this->lblMaxHP->AutoSize = true;
			this->lblMaxHP->Location = System::Drawing::Point(12, 391);
			this->lblMaxHP->Name = L"lblMaxHP";
			this->lblMaxHP->Size = System::Drawing::Size(48, 13);
			this->lblMaxHP->TabIndex = 43;
			this->lblMaxHP->Text = L"Max HP:";
			// 
			// txtMaxMP
			// 
			this->txtMaxMP->Location = System::Drawing::Point(135, 416);
			this->txtMaxMP->Name = L"txtMaxMP";
			this->txtMaxMP->Size = System::Drawing::Size(150, 20);
			this->txtMaxMP->TabIndex = 48;
			this->txtMaxMP->TextChanged += gcnew System::EventHandler(this, &FormMain::txtMaxMP_TextChanged);
			// 
			// lblMaxMP
			// 
			this->lblMaxMP->AutoSize = true;
			this->lblMaxMP->Location = System::Drawing::Point(12, 421);
			this->lblMaxMP->Name = L"lblMaxMP";
			this->lblMaxMP->Size = System::Drawing::Size(49, 13);
			this->lblMaxMP->TabIndex = 47;
			this->lblMaxMP->Text = L"Max MP:";
			// 
			// pbEquip
			// 
			this->pbEquip->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbEquip.BackgroundImage")));
			this->pbEquip->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pbEquip->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pbEquip->ImageLocation = L"images\\inventory.jpg";
			this->pbEquip->Location = System::Drawing::Point(387, 48);
			this->pbEquip->Name = L"pbEquip";
			this->pbEquip->Size = System::Drawing::Size(307, 304);
			this->pbEquip->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbEquip->TabIndex = 49;
			this->pbEquip->TabStop = false;
			// 
			// comboBoxClass
			// 
			this->comboBoxClass->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxClass->FormattingEnabled = true;
			this->comboBoxClass->Location = System::Drawing::Point(135, 296);
			this->comboBoxClass->Name = L"comboBoxClass";
			this->comboBoxClass->Size = System::Drawing::Size(150, 21);
			this->comboBoxClass->TabIndex = 74;
			this->comboBoxClass->SelectedIndexChanged += gcnew System::EventHandler(this, &FormMain::comboBoxClass_SelectedIndexChanged);
			// 
			// txtDonate
			// 
			this->txtDonate->Location = System::Drawing::Point(135, 446);
			this->txtDonate->Name = L"txtDonate";
			this->txtDonate->Size = System::Drawing::Size(150, 20);
			this->txtDonate->TabIndex = 76;
			this->txtDonate->TextChanged += gcnew System::EventHandler(this, &FormMain::txtDonate_TextChanged);
			// 
			// lblDonate
			// 
			this->lblDonate->AutoSize = true;
			this->lblDonate->Location = System::Drawing::Point(12, 451);
			this->lblDonate->Name = L"lblDonate";
			this->lblDonate->Size = System::Drawing::Size(45, 13);
			this->lblDonate->TabIndex = 75;
			this->lblDonate->Text = L"Donate:";
			// 
			// gbCharacterInfo
			// 
			this->gbCharacterInfo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->gbCharacterInfo->Location = System::Drawing::Point(6, 185);
			this->gbCharacterInfo->Name = L"gbCharacterInfo";
			this->gbCharacterInfo->Size = System::Drawing::Size(366, 288);
			this->gbCharacterInfo->TabIndex = 77;
			this->gbCharacterInfo->TabStop = false;
			this->gbCharacterInfo->Text = L"Character Information";
			// 
			// gbAccountInfo
			// 
			this->gbAccountInfo->Location = System::Drawing::Point(6, 28);
			this->gbAccountInfo->Name = L"gbAccountInfo";
			this->gbAccountInfo->Size = System::Drawing::Size(366, 151);
			this->gbAccountInfo->TabIndex = 78;
			this->gbAccountInfo->TabStop = false;
			this->gbAccountInfo->Text = L"Account Information";
			// 
			// gbCharacterStats
			// 
			this->gbCharacterStats->Controls->Add(this->txtInt);
			this->gbCharacterStats->Controls->Add(this->lblStr);
			this->gbCharacterStats->Controls->Add(this->txtStr);
			this->gbCharacterStats->Controls->Add(this->lblDex);
			this->gbCharacterStats->Controls->Add(this->txtDex);
			this->gbCharacterStats->Controls->Add(this->lblInt);
			this->gbCharacterStats->Controls->Add(this->lblCon);
			this->gbCharacterStats->Controls->Add(this->txtCon);
			this->gbCharacterStats->Controls->Add(this->lblSpecial0);
			this->gbCharacterStats->Controls->Add(this->txtSpecial0);
			this->gbCharacterStats->Controls->Add(this->txtSpecial3);
			this->gbCharacterStats->Controls->Add(this->lblSpecial1);
			this->gbCharacterStats->Controls->Add(this->lblSpecial3);
			this->gbCharacterStats->Controls->Add(this->txtSpecial1);
			this->gbCharacterStats->Controls->Add(this->txtSpecial2);
			this->gbCharacterStats->Controls->Add(this->lblSpecial2);
			this->gbCharacterStats->Location = System::Drawing::Point(6, 479);
			this->gbCharacterStats->Name = L"gbCharacterStats";
			this->gbCharacterStats->Size = System::Drawing::Size(366, 142);
			this->gbCharacterStats->TabIndex = 79;
			this->gbCharacterStats->TabStop = false;
			this->gbCharacterStats->Text = L"Character Stats";
			// 
			// pbCarry
			// 
			this->pbCarry->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbCarry.BackgroundImage")));
			this->pbCarry->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pbCarry->Location = System::Drawing::Point(388, 349);
			this->pbCarry->Name = L"pbCarry";
			this->pbCarry->Size = System::Drawing::Size(304, 262);
			this->pbCarry->TabIndex = 80;
			this->pbCarry->TabStop = false;
			// 
			// pbVault
			// 
			this->pbVault->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbVault.BackgroundImage")));
			this->pbVault->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pbVault->Location = System::Drawing::Point(6, 20);
			this->pbVault->Name = L"pbVault";
			this->pbVault->Size = System::Drawing::Size(300, 563);
			this->pbVault->TabIndex = 81;
			this->pbVault->TabStop = false;
			// 
			// gbInventory
			// 
			this->gbInventory->Location = System::Drawing::Point(378, 28);
			this->gbInventory->Name = L"gbInventory";
			this->gbInventory->Size = System::Drawing::Size(325, 593);
			this->gbInventory->TabIndex = 82;
			this->gbInventory->TabStop = false;
			this->gbInventory->Text = L"Inventory";
			// 
			// gbVault
			// 
			this->gbVault->Controls->Add(this->pbVault);
			this->gbVault->Location = System::Drawing::Point(709, 28);
			this->gbVault->Name = L"gbVault";
			this->gbVault->Size = System::Drawing::Size(314, 593);
			this->gbVault->TabIndex = 83;
			this->gbVault->TabStop = false;
			this->gbVault->Text = L"Vault";
			// 
			// FormMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1030, 630);
			this->Controls->Add(this->pbCarry);
			this->Controls->Add(this->txtDonate);
			this->Controls->Add(this->lblDonate);
			this->Controls->Add(this->comboBoxClass);
			this->Controls->Add(this->pbEquip);
			this->Controls->Add(this->txtMaxMP);
			this->Controls->Add(this->lblMaxMP);
			this->Controls->Add(this->txtMaxHP);
			this->Controls->Add(this->lblMaxHP);
			this->Controls->Add(this->txtCode);
			this->Controls->Add(this->lblCode);
			this->Controls->Add(this->comboBoxCharacter);
			this->Controls->Add(this->txtPosY);
			this->Controls->Add(this->lblCoordsY);
			this->Controls->Add(this->txtPosX);
			this->Controls->Add(this->lblPosX);
			this->Controls->Add(this->lblClass);
			this->Controls->Add(this->txtLevel);
			this->Controls->Add(this->lblLevel);
			this->Controls->Add(this->txtCoin);
			this->Controls->Add(this->lblCoin);
			this->Controls->Add(this->txtExperience);
			this->Controls->Add(this->lblExp);
			this->Controls->Add(this->lblPickCharacter);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->txtAccountName);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->lblAccountName);
			this->Controls->Add(this->gbCharacterInfo);
			this->Controls->Add(this->gbAccountInfo);
			this->Controls->Add(this->gbCharacterStats);
			this->Controls->Add(this->gbInventory);
			this->Controls->Add(this->gbVault);
			this->Name = L"FormMain";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Account Editor";
			this->TransparencyKey = System::Drawing::Color::Fuchsia;
			this->Load += gcnew System::EventHandler(this, &FormMain::FormMain_Load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbEquip))->EndInit();
			this->gbCharacterStats->ResumeLayout(false);
			this->gbCharacterStats->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbCarry))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVault))->EndInit();
			this->gbVault->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		bool is_digits(const string& str)
		{
			return str.find_first_not_of("0123456789") == string::npos;
		}

		private: System::Void FormMain_Load(System::Object^ sender, System::EventArgs^ e) {
			ClearCharacterView();

			pbEquip->ImageLocation = currentdir + "inventory.jpg";
		}

		private: System::Void OpenToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			openFileDialog1->ShowDialog();
		}

		private: System::Void SaveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			string cPath = (const char*)Marshal::StringToHGlobalAnsi(filepath).ToPointer();

			SaveFile(cPath);
		}

		private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
			if (!account) {
				account = (STRUCT_ACCOUNTFILE*)malloc(sizeof(STRUCT_ACCOUNTFILE));
				memset(account, 0, sizeof(STRUCT_ACCOUNTFILE));
			}
			
			filepath = openFileDialog1->FileName;
			string cPath = (const char*)Marshal::StringToHGlobalAnsi(filepath).ToPointer();
		
			ClearCharacterView();

			ReadFile(cPath);

			for (int i = 0; i < pbArrVault->Length; i++)
				pbArrVault[i]->ImageLocation = GetValidPath(currentdir, account->Cargo[i].sIndex);

			for (int i = 0; i < CARGO_COUNT; i++)
				pbButtonVault[i]->ImageLocation = currentdir + "cargo_button" + (i + 1) + ".png";

			pbButtonVault[0]->ImageLocation = currentdir + "cargo_button1_selected.png";
		}

		void ReadFile(string path) {
			ifstream file(path, ios::binary);

			file.read((char*)account, sizeof(STRUCT_ACCOUNTFILE));
			file.close();

			txtAccountName->Text =	gcnew String(account->Info.AccountName);
			txtCode->Text =			gcnew String(account->Info.NumericToken);
			txtPassword->Text =		gcnew String(account->Info.AccountPass);

			for (int i = 0; i < 4; i++) {
				if (account->Char[i].MobName != NULL && strlen(account->Char[i].MobName)) {
					comboBoxCharacter->Items->Add(gcnew String(account->Char[i].MobName));
				}
			}
		}

		void SaveFile(string path) {
			ofstream file(path, ios::binary);

			file.write((char*)account, sizeof(STRUCT_ACCOUNTFILE));

			file.close();
		}

		void WriteFile(string path) {
			ofstream file(path, ios::binary);

			file.write((char*)account, sizeof(STRUCT_ACCOUNTFILE));
			file.close();
		}

		void ClearCharacterView() {
			charIndex = -1;

			comboBoxCharacter->Items->Clear();
			comboBoxClass->Items->Clear();
			txtExperience->Clear();
			txtCoin->Clear();
			txtLevel->Clear();
			txtSpecial0->Clear();
			txtSpecial1->Clear();
			txtSpecial2->Clear();
			txtSpecial3->Clear();
			txtStr->Clear();
			txtDex->Clear();
			txtInt->Clear();
			txtCon->Clear();
			txtPosX->Clear();
			txtPosY->Clear();
			txtMaxHP->Clear();
			txtMaxMP->Clear();
			txtDonate->Clear();

			comboBoxCharacter->Text = "";
			comboBoxClass->Text = "";

			for (int i = 0; i < pbArrEquip->Length; i++)
				pbArrEquip[i]->ImageLocation = currentdir + "0.png";

			for (int i = 0; i < pbArrCarry->Length; i++)
				pbArrCarry[i]->ImageLocation = currentdir + "0.png";

			pbEquip->ImageLocation = currentdir + "inventory.jpg";
		}

		String^ GetValidPath(String^ path, int index) {
			if(index == 0)
				return currentdir + "0.png";

			path += index + ".png";

			string cPath = (const char*)Marshal::StringToHGlobalAnsi(path).ToPointer();
		
			struct stat fileInfo;

			if (stat(cPath.c_str(), &fileInfo) == 0)
				return path;

			return currentdir + "unknown.png";
		}
	
		private: System::Void comboBoxCharacter_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			charIndex = comboBoxCharacter->SelectedIndex;

			txtCoin->Text = account->Char[charIndex].Coin + "";
			txtExperience->Text = account->Char[charIndex].Exp + "";
			txtLevel->Text = account->Char[charIndex].BaseScore.Level + "";
			txtPosX->Text = account->Char[charIndex].SPX + "";
			txtPosY->Text = account->Char[charIndex].SPY + "";
			txtStr->Text = account->Char[charIndex].BaseScore.Str + "";
			txtDex->Text = account->Char[charIndex].BaseScore.Dex + "";
			txtInt->Text = account->Char[charIndex].BaseScore.Int + "";
			txtCon->Text = account->Char[charIndex].BaseScore.Con + "";
			txtSpecial0->Text = account->Char[charIndex].BaseScore.Special[0] + "";
			txtSpecial1->Text = account->Char[charIndex].BaseScore.Special[1] + "";
			txtSpecial2->Text = account->Char[charIndex].BaseScore.Special[2] + "";
			txtSpecial3->Text = account->Char[charIndex].BaseScore.Special[3] + "";
			txtMaxHP->Text = account->Char[charIndex].BaseScore.MaxHp + "";
			txtMaxMP->Text = account->Char[charIndex].BaseScore.MaxMp + "";
			txtDonate->Text = account->mobExtra[charIndex].DonateInfo.Count + "";

			for (int i = 0; i < CLASSES; i++)
				comboBoxClass->Items->Add(gcnew String(Classes[i]));

			comboBoxClass->SelectedIndex = account->Char[charIndex].Class;

			for(int i = 0; i < pbArrEquip->Length; i++)
				pbArrEquip[i]->ImageLocation = GetValidPath(currentdir, account->Char[charIndex].Equip[i+1].sIndex);

			for (int i = 0; i < pbArrCarry->Length; i++)
				pbArrCarry[i]->ImageLocation = GetValidPath(currentdir, account->Char[charIndex].Carry[i].sIndex);

			for (int i = 0; i < INVENTORY_COUNT; i++) {
				pbButtonCarry[i]->ImageLocation = currentdir + "bag.png";
			}

			pbButtonCarry[0]->ImageLocation = currentdir + "bag_selected.png";
		}

		void DisplayFormItem(int slot, String^ type) {
			int itemIndex;
			int effect[3], value[3];

			for (int i = 0; i < 3; i++) {
				if (type->Equals("Carry")) {
					itemIndex	= account->Char[charIndex].Carry[slot].sIndex;
					effect[i]	= account->Char[charIndex].Carry[slot].stEffect[i].cEffect;
					value[i]	= account->Char[charIndex].Carry[slot].stEffect[i].cValue;
				}
				else if (type->Equals("Equip")) {
					itemIndex	= account->Char[charIndex].Equip[slot].sIndex;
					effect[i]	= account->Char[charIndex].Equip[slot].stEffect[i].cEffect;
					value[i]	= account->Char[charIndex].Equip[slot].stEffect[i].cValue;
				}
				else if (type->Equals("Cargo")) {
					itemIndex	= account->Cargo[slot].sIndex;
					effect[i]	= account->Cargo[slot].stEffect[i].cEffect;
					value[i]	= account->Cargo[slot].stEffect[i].cValue;
				}
			}

			Form2^ form2 = gcnew Form2(currentdir, itemIndex, effect[0], value[0], effect[1], value[1], effect[2], value[2]);

			form2->ShowDialog();
	
			itemIndex =		atoi((const char*)Marshal::StringToHGlobalAnsi(form2->GetIndex()).ToPointer());
			effect[0] =	atoi((const char*)Marshal::StringToHGlobalAnsi(form2->GetEffect0()).ToPointer());
			effect[1] =	atoi((const char*)Marshal::StringToHGlobalAnsi(form2->GetEffect1()).ToPointer());
			effect[2] =	atoi((const char*)Marshal::StringToHGlobalAnsi(form2->GetEffect2()).ToPointer());
			value[0] =	atoi((const char*)Marshal::StringToHGlobalAnsi(form2->GetValue0()).ToPointer());
			value[1] =	atoi((const char*)Marshal::StringToHGlobalAnsi(form2->GetValue1()).ToPointer());
			value[2] =	atoi((const char*)Marshal::StringToHGlobalAnsi(form2->GetValue2()).ToPointer());

			InsertEquipData(slot, type, itemIndex, effect, value);
		}

		void InsertEquipData(int slot, String^ type, int index, int effect[3], int value[3]) {
			for (int i = 0; i < 3; i++) {
				if (type->Equals("Carry")) {
					account->Char[charIndex].Carry[slot].sIndex = index;
					account->Char[charIndex].Carry[slot].stEffect[i].cEffect = effect[i];
					account->Char[charIndex].Carry[slot].stEffect[i].cValue = value[i];
				}
				else if (type->Equals("Equip")) {
					account->Char[charIndex].Equip[slot].sIndex = index;
					account->Char[charIndex].Equip[slot].stEffect[i].cEffect = effect[i];
					account->Char[charIndex].Equip[slot].stEffect[i].cValue = value[i];
				}
				else if (type->Equals("Cargo")) {
					account->Cargo[slot].sIndex = index;
					account->Cargo[slot].stEffect[i].cEffect = effect[i];
					account->Cargo[slot].stEffect[i].cValue = value[i];
				}
			}
		}
	
		private: System::Void pbClickHandler(System::Object^ sender, System::EventArgs^ e) {
			String^ type = (String^)((PictureBox^)sender)->Tag;
			
			if (!(type->Equals("Cargo")) && charIndex < 0)
				return;

			int index = ((PictureBox^)sender)->TabIndex;

			if (type->Equals("Equip")) {
				DisplayFormItem(index + 1, type);

				pbArrEquip[index]->ImageLocation = GetValidPath(currentdir, account->Char[charIndex].Equip[index + 1].sIndex);
			}
			else if (type->Equals("Carry")) {
				DisplayFormItem(index, type);

				pbArrCarry[index % INVENTORY_SIZE]->ImageLocation = GetValidPath(currentdir, account->Char[charIndex].Carry[index].sIndex);
			}
			else if (type->Equals("Cargo")) {
				DisplayFormItem(index, type);

				pbArrVault[index % CARGO_SIZE]->ImageLocation = GetValidPath(currentdir, account->Cargo[index].sIndex);
			}
		}

		private: System::Void pbButtonClickHandler(System::Object^ sender, System::EventArgs^ e) {
			if (!account || !((PictureBox^)sender)->Tag->Equals("Cargo") && charIndex < 0)
				return;

			String^ type = (String^)((PictureBox^)sender)->Tag;
			int index = ((PictureBox^)sender)->TabIndex;

			if (type == "Carry") {
				for (int i = 0; i < pbButtonCarry->Length; i++) {
					pbButtonCarry[i]->ImageLocation = currentdir + "bag.png";
				}

				pbButtonCarry[index]->ImageLocation = currentdir + "bag_selected.png";

				for (int i = 0; i < pbArrCarry->Length; i++) {
					int id = i + index * INVENTORY_SIZE;

					pbArrCarry[i]->ImageLocation = GetValidPath(currentdir, account->Char[charIndex].Carry[id].sIndex);
					pbArrCarry[i]->TabIndex = id;
				}
					
			}
			
			else if (type == "Cargo") {
				for (int i = 0; i < pbButtonVault->Length; i++) {
					pbButtonVault[i]->ImageLocation = currentdir + "cargo_button" + (i+1) + ".png";
				}

				pbButtonVault[index]->ImageLocation = currentdir + "cargo_button" + (index+1) + "_selected.png";

				for (int i = 0; i < pbArrVault->Length; i++) {
					int id = i + index * CARGO_SIZE;

					pbArrVault[i]->ImageLocation = GetValidPath(currentdir, account->Cargo[id].sIndex);
					pbArrVault[i]->TabIndex = id;
				}
					
			}
			
		}

		void SetCharacterAttribute(TextBox^ tb, int& attribute) {
			if (!account || charIndex < 0) {
				tb->Clear();
				return;
			}

			string currentValue = (const char*)Marshal::StringToHGlobalAnsi(tb->Text).ToPointer();

			if (is_digits(currentValue)) {
				long long newValue = atol(currentValue.c_str());

				if (newValue < 0) {
					newValue = 0;
					tb->Text = "0";
				}

				if (newValue < INT_MAX)
					attribute = (int)newValue;

				else {
					attribute = INT_MAX;
					tb->Text = INT_MAX + "";
				}
			}
			else {
				tb->Text = attribute + "";
			}

			tb->SelectionStart = tb->Text->Length;
		}

		void SetCharacterAttribute(TextBox^ tb, short& attribute) {
			if (!account || charIndex < 0) {
				tb->Clear();
				return;
			}

			string currentValue = (const char*)Marshal::StringToHGlobalAnsi(tb->Text).ToPointer();

			if (is_digits(currentValue)) {
				long long newValue = atol(currentValue.c_str());

				if (newValue < 0) {
					newValue = 0;
					tb->Text = "0";
				}

				if (newValue < SHRT_MAX)
					attribute = (short)newValue;

				else {
					attribute = SHRT_MAX;
					tb->Text = SHRT_MAX + "";
				}
			}
			else {
				tb->Text = attribute + "";
			}

			tb->SelectionStart = tb->Text->Length;
		}

		void SetCharacterAttribute(TextBox^ tb, long long& attribute) {
			if (!account || charIndex < 0) {
				tb->Clear();
				return;
			}
				
			string currentValue = (const char*)Marshal::StringToHGlobalAnsi(tb->Text).ToPointer();

			if (is_digits(currentValue)) {
				long long newValue = atoll(currentValue.c_str());
				long long max = 8200000000;

				if (newValue > max) {
					newValue = max;
					tb->Text = max + "";
				}
				else if (newValue < 0) {

					newValue = 0;
					tb->Text = "0";
				}
				

				attribute = newValue;
			}
			else {
				tb->Text = attribute + "";
			}

			tb->SelectionStart = tb->Text->Length;
		}

		private: System::Void txtExperience_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			SetCharacterAttribute(txtExperience, account->Char[charIndex].Exp);
		}

		private: System::Void txtCoin_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			SetCharacterAttribute(txtCoin, account->Char[charIndex].Coin);
		}
		private: System::Void txtLevel_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			SetCharacterAttribute(txtLevel, account->Char[charIndex].BaseScore.Level);
		}

		private: System::Void txtPosX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			SetCharacterAttribute(txtPosX, account->Char[charIndex].SPX);
		}

		private: System::Void txtPosY_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			SetCharacterAttribute(txtPosY, account->Char[charIndex].SPY);
		}

		private: System::Void txtMaxHP_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			SetCharacterAttribute(txtMaxHP, account->Char[charIndex].BaseScore.MaxHp);
		}

		private: System::Void txtMaxMP_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			SetCharacterAttribute(txtMaxMP, account->Char[charIndex].BaseScore.MaxMp);
		}

		private: System::Void txtStr_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			SetCharacterAttribute(txtStr, account->Char[charIndex].BaseScore.Str);
		}

		private: System::Void txtDex_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			SetCharacterAttribute(txtDex, account->Char[charIndex].BaseScore.Dex);
		}

		private: System::Void txtInt_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			SetCharacterAttribute(txtInt, account->Char[charIndex].BaseScore.Int);
		}

		private: System::Void txtCon_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			SetCharacterAttribute(txtCon, account->Char[charIndex].BaseScore.Con);
		}

		private: System::Void txtSpecial0_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			SetCharacterAttribute(txtSpecial0, account->Char[charIndex].BaseScore.Special[0]);
		}

		private: System::Void txtSpecial1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			SetCharacterAttribute(txtSpecial1, account->Char[charIndex].BaseScore.Special[1]);
		}

		private: System::Void txtSpecial2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			SetCharacterAttribute(txtSpecial2, account->Char[charIndex].BaseScore.Special[2]);
		}

		private: System::Void txtSpecial3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			SetCharacterAttribute(txtSpecial3, account->Char[charIndex].BaseScore.Special[3]);
		}

		private: System::Void txtDonate_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			SetCharacterAttribute(txtDonate, account->mobExtra[charIndex].DonateInfo.Count);
		}

		private: System::Void comboBoxClass_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			account->Char[charIndex].Class = comboBoxClass->SelectedIndex;
		}

		private: System::Void pbArrMouseHover(System::Object^ sender, System::EventArgs^ e) {
			int index = ((PictureBox^)sender)->TabIndex;

			if (!account || !((PictureBox^)sender)->Tag->Equals("Cargo") && charIndex < 0)
				return;

			FormItemDescription^ instance = FormItemDescription::getInstance();

			int x = ((PictureBox^)sender)->Location.X + this->Location.X + (((PictureBox^)sender)->Size.Width / 2);
			int y = ((PictureBox^)sender)->Location.Y + this->Location.Y + (((PictureBox^)sender)->Size.Height / 2);

			int itemIndex = 0;
			int effect[3], value[3];

			for (int i = 0; i < 3; i++) {
				if (((PictureBox^)sender)->Tag->Equals("Carry")) {
					itemIndex	= account->Char[charIndex].Carry[index].sIndex;
					effect[i]	= account->Char[charIndex].Carry[index].stEffect[i].cEffect;
					value[i]	= account->Char[charIndex].Carry[index].stEffect[i].cValue;
				}
				else if (((PictureBox^)sender)->Tag->Equals("Equip")) {
					itemIndex	= account->Char[charIndex].Equip[index + 1].sIndex;
					effect[i]	= account->Char[charIndex].Equip[index + 1].stEffect[i].cEffect;
					value[i]	= account->Char[charIndex].Equip[index + 1].stEffect[i].cValue;
				}
				else if (((PictureBox^)sender)->Tag->Equals("Cargo")) {
					itemIndex	= account->Cargo[index].sIndex;
					effect[i]	= account->Cargo[index].stEffect[i].cEffect;
					value[i]	= account->Cargo[index].stEffect[i].cValue;
				}
			}

			instance->setInformation(itemIndex, effect[0], value[0], effect[1], value[1], effect[2], value[2]);
			instance->setLocation(x, y);
			instance->Show();

			instance->Visible = true;
		}

		private: System::Void pbArrMouseLeave(System::Object^ sender, System::EventArgs^ e) {
			FormItemDescription^ instance = FormItemDescription::getInstance();

			instance->Visible = false;
		}

		private: System::Void txtAccountName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			if (!account) {
				txtAccountName->Clear();
				return;
			}

			string accountname = (const char*)Marshal::StringToHGlobalAnsi((((TextBox^)sender)->Text)).ToPointer();

			if (accountname.length() > 15) {
				accountname.erase(accountname.begin() + 15, accountname.end());

				txtAccountName->Text = gcnew String(accountname.c_str());
				txtAccountName->SelectionStart = accountname.length();
			}

			strncpy_s(account->Info.AccountName, accountname.c_str(), 15);
		}

		private: System::Void txtPassword_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			if (!account) {
				txtPassword->Clear();
				return;
			}

			string password = (const char*)Marshal::StringToHGlobalAnsi((((TextBox^)sender)->Text)).ToPointer();

			if (password.length() > 11) {
				password.erase(password.begin() + 11, password.end());

				((TextBox^)sender)->Text = gcnew String(password.c_str());
				((TextBox^)sender)->SelectionStart = password.length();
			}

			strncpy_s(account->Info.AccountPass, password.c_str(), 11);

		}
		private: System::Void txtCode_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			if (!account) {
				txtCode->Clear();
				return;
			}

			string code = (const char*)Marshal::StringToHGlobalAnsi((((TextBox^)sender)->Text)).ToPointer();

			if (!is_digits(code)) {
				code.erase(code.end() - 1, code.end());

				((TextBox^)sender)->Text = gcnew String(code.c_str());
				((TextBox^)sender)->SelectionStart = code.length();

			}

			if (code.length() > 5) {
				code.erase(code.begin() + 5, code.end());

				((TextBox^)sender)->Text = gcnew String(code.c_str());
				((TextBox^)sender)->SelectionStart = txtAccountName->Text->Length;
			}

			strncpy_s(account->Info.NumericToken, code.c_str(), 5);
		}
	};
}
