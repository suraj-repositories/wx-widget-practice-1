#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainFrame* frame = new MainFrame("C++ App");
	frame->SetClientSize(800, 600);
	frame->Center();
	frame->Show(true);
	return true;
}