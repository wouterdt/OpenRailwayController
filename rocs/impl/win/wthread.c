/*
 Rocs - OS independent C library

Copyright (c) 2002-2015 Robert Jan Versluis, Rocrail.net

 


 All rights reserved.
*/
#ifdef _WIN32 

#include <stdlib.h>
#include <string.h>
#include <process.h>
#include <stddef.h>
#include <stdio.h>

#include <windows.h>

#include "rocs/impl/thread_impl.h"


#ifndef __ROCS_THREAD__
	#pragma message("*** Win32 OThread is disabled. (define __ROCS_THREAD__ in rocs.h) ***")
#endif

static void rocs_thread_wrapper( void* inst ) {
#ifdef __ROCS_THREAD__
  iOThreadData o = Data(inst);
  o->id = __threadid();
  o->run( inst );
#endif
}

Boolean rocs_thread_start( iOThread inst ) {
#ifdef __ROCS_THREAD__
  iOThreadData o = Data(inst);
  int stacksize = 0;
  /* TODO: Returns a handle; not an id!!!
  o->id = _beginthread( o->run, 0, inst );
  */
  if( o->stacksize > 0 )
    stacksize = o->stacksize;
  o->handle = _beginthread( rocs_thread_wrapper, stacksize, inst );
  return o->handle == 1 ? False:True;
#endif
}

void rocs_thread_sleep( const int ms ) {
#ifdef __ROCS_THREAD__
  Sleep( ms );
#endif
}

unsigned long rocs_thread_id(void) {
#ifdef __ROCS_THREAD__
  return __threadid();
#else
  return 0;
#endif
}

void rocs_thread_kill( iOThread inst ) {
#ifdef __ROCS_THREAD__
  iOThreadData o = Data(inst);
  TerminateThread( (void*)o->handle, 0 );
#endif
}

void rocs_thread_high( iOThread inst ) {
#ifdef __ROCS_THREAD__
  iOThreadData o = Data(inst);
  SetThreadPriority((void*)o->handle, THREAD_PRIORITY_TIME_CRITICAL );
#endif
}

Boolean rocs_thread_join( iOThread inst ) {
#ifdef __ROCS_THREAD__
  iOThreadData o = Data(inst);
  WaitForSingleObject( (void*)o->handle, INFINITE );
  return True;
#endif
}

#endif
