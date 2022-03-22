#pragma once
#include "MCommand.hpp"

using namespace Musoeun;


class JumpCommand : public MCommand
{
public:
	void Execute()
	{
		std::cout << "¾Ñ½Î Á¡ÇÁ!!";
	}
};

class RunCommand : public MCommand
{
public:
	void Execute()
	{
		std::cout << "¾Ñ½Î ´Þ¸®±â!!";
	}
};

class LeftCommand : public MCommand
{
public:
	void Execute()
	{
		std::cout << "¸¾¸¶¹Ì¾Æ ¿ÞÂÊ!!";
	}
};

class RightCommand : public MCommand
{
public:
	void Execute()
	{
		std::cout << "¸¾¸¶¹Ì¾Æ ¿À¸¥ÂÊ!!";
	}
};

class DownCommand : public MCommand
{
public:
	void Execute()
	{
		std::cout << "ÀÚÁ¸½É µûÀ© ¾ø´Ù ¾¥±¸¸®±â!!";
	}
};