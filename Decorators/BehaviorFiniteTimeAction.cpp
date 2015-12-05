#include "BehaviorFiniteTimeAction.h"

namespace BehaviorTree
{
	BehaviorFiniteTimeAction::BehaviorFiniteTimeAction(unique_ptr<BehaviorComponent> behavior, std::function<int()> elapsedTimeFunction, int timeToWait)
		: behavior(std::move(behavior))
		, elapsedTimeFunction(elapsedTimeFunction)
		, timeToWait(timeToWait)
		, timeElapsed(0)
		, executed(false)
		, innerBehaviorReturnCode(BehaviorReturnCode::Success)
	{

	}

	BehaviorReturnCode BehaviorFiniteTimeAction::behave()
	{
		if (executed == false)
		{
			innerBehaviorReturnCode = behavior->behave();
			executed = true;
		}

		timeElapsed += elapsedTimeFunction();

		if (timeElapsed >= timeToWait)
		{
			timeElapsed = 0;
			returnCode = innerBehaviorReturnCode;
			return returnCode;
		}
		else
		{
			returnCode = BehaviorReturnCode::Running;
			return BehaviorReturnCode::Running;
		}
	}

	void BehaviorFiniteTimeAction::clearState()
	{
		executed = false;
		timeElapsed = 0;
		behavior->clearState();
	}
}