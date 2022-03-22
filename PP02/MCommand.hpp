#pragma once

class MCommand
{
public :
	MCommand() {}
	virtual ~MCommand() {}

	virtual void execute() {}
};