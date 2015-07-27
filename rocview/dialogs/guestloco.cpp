/*
 Rocrail - Model Railroad Software
 Copyright (c) 2002-2015 Robert Jan Versluis, Rocrail.net
 All rights reserved.
*/
#include "guestloco.h"

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "wx/defs.h"
#endif

#include "rocrail/wrapper/public/Loc.h"

#include "rocview/public/guiapp.h"

GuestLoco::GuestLoco( wxWindow* parent )
  :GuestLocoGen( parent )
{
  m_StdButtonOK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_StdButtonCancel->SetLabel( wxGetApp().getMsg( "cancel" ) );
  SetTitle( wxGetApp().getMsg( "guestloco" ) );
  m_labAddress->SetLabel( wxGetApp().getMsg( "address" ) );
  m_labShortID->SetLabel( wxGetApp().getMsg( "shortid" ) );
  m_Speedsteps->SetLabel( wxGetApp().getMsg( "speedsteps" ) );
  m_Protocol->SetLabel( wxGetApp().getMsg( "protocol" ) );
  m_Protocol->SetString( 0, wxGetApp().getMsg( "default" ) );
  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);
}

void GuestLoco::onCancel( wxCommandEvent& event ) {
  EndModal( 0 );
}


void GuestLoco::onOK( wxCommandEvent& event ) {
  if( !wxGetApp().isStayOffline() ) {
    /* Notify RocRail. */
    iONode cmd = NodeOp.inst(wLoc.name(), NULL, ELEMENT_NODE);
    int addr  = m_Address->GetValue();
    int steps = m_Speedsteps->GetSelection();
    int prot  = m_Protocol->GetSelection();
    char val[32];
    StrOp.fmtb(val, "%d", addr);
    wLoc.setid(cmd, val );
    wLoc.setshortid(cmd, m_ShortID->GetValue().mb_str(wxConvUTF8) );
    wLoc.setV(cmd, 0);
    if( steps == 0 )
      wLoc.setspcnt(cmd, 14);
    else if( steps == 1 )
      wLoc.setspcnt(cmd, 28);
    else
      wLoc.setspcnt(cmd, 128);

    if( prot == 0 )
      wLoc.setprot(cmd, wLoc.prot_P);
    else if( prot == 1 )
      wLoc.setprot(cmd, (addr > 127) ? wLoc.prot_L:wLoc.prot_N);
    else if( prot == 2 )
      wLoc.setprot(cmd, wLoc.prot_M);

    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
  EndModal( wxID_OK );
}


void GuestLoco::onHelp( wxCommandEvent& event ) {
  wxGetApp().openLink( "rocview:guestloco" );
}

