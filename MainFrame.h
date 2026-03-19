
#include<wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

private: 
	void onKeyEvent(wxKeyEvent& evt);
};