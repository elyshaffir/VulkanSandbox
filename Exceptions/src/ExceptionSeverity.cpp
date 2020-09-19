#include "../include/ExceptionSeverity.h"

using namespace sandbox::exceptions;

std::string SeverityToString(ExceptionSeverity severity)
{
	std::string severityString = "[";
	switch (severity)
	{
		case ExceptionSeverity::Warning:
			severityString += "Warning";
			break;
		case ExceptionSeverity::Fatal:
			severityString += "Fatal";
			break;
		default:
			severityString += "Unknown";
	}
	return severityString + "] ";
}