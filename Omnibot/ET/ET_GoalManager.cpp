////////////////////////////////////////////////////////////////////////////////
// 
// $LastChangedBy: drevil $
// $LastChangedDate: 2010-04-24 22:51:13 -0500 (Sat, 24 Apr 2010) $
// $LastChangedRevision: 4828 $
//
////////////////////////////////////////////////////////////////////////////////

#include "PrecompET.h"
#include "ET_GoalManager.h"
#include "ET_NavigationFlags.h"

ET_GoalManager::ET_GoalManager()
{
	m_Instance = this;
}

ET_GoalManager::~ET_GoalManager()
{
	Shutdown();
}

void ET_GoalManager::CheckWaypointForGoal(Waypoint *_wp, BitFlag64 _used)
{
	enum { MaxGoals=8 };

	MapGoalDef Definition[MaxGoals];
	int NumDefs = 0;

	//////////////////////////////////////////////////////////////////////////

	if(_wp->IsFlagOn(F_ET_NAV_MG42SPOT))
	{
		/*MapGoalPtr goal(new ET_MobileMG42Goal());
		newGoals.push_back(goal);*/

		Definition[NumDefs++].Props.SetString("Type","MOBILEMG42");
	}
	if(_wp->IsFlagOn(F_ET_NAV_MORTAR))
	{
		/*MapGoalPtr goal(new ET_MobileMortarGoal());
		newGoals.push_back(goal);*/

		Definition[NumDefs++].Props.SetString("Type","MOBILEMORTAR");
	}
	if(_wp->IsFlagOn(F_ET_NAV_ARTSPOT))
	{
		/*MapGoalPtr goal(new ET_CallArtyGoal());
		newGoals.push_back(goal);*/

		Definition[NumDefs++].Props.SetString("Type","CALLARTILLERY");
	}
	if(_wp->IsFlagOn(F_ET_NAV_ARTYTARGET_S))
	{
		/*MapGoalPtr goal(new ET_CallArtyTargetGoal_Static());
		newGoals.push_back(goal);*/

		Definition[NumDefs++].Props.SetString("Type","ARTILLERY_S");
	}
	if(_wp->IsFlagOn(F_ET_NAV_ARTYTARGET_D))
	{
		/*MapGoalPtr goal(new ET_CallArtyTargetGoal_Dynamic());
		newGoals.push_back(goal);*/

		Definition[NumDefs++].Props.SetString("Type","ARTILLERY_D");
	}
	if(_wp->IsFlagOn(F_ET_NAV_MINEAREA))
	{
		/*MapGoalPtr goal(new ET_PlantMineGoal());
		newGoals.push_back(goal);*/

		Definition[NumDefs++].Props.SetString("Type","PLANTMINE");
	}
	if(_wp->IsFlagOn(F_ET_NAV_CAPPOINT))
	{
		/*MapGoalPtr goal(new FlagCapGoal());
		newGoals.push_back(goal);*/

		Definition[NumDefs++].Props.SetString("Type","cappoint");
	}
	if(_wp->IsFlagOn(F_ET_NAV_FLAMETHROWER))
	{
		/*MapGoalPtr goal(new ET_FlamethrowerGoal());
		newGoals.push_back(goal);*/

		Definition[NumDefs++].Props.SetString("Type","FLAME");
	}
	if(_wp->IsFlagOn(F_ET_NAV_PANZER))
	{
		/*MapGoalPtr goal(new ET_PanzerGoal());
		newGoals.push_back(goal);*/

		Definition[NumDefs++].Props.SetString("Type","PANZER");
	}
	//version 0.7x feature, per gfs possibly auto create if wp has a name
	/*if(_wp->IsFlagOn(F_ET_NAV_USERGOAL))
	{
		MapGoalPtr goal(new ET_UserGoal());
		newGoals.push_back(goal);
	}*/

	RegisterWaypointGoals(_wp,Definition,NumDefs);
	
	// Allow the base class to process it.
	GoalManager::CheckWaypointForGoal(_wp, _used);
}
