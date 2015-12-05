#include "Counter.h"

namespace BehaviorTree
{
	Counter::Counter(unique_ptr<BehaviorComponent> behavior, int maxCount)
		: behavior(std::move(behavior))
		, maxCount(maxCount)
		, counter(0)
	{

	}

	BehaviorReturnCode Counter::behave()
	{
		if (counter < maxCount)
		{
			counter++;
			returnCode = BehaviorReturnCode::Running;
			return BehaviorReturnCode::Running;
		}
		else
		{
			counter = 0;
			returnCode = behavior->behave();
			return returnCode;
		}
	}

	void Counter::clearState()
	{
		counter = 0;
		behavior->clearState();
	}
}