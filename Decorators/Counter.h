#ifndef Counter_h__
#define Counter_h__

// Executes the behavior based on a counter
// each time Counter is called the counter increments by 1
// Counter executes the behavior when it reaches the supplied maxCount

#include "BehaviorComponent.h"
#include "DecoratorsCommon.h"

namespace BehaviorTree
{
	class Counter : public BehaviorComponent
	{
	public:
		Counter(unique_ptr<BehaviorComponent> behavior, int maxCount);
		virtual BehaviorReturnCode behave();
		virtual void clearState();
	private:
		int maxCount;
		int counter;
		unique_ptr<BehaviorComponent> behavior;
	};
}
#endif // Counter_h__
