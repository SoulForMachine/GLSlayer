
#include "Common/SampleFramework.h"
#include "TriangleSample.h"


int main()
{
	SampleFramework framework(L"Triangle", 800, 600);
	framework.Run(new TriangleSample);
}
