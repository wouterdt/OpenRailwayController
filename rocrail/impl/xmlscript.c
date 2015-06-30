/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2015 Rob Versluis, Rocrail.net

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include "rocrail/impl/xmlscript_impl.h"

#include "rocrail/public/app.h"
#include "rocrail/public/model.h"
#include "rocrail/public/text.h"
#include "rocrail/public/var.h"
#include "rocrail/public/loc.h"

#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/Loc.h"

#include "rocs/public/mem.h"
#include "rocs/public/trace.h"
#include "rocs/public/node.h"

static int instCnt = 0;

/** ----- OBase ----- */
static void __del( void* inst ) {
}

static const char* __name( void ) {
  return name;
}

static unsigned char* __serialize( void* inst, long* size ) {
  return NULL;
}

static void __deserialize( void* inst,unsigned char* bytestream ) {
  return;
}

static char* __toString( void* inst ) {
  return NULL;
}

static int __count( void ) {
  return instCnt;
}

static struct OBase* __clone( void* inst ) {
  return NULL;
}

static Boolean __equals( void* inst1, void* inst2 ) {
  return False;
}

static void* __properties( void* inst ) {
  return NULL;
}

static const char* __id( void* inst ) {
  return NULL;
}

static void* __event( void* inst, const void* evt ) {
  return NULL;
}

/** ----- OXmlScript ----- */


/**  */

static Boolean __isWhere(const char* whereRes) {
  Boolean ok = True;
  /* ToDo: Check the where clausel. */

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "where [%s] is %s", whereRes, ok?"true":"false" );
  return ok;
}

static void __executeCmd(iONode cmd) {
  iOModel model = AppOp.getModel();
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "execute [%s]", NodeOp.getName(cmd) );
  if( StrOp.equals( wFunCmd.name(), NodeOp.getName(cmd)) ) {
    iOLoc lc = ModelOp.getLoc(model, wItem.getid(cmd), NULL, False);
    if( lc != NULL )
      LocOp.cmd(lc, (iONode)NodeOp.base.clone(cmd));
  }
}


static void __doForEach(iONode nodeScript) {
  iOModel model = AppOp.getModel();
  iONode plan = ModelOp.getModel(model);
  iONode table = NodeOp.findNode(plan, NodeOp.getStr(nodeScript, "table", ""));
  const char* where = NodeOp.getStr(nodeScript, "where", "");
  if( table != NULL && where != NULL ) {
    int childs = NodeOp.getChildCnt(table);
    int i = 0;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "for each in table [%s] where [%s]", NodeOp.getName(table), where );
    for( i = 0; i < childs; i++ ) {
      iONode child = NodeOp.getChild( table, i);
      iOMap map = MapOp.inst();
      const char* oid = wItem.getid(child);
      MapOp.put(map, "oid", (obj)oid);
      char* whereRes = TextOp.replaceAllSubstitutions(where, map);
      MapOp.base.del(map);
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "for each in table [%s] where [%s]", NodeOp.getName(table), whereRes );

      if( __isWhere(whereRes) ) {
        int cmds = NodeOp.getChildCnt(nodeScript);
        int n = 0;
        for( n = 0; n < cmds; n++ ) {
          iONode cmd = NodeOp.getChild(nodeScript, n);
          wItem.setid(cmd, oid);
          __executeCmd(cmd);
        }
      }

      StrOp.free(whereRes);
    }


  }
}


/*
<foreach table="lclist" where="#var2%oid% < &time">
  <fn f3="true"/>
  <var id="#var2%oid%" val="0"/>
  <lc cmd="go"/>
</foreach>
 */
static void _run(const char* script) {
  iODoc  doc        = DocOp.parse(script);
  iONode nodeScript = NULL;
  if( doc != NULL && DocOp.getRootNode(doc) != NULL) {
    nodeScript = DocOp.getRootNode(doc);
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "script: [%s]", NodeOp.getName(nodeScript) );
    if( StrOp.equals( "foreach", NodeOp.getName(nodeScript) ) ) {
      __doForEach(nodeScript);
    }

    NodeOp.base.del(nodeScript);
  }

  if( doc != NULL)
    DocOp.base.del(doc);

}



/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocrail/impl/xmlscript.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
