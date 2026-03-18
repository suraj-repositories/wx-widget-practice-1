#include "MainFrame.h"
#include <wx/wx.h> 

// Event propagation
// window -> panel -> button

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

	wxPanel* panel = new wxPanel(this);
 
	wxButton* button1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 275), wxSize(200, 50));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 50));

	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::onClose, this);
	this->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this);
	button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this);
	button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this);

	CreateStatusBar();

}

void MainFrame::onClose(wxCloseEvent& evt) {
	wxLogMessage("Window is closing...");
	evt.Skip(); // allow event to propagate to parent
}

void MainFrame::OnAnyButtonClicked(wxCommandEvent& evt) {
	wxLogMessage("Button clicked!");
}
void MainFrame::OnButton1Clicked(wxCommandEvent& evt) {
	wxLogStatus("Button 1 clicked!");
	evt.Skip(); // allow event to propagate to parent
}
void MainFrame::OnButton2Clicked(wxCommandEvent& evt) {
	wxLogStatus("Button 2 clicked!");
	evt.Skip(); // allow event to propagate to parent
}
 