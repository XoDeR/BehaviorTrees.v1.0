#ifndef StatefulSequence_h__
#define StatefulSequence_h__

// attempts to run the behaviors all in one cycle (stateful on running)
// Success when ALL are successful
// Failure if ANY behavior fails
// Running if ANY behavior running, in next iteration running behavior is entered

#include "BehaviorComponent.h"
#include "CompositesCommon.h"

namespace BehaviorTree
{
	class StatefulSequence : public BehaviorComponent
	{
	public:
		StatefulSequence();
		StatefulSequence(StatefulSequence&& statefulSequence);
		~StatefulSequence();
		StatefulSequence(std::vector<unique_ptr<BehaviorComponent>> behaviors);
		virtual BehaviorReturnCode behave();
		virtual void clearState();
		void addBehavior(unique_ptr<BehaviorComponent> behavior);
	private:
		std::vector<unique_ptr<BehaviorComponent> > behaviors;
		int lastBehavior;
	};
}

#endif // StatefulSequence_h__
