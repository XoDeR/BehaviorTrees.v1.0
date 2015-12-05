#ifndef PartialSequence_h__
#define PartialSequence_h__

// Performs the given behavior components sequentially (one evaluation per Behave call)
// Performs an AND-Like behavior and will perform each successive component
// Success if ALL behaviors returned Success
// Running if ANY behavior returned Success or Running
// Failure if ANY behavior returned Failure

#include "BehaviorComponent.h"
#include "CompositesCommon.h"

namespace BehaviorTree
{
	class PartialSequence : public BehaviorComponent
	{
	public:
		PartialSequence();
		~PartialSequence();
		PartialSequence(std::vector<unique_ptr<BehaviorComponent>> behaviors);
		virtual BehaviorReturnCode behave();
		virtual void clearState();
		void addBehavior(unique_ptr<BehaviorComponent> behavior);
	protected:
		std::vector<unique_ptr<BehaviorComponent>> behaviors;
	private:
		int sequence = 0;
		int seqLength = 0;
	};
}
#endif // PartialSequence_h__
