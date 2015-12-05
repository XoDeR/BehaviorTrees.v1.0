// Copyright (c) 2015 Volodymyr Syvochka
#pragma once

// Inverts the behavior
// Success on Failure
// Failure on Success 
// Running on Running

#include "BehaviorComponent.h"
#include "DecoratorsCommon.h"

namespace BehaviorTree
{
    class Inverter : public BehaviorComponent
    {
	public:
		Inverter(unique_ptr<BehaviorComponent> behavior);
        virtual BehaviorReturnCode behave();
		virtual void clearState();
	private:
		unique_ptr<BehaviorComponent> behavior;
	};
}
