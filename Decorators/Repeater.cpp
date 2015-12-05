#include "Repeater.h"

namespace BehaviorTree
{
	Repeater::Repeater(unique_ptr<BehaviorComponent> behavior)
		: behavior(std::move(behavior))
	{

	}

	BehaviorReturnCode Repeater::behave()
	{
		returnCode = behavior->behave();
		returnCode = BehaviorReturnCode::Running;
		return BehaviorReturnCode::Running;
	}

	void Repeater::clearState()
	{
		behavior->clearState();
	}

}