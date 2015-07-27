/*
 Rocrail - Model Railroad Software

Copyright (c) 2002-2015 Robert Jan Versluis, Rocrail.net

 


 All rights reserved.
*/
#ifndef __cardlg__
#define __cardlg__

/**
@file
Subclass of CarDlg, which is generated by wxFormBuilder.
*/

#include "cardlggen.h"
#include "basenotebook.h"

#include "basedlg.h"
#include "rocs/public/node.h"

/** Implementing CarDlg */
class CarDlg : public cardlggen, public BaseDialog
{
  iONode m_Props;
  bool   m_bSave;
  int    m_TabAlign;
  int    m_SetPage;
  int    m_SortCol;
  int    m_FGroup;
  void initCVDesc();
  const char* m_CVDesc[256];
  int m_iSelectedCV;
  iONode m_CVNodes[1024];
  const char* m_Train4Add;
  const char* m_Train4AddConsist;
  const char* m_Train4AddLocality;

  void initLabels();
  bool evaluate();
  void initIndex();
  void initValues();
  void initSubType();
  void initLocationCombo();
  int findID( const char* ID );
  void setSelection(const char* ID);
  void initFunctions();
  void evaluateFunctions();

public:
  static const char* findTrain(const char* carid);
	/** Constructor */
  CarDlg( wxWindow* parent, iONode p_Props, bool save=true, const char* train=NULL, const char* consist=NULL, const char* locality=NULL );

  void onCarImage( wxCommandEvent& event );
  void onCarList2( wxListEvent& event );
  void onNewCar( wxCommandEvent& event );
  void onDeleteCar( wxCommandEvent& event );
  void onTypeSelect( wxCommandEvent& event );
  void onApply( wxCommandEvent& event );
  void onCancel( wxCommandEvent& event );
  void onOK( wxCommandEvent& event );
  void onSetPage( wxCommandEvent& event );
  void onImport( wxCommandEvent& event );
  iONode getSelectedCar();
  void OnCopy( wxCommandEvent& event );
  void onDoc( wxCommandEvent& event );
  void onListColClick( wxListEvent& event );
  void onFG( wxCommandEvent& event );
  void onCVCell( wxGridEvent& event );
  void onCVModify( wxCommandEvent& event );
  void onShow( wxCommandEvent& event );
  void onListAvailableOnly( wxCommandEvent& event );
  void onF0Icon( wxMouseEvent& event );
  void onF1Icon( wxMouseEvent& event );
  void onF2Icon( wxMouseEvent& event );
  void onF3Icon( wxMouseEvent& event );
  void onF4Icon( wxMouseEvent& event );
  void onHelp( wxCommandEvent& event );
  void onImageChooser( wxCommandEvent& event );
};

#endif // __cardlg__
