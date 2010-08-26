////////////////////////////////////////////////////////////////////////////////
// 
// $LastChangedBy: drevil $
// $LastChangedDate: 2009-11-08 15:53:48 -0600 (Sun, 08 Nov 2009) $
// $LastChangedRevision: 4521 $
//
////////////////////////////////////////////////////////////////////////////////

#include "PrecompCommon.h"
#include "NavigationManager.h"
#include "IGameManager.h"
#include "IGame.h"

#include "PathPlannerWaypoint.h"
#include "PathPlannerNavMesh.h"
#include "PathPlannerFloodFill.h"
#include "PathPlannerRecast.h"

NavigationManager *NavigationManager::m_Instance = 0;

NavigationManager::NavigationManager() : 
	m_PathPlanner(0)
{
}

NavigationManager::~NavigationManager()
{
	DeletePathPlanner();
}

bool NavigationManager::CreatePathPlanner(NavigatorID _navid)
{
	switch(_navid)
	{
	case NAVID_WP:
		m_PathPlanner = new PathPlannerWaypoint;		
		break;
	case NAVID_NAVMESH:
		m_PathPlanner = new PathPlannerNavMesh;
		break;
	case NAVID_FLOODFILL:
		m_PathPlanner = new PathPlannerFloodFill;
		break;
	case NAVID_RECAST:
		m_PathPlanner = new PathPlannerRecast;
		break;
	default:
		LOGERR_BASIC("Unknown Path Planner!");
	};

	OBASSERT(m_PathPlanner, "No Path Planner!");
	if(m_PathPlanner && m_PathPlanner->Init())
	{
		// Allow the game to set up its navigation flags.
		IGameManager::GetInstance()->GetGame()->RegisterNavigationFlags(m_PathPlanner);
		return true;
	}

	OB_DELETE(m_PathPlanner);
	return false;
}

void NavigationManager::DeletePathPlanner()
{
	if(m_PathPlanner)
	{
		m_PathPlanner->Shutdown();
		OB_DELETE(m_PathPlanner);
	}
}

PathPlannerBase *NavigationManager::GetCurrentPathPlanner()
{
	return m_PathPlanner;
}

NavigationManager *NavigationManager::GetInstance()
{
	if(!m_Instance)
		m_Instance = new NavigationManager;
	return m_Instance;
}

void NavigationManager::DeleteInstance()
{
	OB_DELETE(m_Instance);
}

