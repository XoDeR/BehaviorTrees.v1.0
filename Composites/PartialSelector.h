#ifndef PartialSelector_h__
#define PartialSelector_h__

// PartialSelector
// Selects among the given behavior components (one evaluation per Behave call)
// Performs an OR-Like behavior and will "fail-over" to each successive component until Success is reached or Failure is certain
// Success if ANY behavior returned Success
// Running if ANY behavior returned Failure or Running
// Failure if ALL behaviors returned Failure

#include "BehaviorComponent.h"
#include "CompositesCommon.h"

namespace BehaviorTree
{
	class PartialSelector : public BehaviorComponent
    {
	public:
		PartialSelector();
		~PartialSelector();
		PartialSelector(std::vector<unique_ptr<BehaviorComponent>> behaviors);
        virtual BehaviorReturnCode behave();
		virtual void clearState();
		void addBehavior(unique_ptr<BehaviorComponent> behavior);
	protected:
		std::vector<unique_ptr<BehaviorComponent>> behaviors;
	private:
		int selections = 0;
		int selLength = 0;
	};
}
#endif // PartialSelector_h__
