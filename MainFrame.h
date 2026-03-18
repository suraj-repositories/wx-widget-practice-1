
#include<wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

private: 
	void OnBUttonClicked(wxCommandEvent& evt);
	void OnSliderChanged(wxCommandEvent& evt);
	void OnTextChanged(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};