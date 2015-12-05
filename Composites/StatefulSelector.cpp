#include "StatefulSelector.h"

namespace BehaviorTree
{
	StatefulSelector::StatefulSelector(std::vector<unique_ptr<BehaviorComponent>> behaviors)
		: behaviors(std::move(behaviors))
		, lastBehavior(0)
	{

	}

	StatefulSelector::StatefulSelector()
		: lastBehavior(0)
	{

	}

	StatefulSelector::~StatefulSelector()
	{

	}


	BehaviorReturnCode StatefulSelector::behave()
	{
		for (; lastBehavior < behaviors.size(); lastBehavior++)
		{
			switch (behaviors[lastBehavior]->behave())
			{
			case BehaviorReturnCode::Failure:
				continue;
			case BehaviorReturnCode::Success:
				lastBehavior = 0;
				returnCode = BehaviorReturnCode::Success;
				return returnCode;
			case BehaviorReturnCode::Running:
				returnCode = BehaviorReturnCode::Running;
				return returnCode;
			default:
				continue;
			}
		}

		lastBehavior = 0;
		returnCode = BehaviorReturnCode::Failure;
		return returnCode;
	}

	void StatefulSelector::clearState()
	{
		lastBehavior = 0;
		for (auto it = behaviors.cbegin(); it != behaviors.cend(); ++it)
		{
			it->get()->clearState();
		}
	}

	void StatefulSelector::addBehavior(unique_ptr<BehaviorComponent> behavior)
	{
		behaviors.push_back(std::move(behavior));
	}

}