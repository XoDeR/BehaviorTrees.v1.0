#include "Succeeder.h"

namespace BehaviorTree
{
	Succeeder::Succeeder(unique_ptr<BehaviorComponent> behavior)
		: behavior(std::move(behavior))
	{

	}

	BehaviorReturnCode Succeeder::behave()
	{
		returnCode = behavior->behave();
		if (returnCode == BehaviorReturnCode::Failure)
		{
			returnCode = BehaviorReturnCode::Success;
		}
		return returnCode;
	}

	void Succeeder::clearState()
	{
		behavior->clearState();
	}

}