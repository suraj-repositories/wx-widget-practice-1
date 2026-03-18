#include "MainFrame.h"
#include <wx/wx.h> 

/*
	Custom id rules
	- must be positive,
	- can be 0 or 1
	- can be from wxID_LOWEST(4999) to wxID_HIGHEST(5999)
*/
enum IDs {
	BUTTON_ID = 2,
	SLIDER_ID = 3,
	TEXT_ID = 4,
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_BUTTON(BUTTON_ID, MainFrame::OnBUttonClicked)
EVT_SLIDER(SLIDER_ID, MainFrame::OnSliderChanged)
EVT_TEXT(TEXT_ID, MainFrame::OnTextChanged)
wxEND_EVENT_TABLE();

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

	wxPanel* panel = new wxPanel(this);
 
	wxButton* button = new wxButton(panel, BUTTON_ID, "Button", wxPoint(300, 275), wxSize(200, 50));
	wxSlider* slider = new wxSlider(panel, SLIDER_ID, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
	wxTextCtrl* textCtrl = new wxTextCtrl(panel, TEXT_ID, "", wxPoint(300, 375), wxSize(200, -1));

	CreateStatusBar();

}

void MainFrame::OnBUttonClicked(wxCommandEvent& evt) {
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