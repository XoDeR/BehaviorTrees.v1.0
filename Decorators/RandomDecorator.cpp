#include "RandomDecorator.h"
#include "Random.h"

namespace BehaviorTree
{
	RandomDecorator::RandomDecorator(unique_ptr<BehaviorComponent> behavior, float probability)
		: behavior(std::move(behavior))
		, probability(probability)
	{

	}

	BehaviorReturnCode RandomDecorator::behave()
	{
		if (rand_0_1() <= probability)
		{
			returnCode = behavior->behave();
			return returnCode;
		}
		else
		{
			returnCode = BehaviorReturnCode::Running;
			return BehaviorReturnCode::Running;
		}
	}

	void RandomDecorator::clearState()
	{
		behavior->clearState();
	}

}