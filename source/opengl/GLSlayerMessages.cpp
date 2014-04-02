
#include "GLSlayerMessages.h"

const char* messageTable[] =
{
	"Version number must be at least 330.",
	"Failed to create rendering context (version %u): %s.",
	"The driver does not have an entry for function %s.",
	"Extension %s is not supported.",

#if defined (_WIN32)
	"Failed to create temporary rendering context: %s.",
#endif
};

const char* GetMessageString(ErrorMessageId message_id)
{
	return (message_id < MESSAGE_COUNT) ? messageTable[message_id] : nullptr;
}
