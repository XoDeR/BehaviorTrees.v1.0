// Copyright (c) 2015 Volodymyr Syvochka
#pragma once
#include "Common.h"
#include "BehaviorReturnCode.h"

namespace BehaviorTree
{
	class BehaviorComponent;
	class IndexSelector;

    class Behavior
    {
	public:
		explicit Behavior(unique_ptr<IndexSelector> root);
		////Behavior(const Behavior& rhs);
		Behavior(Behavior&& rhs);
		virtual ~Behavior();
        BehaviorReturnCode behave();
		void clearState();

		BehaviorReturnCode getReturnCode();
		void setReturnCode(BehaviorReturnCode returnCode);
	private:
		unique_ptr<IndexSelector> root;
		BehaviorReturnCode returnCode;
	};
}
