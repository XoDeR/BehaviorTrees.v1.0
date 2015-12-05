#include "PartialSequence.h"

namespace BehaviorTree
{
	PartialSequence::PartialSequence(std::vector<unique_ptr<BehaviorComponent>> behaviors)
		: behaviors(std::move(behaviors))
		, seqLength(behaviors.size())
	{
	}

	PartialSequence::PartialSequence()
		: seqLength(0)
	{

	}

	PartialSequence::~PartialSequence()
	{

	}

	BehaviorReturnCode PartialSequence::behave()
	{
		//while you can go through them, do so
		while (sequence < seqLength)
		{
			switch (behaviors[sequence]->behave())
			{
			case BehaviorReturnCode::Failure:
				sequence = 0;
				returnCode = BehaviorReturnCode::Failure;
				return returnCode;
			case BehaviorReturnCode::Success:
				sequence++;
				returnCode = BehaviorReturnCode::Running;
				return returnCode;
			case BehaviorReturnCode::Running:
				returnCode = BehaviorReturnCode::Running;
				return returnCode;
			}
		}

		sequence = 0;
		returnCode = BehaviorReturnCode::Success;
		return returnCode;
	}

	void PartialSequence::clearState()
	{
		for (auto it = behaviors.cbegin(); it != behaviors.cend(); ++it)
		{
			it->get()->clearState();
		}
	}

	void PartialSequence::addBehavior(unique_ptr<BehaviorComponent> behavior)
	{
		behaviors.push_back(std::move(behavior));
		seqLength = behaviors.size();
	}

}