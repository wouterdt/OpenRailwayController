/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2012 Rob Versluis, Rocrail.net

 Without an official permission commercial use is not permitted.
 Forking this project is not permitted.

 This program is free software; you can redistribute it and/or
 as published by the Free Software Foundation; either version 2
 modify it under the terms of the GNU General Public License
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef __bidibidentdlg__
#define __bidibidentdlg__

/**
@file
Subclass of BidibIdentDlgGen, which is generated by wxFormBuilder.
*/

#include "bidibidendlggen.h"

#include "rocs/public/node.h"
#include "rocs/public/list.h"
#include "rocs/public/map.h"

//// end generated include

/** Implementing BidibIdentDlgGen */
class BidibIdentDlg : public BidibIdentDlgGen
{
  iONode node;
  iOList nodeList;
  iOMap nodeMap;
  wxTreeItemId findTreeItem( const wxTreeItemId& root, const wxString& text);
  int getLevel(const char* path );
  wxTreeItemId addTreeChild( const wxTreeItemId& root, iONode bidibnode);
  protected:
		// Handlers for BidibIdentDlgGen events.
		void onCancel( wxCommandEvent& event );
		void onOK( wxCommandEvent& event );
    void onTreeSelChanged( wxTreeEvent& event );
    void onSetup( wxCommandEvent& event );
    void onBeginDrag( wxTreeEvent& event );
    void onItemActivated( wxTreeEvent& event );
	public:
		/** Constructor */
		BidibIdentDlg( wxWindow* parent );
	//// end generated class members
    BidibIdentDlg( wxWindow* parent, iONode node );
    ~BidibIdentDlg();
    void event(iONode node);
    void initLabels();
    void initValues();
	
};

#endif // __bidibidentdlg__
