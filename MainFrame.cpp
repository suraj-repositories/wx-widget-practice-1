#include "MainFrame.h"
#include <wx/wx.h> 

// use dynamic event handling
  
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

	wxPanel* panel = new wxPanel(this);
 
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 275), wxSize(200, 50));
	wxSlider* slider = new wxSlider(panel, wxID_ANY, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 375), wxSize(200, -1));

	button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	slider->Bind(wxEVT_SLIDER, &MainFrame::OnSliderChanged, this);
	textCtrl->Bind(wxEVT_TEXT, &MainFrame::OnTextChanged, this);

	button->Unbind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

	CreateStatusBar();

}

void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	wxLogStatus("Button clicked!");
}

void MainFrame::OnSliderChanged(wxCommandEvent& evt) {
	//int value = evt.GetInt();
	//wxLogStatus("Slider value: %d", value);

	wxString str = wxString::Format("Slider Value: %d", evt.GetInt());
	wxLogStatus( str);
}

void MainFrame::OnTextChanged(wxCommandEvent& evt) {
	wxString text = evt.GetString();
	wxLogStatus("Text changed: %s", text);
}