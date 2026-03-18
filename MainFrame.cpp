#include "MainFrame.h"
#include <wx/wx.h> 
 

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

	wxPanel* panel = new wxPanel(this);
 
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 250), wxSize(200, 100));
	
	wxStatusBar* statusBar = CreateStatusBar();
	statusBar->SetDoubleBuffered(true); // stop Buffering

	// Available actions
	/*
	wxEVT_LEFT_DOWN, 
	wxEVT_LEFT_UP, 
	wxEVT_RIGHT_DOWN, 
	wxEVT_RIGHT_UP, 
	wxEVT_MIDDLE_DOWN, 
	wxEVT_MIDDLE_UP, 
	wxEVT_MOTION 
	*/
	  
	panel->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
	button->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);

}

void MainFrame::OnMouseEvent(wxMouseEvent& evt) {

	//wxPoint mousePos = evt.GetPosition();
	wxPoint mousePos = wxGetMousePosition();

	mousePos = this->ScreenToClient(mousePos); // convert to client coordinates
	wxString message = wxString::Format("Mouse event detected at (%d, %d)", mousePos.x, mousePos.y);

	wxLogStatus(message);
}
 