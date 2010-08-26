////////////////////////////////////////////////////////////////////////////////
// 
// $LastChangedBy: DrEvil $
// $LastChangedDate: 2006-09-04 09:36:01 -0700 (Mon, 04 Sep 2006) $
// $LastChangedRevision: 1265 $
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _GM_TRIGGERINFO_H_
#define _GM_TRIGGERINFO_H_

#include "gmBind.h"

class gmTriggerInfo : public gmBind<TriggerInfo, gmTriggerInfo>
{
public:
	GMBIND_DECLARE_PROPERTIES( );

	// Property Accessors
	static bool getName( TriggerInfo *a_native, gmThread *a_thread, gmVariable *a_operands );
	static bool getAction( TriggerInfo *a_native, gmThread *a_thread, gmVariable *a_operands );
	static bool getActivator( TriggerInfo *a_native, gmThread *a_thread, gmVariable *a_operands );
	static bool getEntity( TriggerInfo *a_native, gmThread *a_thread, gmVariable *a_operands );

	static TriggerInfo *Constructor(gmThread *a_thread);
	static void Destructor(TriggerInfo *_native);
};

#endif
