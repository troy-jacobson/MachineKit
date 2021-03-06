/********************************************************************
* Description:  rt-preempt-user.h
*               This file defines the differences specific to the
*               the RT_PREEMPT thread system
*
*		It should be included in rtapi_common.h
********************************************************************/

#define REV_CODE 5	// see rtapi_common.h


/***********************************************************************
*                           TASK FUNCTIONS                             *
************************************************************************/
#include "config.h"
#include <sched.h>		// sched_get_priority_*()
#include <pthread.h>		/* pthread_* */



/* rtapi_io.c */
#ifdef RTAPI_IO		// only define these for rtapi_io.c
#define HAVE_RTAPI_OUTB_HOOK
inline void rtapi_outb_hook(unsigned char byte, unsigned int port) { return; }
#define HAVE_RTAPI_INB_HOOK
inline unsigned char rtapi_inb_hook(unsigned int port) { return 0; }
#endif


/* rtapi_task.c */
#define PRIO_LOWEST sched_get_priority_min(SCHED_FIFO)
#define PRIO_HIGHEST sched_get_priority_max(SCHED_FIFO)

#define HAVE_RTAPI_TASK_NEW_HOOK
#define HAVE_RTAPI_TASK_DELETE_HOOK
#define HAVE_RTAPI_TASK_STOP_HOOK
#define HAVE_RTAPI_WAIT_HOOK


/* misc */
#define HAVE_RTAPI_TASK_FREE
#define HAVE_DROP_RESTORE_PRIVS


