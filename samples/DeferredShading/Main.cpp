
#include "Common/SampleFramework.h"
#include "DeferredSample.h"


int main()
{
	SampleFramework framework(L"Deferred shading", 800, 600);
	framework.Run(new DeferredSample);
}
