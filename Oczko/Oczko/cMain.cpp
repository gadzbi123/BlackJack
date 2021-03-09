#include "cMain.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Cosiek",wxPoint(30,30),wxSize(800,600))
{
	m_button = new wxButton(this,wxID_ANY,"Klikaj",wxPoint(10,10),wxSize(150,50));
	m_txt = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	m_list = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
}

cMain::~cMain()
{

}