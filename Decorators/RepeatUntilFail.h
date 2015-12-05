// Copyright (c) 2015 Volodymyr Syvochka
#pragma once
// executes the behavior every time again if behavior is not failed

#include "BehaviorComponent.h"
#include "DecoratorsCommon.h"

namespace BehaviorTree
{
    class RepeatUntilFail : public BehaviorComponent
    {
	public:
		RepeatUntilFail(unique_ptr<BehaviorComponent> behavior);
        virtual BehaviorReturnCode behave();
		virtual void clearState();
	private:
		unique_ptr<BehaviorComponent> behavior;
	};
}
