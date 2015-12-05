// Copyright (c) 2015 Volodymyr Syvochka
#include "Behavior.h"
#include "BehaviorComponent.h"
#include "IndexSelector.h"

namespace BehaviorTree
{
	Behavior::Behavior(unique_ptr<IndexSelector> root)
		: root(std::move(root))
	{

	}

	////Behavior::Behavior(const Behavior& rhs)
	////	: root(std::move(rhs.root))
	////	, returnCode(rhs.returnCode)
	////{

	////}

	Behavior::Behavior(Behavior&& rhs)
		: root(std::move(rhs.root))
		, returnCode(rhs.returnCode)
	{

	}

	Behavior::~Behavior()
	{

	}

	BehaviorReturnCode Behavior::getReturnCode()
	{
		return returnCode;
	}

	void Behavior::setReturnCode(BehaviorReturnCode returnCode)
	{
		this->returnCode = returnCode;
	}

	BehaviorReturnCode Behavior::behave()
	{
		switch (root->behave())
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
			returnCode = BehaviorReturnCode::Running;
			return returnCode;
		}
	}

	void Behavior::clearState()
	{
		root->clearState();
	}

}