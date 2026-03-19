#include "MainFrame.h"
#include <wx/wx.h> 
 

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

	//wxPanel* panel = new wxPanel(this);
	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS);
 
	/*
		other key event types include:
		wxEVT_KEY_UP,
		wxEVT_CHAR, 
		wxEVT_CHAR_HOOK, 
		wxEVT_CHAR_MAX
	*/
	//panel->Bind(wxEVT_KEY_DOWN, &MainFrame::onKeyEvent, this);

	wxButton* btn1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 150), wxSize(200, 100), wxWANTS_CHARS);
	wxButton* btn2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 100));

	//btn1->Bind(wxEVT_KEY_DOWN, &MainFrame::onKeyEvent, this);

	panel->Bind(wxEVT_CHAR_HOOK, &MainFrame::onKeyEvent, this);

	CreateStatusBar();

}

void MainFrame::onKeyEvent(wxKeyEvent& evt) {

	// when uses wxWANTS_CHARS on button the tab and arrow will not work - so you need to handle them manually
	if (evt.GetKeyCode() == WXK_TAB) {
		wxWindow* window = (wxWindow*)evt.GetEventObject();
		window->Navigate();
	}

	//if (evt.GetUnicodeKey() == 'A') {
	//	wxLogStatus("You pressed the A key!");
	//}
	//else if (evt.GetKeyCode() == WXK_HOME) {
	//	wxLogStatus("HOME was pressed");
	//}
	//return;

	wxChar keyChar = evt.GetUnicodeKey();
	if (keyChar == WXK_NONE) {
		int keyCode = evt.GetKeyCode();
		wxLogStatus("You pressed a non-character key with code %d", keyCode);
	}
	else {
		wxLogStatus("You pressed the '%c' key!", keyChar);
	}
	 
}
 