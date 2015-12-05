#ifndef BehaviorInstantAction_h__
#define BehaviorInstantAction_h__

// Action always returns success
// For instant simple actions

#include "BehaviorComponent.h"

namespace BehaviorTree
{
	class BehaviorInstantAction : public BehaviorComponent
    {
	public:
		BehaviorInstantAction();
		explicit BehaviorInstantAction(std::function<void()> action);
        virtual BehaviorReturnCode behave();
		virtual void clearState();
	private:
		std::function<void()> action;
	};
}
#endif // BehaviorInstantAction_h__
