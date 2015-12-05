#include "BehaviorComponent.h"

namespace BehaviorTree
{

	BehaviorComponent::BehaviorComponent()
	{

	}

	BehaviorComponent::BehaviorComponent(BehaviorComponent&& behaviorComponent)
		: returnCode(behaviorComponent.returnCode)
	{

	}

	BehaviorComponent::~BehaviorComponent()
	{

	}

}