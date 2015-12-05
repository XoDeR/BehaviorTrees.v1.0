#ifndef Sequence_h__
#define Sequence_h__

// attempts to run the behaviors all in one cycle
// Success when ALL are successful
// Failure if ANY behavior failed
// Running if ANY is running

#include "BehaviorComponent.h"
#include "CompositesCommon.h"

namespace BehaviorTree
{
	class Sequence : public BehaviorComponent
    {
	public:
		Sequence();
		~Sequence();
		Sequence(std::vector<unique_ptr<BehaviorComponent>> behaviors);
        virtual BehaviorReturnCode behave();
		virtual void clearState();
		void addBehavior(unique_ptr<BehaviorComponent> behavior);
	private:
		std::vector<unique_ptr<BehaviorComponent>> behaviors;
	};
}
#endif // Sequence_h__
