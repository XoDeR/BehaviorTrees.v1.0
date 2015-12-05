#ifndef Selector_h__
#define Selector_h__

// Selects among the given behavior components
// Performs an OR-Like behavior and will "fail-over" to each successive component until Success is reached or Failure is certain
// Success if ANY behavior returned Success
// Running if ANY behavior returned Running
// Failure if ALL behaviors returned Failure

#include "BehaviorComponent.h"
#include "CompositesCommon.h"

namespace BehaviorTree
{
	class Selector : public BehaviorComponent
    {
	public:
		Selector();
		~Selector();
		Selector(std::vector<unique_ptr<BehaviorComponent>> behaviors);
        virtual BehaviorReturnCode behave();
		virtual void clearState();
		void addBehavior(unique_ptr<BehaviorComponent> behavior);
	protected:
		std::vector<unique_ptr<BehaviorComponent>> behaviors;
	};
}
#endif // Selector_h__
