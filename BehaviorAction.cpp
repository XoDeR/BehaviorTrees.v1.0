#include "BehaviorAction.h"

namespace BehaviorTree
{
	BehaviorAction::BehaviorAction()
	{

	}

	BehaviorAction::BehaviorAction(std::function<BehaviorReturnCode()> action) : action(action)
	{

	}

	BehaviorReturnCode BehaviorAction::behave()
	{
		switch (action())
		{
		case BehaviorReturnCode::Success:
			returnCode = BehaviorReturnCode::Success;
			return returnCode;
		case BehaviorReturnCode::Failure:
			returnCode = BehaviorReturnCode::Failure;
			return returnCode;
		case BehaviorReturnCode::Running:
			returnCode = BehaviorReturnCode::Running;
			return returnCode;
		default:
			returnCode = BehaviorReturnCode::Failure;
			return returnCode;
		}
	}

	void BehaviorAction::clearState()
	{

	}
}