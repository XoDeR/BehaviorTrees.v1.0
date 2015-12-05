#include "RepeatUntilFail.h"

namespace BehaviorTree
{
	RepeatUntilFail::RepeatUntilFail(unique_ptr<BehaviorComponent> behavior)
		: behavior(std::move(behavior))
	{

	}

	BehaviorReturnCode RepeatUntilFail::behave()
	{
		returnCode = behavior->behave();
		if (returnCode == BehaviorReturnCode::Failure)
		{
			return BehaviorReturnCode::Failure;
		}
		else
		{
			returnCode = BehaviorReturnCode::Running;
			return BehaviorReturnCode::Running;
		}
	}

	void RepeatUntilFail::clearState()
	{
		behavior->clearState();
	}
}