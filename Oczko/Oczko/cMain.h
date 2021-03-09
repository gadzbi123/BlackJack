#pragma once
#include "wx/wx.h"

class cMain: public wxFrame
{
public:
	cMain();
	~cMain();

public:
	wxButton *m_button = nullptr;
	wxTextCtrl* m_txt = nullptr;
	wxListBox* m_list = nullptr;
};

