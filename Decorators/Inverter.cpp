#include "Inverter.h"

namespace BehaviorTree
{
	Inverter::Inverter(unique_ptr<BehaviorComponent> behavior)
		: behavior(std::move(behavior))
	{

	}

	BehaviorReturnCode Inverter::behave()
	{
		switch (behavior->behave())
		{
		case BehaviorReturnCode::Failure:
			returnCode = BehaviorReturnCode::Success;
			return returnCode;
		case BehaviorReturnCode::Success:
			returnCode = BehaviorReturnCode::Failure;
			return returnCode;
		case BehaviorReturnCode::Running:
			returnCode = BehaviorReturnCode::Running;
			return returnCode;
		}
		returnCode = BehaviorReturnCode::Success;
		return returnCode;
	}

	void Inverter::clearState()
	{
		behavior->clearState();
	}
}