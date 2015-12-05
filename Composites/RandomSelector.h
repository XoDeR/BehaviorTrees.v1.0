#ifndef RandomSelector_h__
#define RandomSelector_h__

// Randomly selects and performs one of the passed behaviors
// Success if selected behavior returns Success
// Failure if selected behavior returns Failure
// Running if selected behavior returns Running

#include "BehaviorComponent.h"
#include "CompositesCommon.h"

namespace BehaviorTree
{
	class RandomSelector : public BehaviorComponent
    {
	public:
		RandomSelector();
		~RandomSelector();
		RandomSelector(std::vector<unique_ptr<BehaviorComponent>> behaviors);
        virtual BehaviorReturnCode behave();
		virtual void clearState();
		void addBehavior(unique_ptr<BehaviorComponent> behavior);
	private:
		std::vector<unique_ptr<BehaviorComponent>> behaviors;
	};
}
#endif // RandomSelector_h__
