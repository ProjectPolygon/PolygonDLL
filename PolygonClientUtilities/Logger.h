#pragma once

#include "pch.h"

enum class LogType { Output, Http };

class Logger
{
public:
	static HANDLE handle;
	static void Initialize(const std::string jobId);
};