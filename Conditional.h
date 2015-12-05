// Copyright (c) 2015 Volodymyr Syvochka
#pragma once

#include "BehaviorComponent.h"

namespace BehaviorTree
{
    class Conditional : public BehaviorComponent
    {
	public:
		explicit Conditional(std::function<bool()> test);
        virtual BehaviorReturnCode behave();
		virtual void clearState();
	private:
		std::function<bool()> test;
	};
}
