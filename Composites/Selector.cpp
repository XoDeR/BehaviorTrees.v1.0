#include "Selector.h"

namespace BehaviorTree
{
	Selector::Selector(std::vector<unique_ptr<BehaviorComponent>> behaviors) 
		: behaviors(std::move(behaviors))
	{

	}

	Selector::Selector()
	{

	}


	Selector::~Selector()
	{

	}


	BehaviorReturnCode Selector::behave()
	{
		for (int i = 0; i < behaviors.size(); i++)
		{
			switch (behaviors[i]->behave())
			{
			case BehaviorReturnCode::Failure:
				continue;
			case BehaviorReturnCode::Success:
				returnCode = BehaviorReturnCode::Success;
				return returnCode;
			case BehaviorReturnCode::Running:
				returnCode = BehaviorReturnCode::Running;
				return returnCode;
			default:
				continue;
			}
		}

		returnCode = BehaviorReturnCode::Failure;
		return returnCode;
	}

	void Selector::clearState()
	{
		for (auto it = behaviors.cbegin(); it != behaviors.cend(); ++it)
		{
			it->get()->clearState();
		}
	}

	void Selector::addBehavior(unique_ptr<BehaviorComponent> behavior)
	{
		behaviors.push_back(std::move(behavior));
	}

}