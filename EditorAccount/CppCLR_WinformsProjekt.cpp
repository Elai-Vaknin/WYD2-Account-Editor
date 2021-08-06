#include "pch.h"

using namespace System;

#include "FormMain.h"
#include "FormItemModify.h"

using namespace System::Windows::Forms;

[STAThread]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew EditorAccount::FormMain());
	return 0;
}