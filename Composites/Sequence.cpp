#include "Sequence.h"

namespace BehaviorTree
{
	Sequence::Sequence(std::vector<unique_ptr<BehaviorComponent>> behaviors) 
		: behaviors(std::move(behaviors))
	{

	}

	Sequence::Sequence()
	{

	}


	Sequence::~Sequence()
	{

	}

	BehaviorReturnCode Sequence::behave()
	{
		//add watch for any running behaviors
		bool anyRunning = false;

		for (int i = 0; i < behaviors.size(); i++)
		{
			switch (behaviors[i]->behave())
			{
			case BehaviorReturnCode::Failure:
				returnCode = BehaviorReturnCode::Failure;
				return returnCode;
			case BehaviorReturnCode::Success:
				continue;
			case BehaviorReturnCode::Running:
				anyRunning = true;
				continue;
			default:
				returnCode = BehaviorReturnCode::Success;
				return returnCode;
			}
		}

		// if ANY running return running, otherwise return success (NONE failed)
		returnCode = anyRunning == false ? BehaviorReturnCode::Success : BehaviorReturnCode::Running;
		return returnCode;
	}

	void Sequence::clearState()
	{
		for (auto it = behaviors.cbegin(); it != behaviors.cend(); ++it)
		{
			it->get()->clearState();
		}
	}

	void Sequence::addBehavior(unique_ptr<BehaviorComponent> behavior)
	{
		behaviors.push_back(std::move(behavior));
	}

}