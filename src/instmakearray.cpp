#include "instmakearray.h"
#include <vector>
#include <memory>
#include "value.h"
#include "virtualmachine.h"
#include "vmstack.h"
#include "sqfnamespace.h"

void sqf::inst::makearray::execute(virtualmachine* vm) const
{
	auto vec = std::vector<value>(msize);
	for (size_t i = msize - 1; i != (size_t)~0; i--)
	{
		bool flag;
		vec[i] = vm->active_vmstack()->popval(flag);
		if (!flag)
		{
			vm->err() << "Missing elements on value stack. Expected " << msize << ", got " << msize - i << std::endl;
			break;
		}
	}
	vm->active_vmstack()->pushval(value(vec));
}