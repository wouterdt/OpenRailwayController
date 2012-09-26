///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "bidibidendlggen.h"

///////////////////////////////////////////////////////////////////////////

BidibIdentDlgGen::BidibIdentDlgGen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer8->AddGrowableCol( 3 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labPath = new wxStaticText( this, wxID_ANY, wxT("Path"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labPath->Wrap( -1 );
	fgSizer8->Add( m_labPath, 0, wxALL, 5 );
	
	m_labUID = new wxStaticText( this, wxID_ANY, wxT("Unique-ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labUID->Wrap( -1 );
	fgSizer8->Add( m_labUID, 0, wxALL, 5 );
	
	m_labVendor = new wxStaticText( this, wxID_ANY, wxT("Vendor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labVendor->Wrap( -1 );
	fgSizer8->Add( m_labVendor, 0, wxALL, 5 );
	
	m_labClass = new wxStaticText( this, wxID_ANY, wxT("Class"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labClass->Wrap( -1 );
	fgSizer8->Add( m_labClass, 0, wxALL, 5 );
	
	m_Path = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	fgSizer8->Add( m_Path, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_UID = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxTE_CENTRE|wxTE_READONLY );
	fgSizer8->Add( m_UID, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_Vendor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 120,-1 ), wxTE_READONLY );
	fgSizer8->Add( m_Vendor, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_Class = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), wxTE_READONLY );
	fgSizer8->Add( m_Class, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	bSizer7->Add( fgSizer8, 0, wxEXPAND, 5 );
	
	m_stdButtons = new wxStdDialogButtonSizer();
	m_stdButtonsOK = new wxButton( this, wxID_OK );
	m_stdButtons->AddButton( m_stdButtonsOK );
	m_stdButtonsCancel = new wxButton( this, wxID_CANCEL );
	m_stdButtons->AddButton( m_stdButtonsCancel );
	m_stdButtons->Realize();
	bSizer7->Add( m_stdButtons, 0, wxEXPAND|wxALL, 5 );
	
	this->SetSizer( bSizer7 );
	this->Layout();
	bSizer7->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_stdButtonsCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BidibIdentDlgGen::onCancel ), NULL, this );
	m_stdButtonsOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BidibIdentDlgGen::onOK ), NULL, this );
}

BidibIdentDlgGen::~BidibIdentDlgGen()
{
	// Disconnect Events
	m_stdButtonsCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BidibIdentDlgGen::onCancel ), NULL, this );
	m_stdButtonsOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BidibIdentDlgGen::onOK ), NULL, this );
	
}
