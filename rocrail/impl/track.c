/*
 Rocrail - Model Railroad Software

Copyright (c) 2002-2015 Robert Jan Versluis, Rocrail.net

 


 All rights reserved.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "rocrail/impl/track_impl.h"
#include "rocrail/public/app.h"
#include "rocrail/public/model.h"
#include "rocrail/public/switch.h"

#include "rocs/public/doc.h"
#include "rocs/public/trace.h"
#include "rocs/public/node.h"
#include "rocs/public/mem.h"
#include "rocs/public/str.h"


#include "rocrail/wrapper/public/Track.h"

static int instCnt = 0;

/*
 ***** OBase functions.
 */
static const char* __id( void* inst ) {
  return NULL;
}

static void* __event( void* inst, const void* evt ) {
  return NULL;
}

static const char* __name(void) {
  return name;
}
static unsigned char* __serialize(void* inst, long* size) {
  return NULL;
}
static void __deserialize(void* inst, unsigned char* a) {
}
static char* __toString(void* inst) {
  return (char*)TrackOp.getId( (iOTrack)inst );
}
static void __del(void* inst) {
  iOTrackData data = Data(inst);
  freeMem( data );
  freeMem( inst );
  instCnt--;
}
static void* __properties(void* inst) {
  iOTrackData data = Data(inst);
  return data->props;
}
static struct OBase* __clone( void* inst ) {
  return NULL;
}
static Boolean __equals( void* inst1, void* inst2 ) {
  return False;
}
static int __count(void) {
  return instCnt;
}


/*
 ***** _Public functions.
 */
static const char* _getId( iOTrack inst ) {
  iOTrackData data = Data(inst);
  return wTrack.getid( data->props );
}

/**
 * Checks for property changes.
 * todo: Range checking?
 */
static void _modify( iOTrack inst, iONode props ) {
  iOTrackData o = Data(inst);
  int cnt = NodeOp.getAttrCnt( props );
  int i = 0;
  for( i = 0; i < cnt; i++ ) {
    iOAttr attr = NodeOp.getAttr( props, i );
    const char* name  = AttrOp.getName( attr );
    const char* value = AttrOp.getVal( attr );
    NodeOp.setStr( o->props, name, value );
  }

  /* Broadcast to clients. */
  {
    iONode clone = (iONode)NodeOp.base.clone( o->props );
    AppOp.broadcastEvent( clone );
  }
  props->base.del(props);
}

static iOTrack _inst( iONode props ) {
  iOTrack     track = allocMem( sizeof( struct OTrack ) );
  iOTrackData data  = allocMem( sizeof( struct OTrackData ) );

  /* OBase operations */
  MemOp.basecpy( track, &TrackOp, 0, sizeof( struct OTrack ), data );

  data->props = props;
  NodeOp.removeAttrByName(data->props, "cmd");

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "inst for %s", _getId(track) );

  instCnt++;

  return track;
}


/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocrail/impl/track.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/

