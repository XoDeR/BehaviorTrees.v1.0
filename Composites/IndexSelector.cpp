// Copyright (c) 2015 Volodymyr Syvochka
#include "IndexSelector.h"

namespace BehaviorTree
{
	IndexSelector::IndexSelector(std::function<int()> index)
		: index(index)
	{
	}

	IndexSelector::IndexSelector(std::vector<unique_ptr<BehaviorComponent>> behaviors, std::function<int()> index) 
		: behaviors(std::move(behaviors))
		, index(index)
	{

	}

	IndexSelector::IndexSelector(IndexSelector&& indexSelector)
		: behaviors(std::move(indexSelector.behaviors))
		, index(indexSelector.index)
	{

	}

	IndexSelector::~IndexSelector()
	{

	}

	BehaviorReturnCode IndexSelector::behave()
	{
		switch (behaviors[index()]->behave())
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

	void IndexSelector::clearState()
	{
		for (auto it = behaviors.cbegin(); it != behaviors.cend(); ++it)
		{
			it->get()->clearState();
		}
	}

	void IndexSelector::addBehavior(unique_ptr<BehaviorComponent> behavior)
	{
		behaviors.push_back(std::move(behavior));
	}
}