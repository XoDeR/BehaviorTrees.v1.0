#include "StatefulSequence.h"

namespace BehaviorTree
{
	StatefulSequence::StatefulSequence(std::vector<unique_ptr<BehaviorComponent>> behaviors) 
		: behaviors(std::move(behaviors))
		, lastBehavior(0)
	{

	}

	StatefulSequence::StatefulSequence()
		: lastBehavior(0)
	{

	}

	StatefulSequence::StatefulSequence(StatefulSequence&& statefulSequence)
		: behaviors(std::move(statefulSequence.behaviors))
		, lastBehavior(statefulSequence.lastBehavior)
	{

	}

	StatefulSequence::~StatefulSequence()
	{

	}

	BehaviorReturnCode StatefulSequence::behave()
	{
		//start from last remembered position
		for (; lastBehavior < behaviors.size(); lastBehavior++)
		{
			switch (behaviors[lastBehavior]->behave())
			{
			case BehaviorReturnCode::Failure:
				lastBehavior = 0;
				returnCode = BehaviorReturnCode::Failure;
				return returnCode;
			case BehaviorReturnCode::Success:
				continue;
			case BehaviorReturnCode::Running:
				returnCode = BehaviorReturnCode::Running;
				return returnCode;
			default:
				lastBehavior = 0;
				returnCode = BehaviorReturnCode::Success;
				return returnCode;
			}
		}

		lastBehavior = 0;
		returnCode = BehaviorReturnCode::Success;
		return returnCode;
	}

	void StatefulSequence::clearState()
	{
		lastBehavior = 0;
		for (auto it = behaviors.cbegin(); it != behaviors.cend(); ++it)
		{
			it->get()->clearState();
		}
	}

	void StatefulSequence::addBehavior(unique_ptr<BehaviorComponent> behavior)
	{
		behaviors.push_back(std::move(behavior));
	}
}