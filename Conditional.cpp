// Copyright (c) 2015 Volodymyr Syvochka
#include "Conditional.h"

namespace BehaviorTree
{
	Conditional::Conditional(std::function<bool()> test) 
		: test(test)
	{

	}

	BehaviorReturnCode Conditional::behave()
	{
		switch (test())
		{
		case true:
			returnCode = BehaviorReturnCode::Success;
			return returnCode;
		case false:
			returnCode = BehaviorReturnCode::Failure;
			return returnCode;
		default:
			returnCode = BehaviorReturnCode::Failure;
			return returnCode;
		}
	}

	void Conditional::clearState()
	{

	}
}