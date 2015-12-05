#ifndef BehaviorAction_h__
#define BehaviorAction_h__

#include "BehaviorComponent.h"

namespace BehaviorTree
{
    class BehaviorAction : public BehaviorComponent
    {
	public:
		BehaviorAction();
		explicit BehaviorAction(std::function<BehaviorReturnCode()> action);
        virtual BehaviorReturnCode behave();
		virtual void clearState();
	private:
		std::function<BehaviorReturnCode()> action;
	};
}
#endif // BehaviorAction_h__
