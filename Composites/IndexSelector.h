// Copyright (c) 2015 Volodymyr Syvochka
#pragma once

// IndexSelector
// Executes the behavior with the selected index

#include "BehaviorComponent.h"
#include "CompositesCommon.h"

namespace BehaviorTree
{
	class IndexSelector : public BehaviorComponent
	{
	public:
		explicit IndexSelector(std::function<int()> index);
		IndexSelector(std::vector<unique_ptr<BehaviorComponent>> behaviors, std::function<int()> index);
		IndexSelector(IndexSelector&& indexSelector);
		~IndexSelector();
		virtual BehaviorReturnCode behave();
		virtual void clearState();
		void addBehavior(unique_ptr<BehaviorComponent> behavior);
	private:
		std::vector<unique_ptr<BehaviorComponent>> behaviors;
		std::function<int()> index;
	};
}
