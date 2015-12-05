#include "RandomSelector.h"
#include "Random.h"

namespace BehaviorTree
{
	RandomSelector::RandomSelector(std::vector<unique_ptr<BehaviorComponent>> behaviors) 
		: behaviors(std::move(behaviors))
	{

	}

	RandomSelector::RandomSelector()
	{

	}

	RandomSelector::~RandomSelector()
	{

	}

	BehaviorReturnCode RandomSelector::behave()
	{
		int randomMax = static_cast<int>(behaviors.size() - 1);

		switch (behaviors[BehaviorTree::random(0, randomMax)]->behave())
		{
		case BehaviorReturnCode::Failure:
			returnCode = BehaviorReturnCode::Failure;
			return returnCode;
		case BehaviorReturnCode::Success:
			returnCode = BehaviorReturnCode::Success;
			return returnCode;
		case BehaviorReturnCode::Running:
			returnCode = BehaviorReturnCode::Running;
			return returnCode;
		default:
			returnCode = BehaviorReturnCode::Failure;
			return returnCode;
		}
	}

	void RandomSelector::clearState()
	{
		for (auto it = behaviors.cbegin(); it != behaviors.cend(); ++it)
		{
			it->get()->clearState();
		}
	}

	void RandomSelector::addBehavior(unique_ptr<BehaviorComponent> behavior)
	{
		behaviors.push_back(std::move(behavior));
	}
}