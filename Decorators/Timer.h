// Copyright (c) 2015 Volodymyr Syvochka
#pragma once

// Timer
// Executes the behavior after a delay in milliseconds

#include "BehaviorComponent.h"
#include "DecoratorsCommon.h"

namespace BehaviorTree
{
	class Timer : public BehaviorComponent
	{
	public:
		Timer(unique_ptr<BehaviorComponent> behavior, std::function<int()>, int timeToWait);
		virtual BehaviorReturnCode behave();
		virtual void clearState();
	private:
		unique_ptr<BehaviorComponent> behavior;
		std::function<int()> elapsedTimeFunction;
		int timeElapsed;
		int timeToWait;
	};
}
