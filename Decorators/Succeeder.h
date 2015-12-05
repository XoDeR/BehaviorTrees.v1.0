// Copyright (c) 2015 Volodymyr Syvochka
#pragma once
// returns a success even when the decorated component failed

#include "BehaviorComponent.h"
#include "DecoratorsCommon.h"

namespace BehaviorTree
{
    class Succeeder : public BehaviorComponent
    {
	public:
		Succeeder(unique_ptr<BehaviorComponent> behavior);
        virtual BehaviorReturnCode behave();
		virtual void clearState();
	private:
		unique_ptr<BehaviorComponent> behavior;
	};
}
