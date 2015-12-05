#include "PartialSelector.h"

namespace BehaviorTree
{
	PartialSelector::PartialSelector(std::vector<unique_ptr<BehaviorComponent>> behaviors) 
		: behaviors(std::move(behaviors))
		, selLength(behaviors.size())
	{

	}

	PartialSelector::PartialSelector()
		: selLength(0)
	{

	}


	PartialSelector::~PartialSelector()
	{

	}


	BehaviorReturnCode PartialSelector::behave()
	{
		while (selections < selLength)
		{
			switch (behaviors[selections]->behave())
			{
			case BehaviorReturnCode::Failure:
				selections++;
				returnCode = BehaviorReturnCode::Running;
				return returnCode;
			case BehaviorReturnCode::Success:
				selections = 0;
				returnCode = BehaviorReturnCode::Success;
				return returnCode;
			case BehaviorReturnCode::Running:
				returnCode = BehaviorReturnCode::Running;
				return returnCode;
			default:
				selections++;
				returnCode = BehaviorReturnCode::Failure;
				return returnCode;
			}
		}

		selections = 0;
		returnCode = BehaviorReturnCode::Failure;
		return returnCode;
	}

	void PartialSelector::clearState()
	{
		for (auto it = behaviors.cbegin(); it != behaviors.cend(); ++it)
		{
			it->get()->clearState();
		}
	}

	void PartialSelector::addBehavior(unique_ptr<BehaviorComponent> behavior)
	{
		behaviors.push_back(std::move(behavior));
		selLength = behaviors.size();
	}

}