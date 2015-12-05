#ifndef BehaviorComponent_h__
#define BehaviorComponent_h__

#include "BehaviorReturnCode.h"
#include <functional>

namespace BehaviorTree
{
    class  BehaviorComponent
    {
	public:
		BehaviorComponent();
		virtual ~BehaviorComponent();
		BehaviorComponent(BehaviorComponent&& behaviorComponent);
		virtual BehaviorReturnCode behave() = 0;
		virtual void clearState() = 0;
	protected:
		BehaviorReturnCode returnCode;
	};
}
#endif // BehaviorComponent_h__
