
#ifndef _GL_SLAYER_MESSAGES_H_
#define _GL_SLAYER_MESSAGES_H_

namespace gls::internals
{

enum ErrorMessageId
{
	MESSAGE_ERROR_UNSUPPORTED_VERSION,
	MESSAGE_ERROR_CREATE_CONTEXT,
	MESSAGE_ERROR_EXTENSION_MISSING_ENTRIES,
	MESSAGE_ERROR_UNSUPPORTED_EXTENSION,

#if defined (_WIN32)
	MESSAGE_ERROR_CREATE_TEMPORARY_CONTEXT,
#endif

	MESSAGE_COUNT
};


const char* GetMessageString(ErrorMessageId message_id);

} // namespace gls::internals

#endif // _GL_SLAYER_MESSAGES_H_
