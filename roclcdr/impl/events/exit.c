/*
 Rocrail - Model Railroad Software

Copyright (c) 2002-2015 Robert Jan Versluis, Rocrail.net

 


 All rights reserved.
*/

#include "roclcdr/impl/lcdriver_impl.h"

#include "roclcdr/impl/tools/tools.h"
#include "rocs/public/strtok.h"
#include "rocs/public/system.h"



#include "rocrail/public/model.h"

#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/Schedule.h"
#include "rocrail/wrapper/public/ScheduleEntry.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/Link.h"



void eventExit( iOLcDriver inst, const char* blockId, Boolean curBlockEvent, Boolean dstBlockEvent ) {
  iOLcDriverData data = Data(inst);

  Boolean newExitEvent = False;
  if( data->prevexit + data->ignevt < SystemOp.getTick() && StrOp.equals( blockId, data->prevexitbkid ) ) {
    data->prevexit = SystemOp.getTick();
    data->prevexitbkid = blockId;
    newExitEvent = True;
  }
  else if( !StrOp.equals( blockId, data->prevexitbkid ) ) {
    data->prevexit = SystemOp.getTick();
    data->prevexitbkid = blockId;
    newExitEvent = True;
  }
  else {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 4101,
                   "Ignoring exit_block event from %s; it came within %d ticks!", blockId, data->ignevt );
  }

  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201,
                 "exit_block event for \"%s\" from \"%s\"...",
                 data->loc->getId( data->loc ), blockId );

  if( newExitEvent && curBlockEvent && ( data->state == LC_GO || data->state == LC_GO || data->state == LC_CHECKROUTE ) ) {
    data->state = LC_EXITBLOCK;
    data->loc->setMode(data->loc, wLoc.mode_auto, "");
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201,
                   "Setting state for \"%s\" to LC_EXITBLOCK.",
                   data->loc->getId( data->loc ) );
  }
  else if( newExitEvent ) {
    if( !dstBlockEvent ) {
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
                     "Check wheels of leaving train for dirt or using some isolated wheels?" );
    }
    else {

      /* Exception! */
      /* Train too long??? */
      /* Leaving train has dirty wheels! */
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 4101,
                     "Unexpected exit_block event for \"%s\" from \"%s\"!",
                     data->loc->getId( data->loc ), blockId );
      /* Break: */
      data->loc->brake( data->loc );
      /* Switch to manual mode: */
      data->loc->stop( data->loc, False );

      data->state = LC_IDLE;
      data->loc->setMode(data->loc, wLoc.mode_idle, wLoc.modereason_unexpectedexit);
      data->run = False;
      if( data->curBlock != NULL ) {
        data->curBlock->exitBlock(data->curBlock, data->loc->getId( data->loc ), True);
      }

      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 4101,
                     "Loc set back in manual mode for \"%s\" in \"%s\"! (correct position of loc)",
                     data->loc->getId( data->loc ), blockId );


      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 4101,
                   "*** Train too long or block too short!!!" );
    }
    /*AppOp.stop(  );*/
  }

}

