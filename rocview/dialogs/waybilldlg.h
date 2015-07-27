/*
 Rocrail - Model Railroad Software

Copyright (c) 2002-2015 Robert Jan Versluis, Rocrail.net

 


 All rights reserved.
*/
#ifndef __waybilldlg__
#define __waybilldlg__

/**
@file
Subclass of waybillgen, which is generated by wxFormBuilder.
*/

#include "waybilldlggen.h"
#include "basenotebook.h"

#include "rocs/public/node.h"

/** Implementing waybillgen */
class WaybillDlg : public waybillgen
{
  iONode m_Props;
  bool   m_bSave;
  int    m_TabAlign;
  int    m_SetPage;

  void initLabels();
  bool evaluate();
  void initIndex();
  void initValues();
  void initLocationCombo();

public:
  /** Constructor */
  WaybillDlg( wxWindow* parent, iONode node, bool save=true );

  void onWaybillList( wxCommandEvent& event );
  void onNewWaybill( wxCommandEvent& event );
  void onDeleteWaybill( wxCommandEvent& event );
  void onApply( wxCommandEvent& event );
  void onCancel( wxCommandEvent& event );
  void OnCopy( wxCommandEvent& event );
  void onOK( wxCommandEvent& event );
  void onSetPage( wxCommandEvent& event );
  void onHelp( wxCommandEvent& event );

  iONode getSelectedWaybill();
  bool isDelivered();

};

#endif // __waybilldlg__
