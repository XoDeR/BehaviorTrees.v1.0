#ifndef StatefulSelector_h__
#define StatefulSelector_h__

// Selects among the given behavior components (stateful on running) 
// Performs an OR-Like behavior and will "fail-over" to each successive component until Success is reached or Failure is certain
// Success if ANY behavior returned Success
// Running if ANY behavior returned Running
// Failure if ALL behaviors returned Failure

#include "BehaviorComponent.h"
#include "CompositesCommon.h"

namespace BehaviorTree
{
	class StatefulSelector : public BehaviorComponent
	{
	public:
		StatefulSelector();
		~StatefulSelector();
		StatefulSelector(std::vector<unique_ptr<BehaviorComponent>> behaviors);
		virtual BehaviorReturnCode behave();
		virtual void clearState();
		void addBehavior(unique_ptr<BehaviorComponent> behavior);
	private:
		std::vector<unique_ptr<BehaviorComponent>> behaviors;
		int lastBehavior;
	};
}
#endif // StatefulSelector_h__
