#include "BehaviorInstantAction.h"

namespace BehaviorTree
{
	BehaviorInstantAction::BehaviorInstantAction()
	{

	}

	BehaviorInstantAction::BehaviorInstantAction(std::function<void()> action) : action(action)
	{

	}

	BehaviorReturnCode BehaviorInstantAction::behave()
	{
		action();
		returnCode = BehaviorReturnCode::Success;
		return returnCode;
	}

	void BehaviorInstantAction::clearState()
	{

	}
}