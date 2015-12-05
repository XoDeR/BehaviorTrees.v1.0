// Copyright (c) 2015 Volodymyr Syvochka
#pragma once

// Repeats the behavior

#include "BehaviorComponent.h"
#include "DecoratorsCommon.h"

namespace BehaviorTree
{
    class Repeater : public BehaviorComponent
    {
	public:
		Repeater(unique_ptr<BehaviorComponent> behavior);
        virtual BehaviorReturnCode behave();
		virtual void clearState();
	private:
		unique_ptr<BehaviorComponent> behavior;
	};
}
