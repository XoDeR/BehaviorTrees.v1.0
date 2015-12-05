#include "Timer.h"

namespace BehaviorTree
{
	Timer::Timer(unique_ptr<BehaviorComponent> behavior, std::function<int()>, int timeToWait)
		: behavior(std::move(behavior))
		, elapsedTimeFunction(elapsedTimeFunction)
		, timeToWait(timeToWait)
		, timeElapsed(0)
	{

	}

	BehaviorReturnCode Timer::behave()
	{
		timeElapsed += elapsedTimeFunction();

		if (timeElapsed >= timeToWait)
		{
			timeElapsed = 0;
			returnCode = behavior->behave();
			return returnCode;
		}
		else
		{
			returnCode = BehaviorReturnCode::Running;
			return BehaviorReturnCode::Running;
		}
	}

	void Timer::clearState()
	{
		timeElapsed = 0;
		behavior->clearState();
	}
}