// Copyright (c) 2015 Volodymyr Syvochka
#pragma once

#include "BehaviorComponent.h"
#include "DecoratorsCommon.h"

namespace BehaviorTree
{
    class BehaviorFiniteTimeAction : public BehaviorComponent
    {
	public:
		BehaviorFiniteTimeAction(unique_ptr<BehaviorComponent> behavior, std::function<int()> elapsedTimeFunction, int timeToWait);
		virtual BehaviorReturnCode behave();
		virtual void clearState();
	private:
		unique_ptr<BehaviorComponent> behavior;
		std::function<int()> elapsedTimeFunction;
		int timeElapsed;
		int timeToWait;
		BehaviorReturnCode innerBehaviorReturnCode;
		bool executed;
	};
}
