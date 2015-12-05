// Copyright (c) 2015 Volodymyr Syvochka
#pragma once
// Randomly executes the behavior

#include "BehaviorComponent.h"
#include "DecoratorsCommon.h"

namespace BehaviorTree
{
    class RandomDecorator : public BehaviorComponent
    {
	public:
		RandomDecorator(unique_ptr<BehaviorComponent> behavior, float probability);
        virtual BehaviorReturnCode behave();
		virtual void clearState();
	private:
		float probability;
		unique_ptr<BehaviorComponent> behavior;
	};
}
