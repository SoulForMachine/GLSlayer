
#ifndef _GL_FRAMEBUFFER_H_
#define _GL_FRAMEBUFFER_H_

#include "GLSlayer/Framebuffer.h"
#include "GLResource.h"



class GLTexture;


class GLRenderbuffer : public gls::IRenderbuffer, public GLResource
{
public:
	IMPLEMENT_IRESOURCE

	static const int typeID = TYPE_ID_RENDERBUFFER;

	GLRenderbuffer() {}

	bool Create(GLState* gl_state);
	void Destroy();

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_RENDERBUFFER) ? this : GLResource::DynamicCast(type_id); }
	void Storage(size_t samples, gls::PixelFormat internal_format, size_t width, size_t height);

private:
	GLRenderbuffer(const GLRenderbuffer&);
	GLRenderbuffer& operator = (const GLRenderbuffer&);

	GLState* _glState;
};


class GLFramebuffer : public gls::IFramebuffer, public GLResource
{
public:
	IMPLEMENT_IRESOURCE

	static const int typeID = TYPE_ID_FRAMEBUFFER;

	GLFramebuffer() {}

	bool Create(GLState* gl_state);
	bool CreateWithoutAttachments(GLState* gl_state, const gls::FramebufferParams& params);
	void Destroy();

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_FRAMEBUFFER) ? this : GLResource::DynamicCast(type_id); }
	void AttachTexture(gls::AttachmentBuffer attachment, gls::ITexture* texture, int level);
	void AttachTextureLayer(gls::AttachmentBuffer attachment, gls::ITexture* texture, int level, int layer);
	void AttachTextureFace(gls::AttachmentBuffer attachment, gls::ITexture* texture, int level, gls::CubeFace face);
	void AttachRenderbuffer(gls::AttachmentBuffer attachment, gls::IRenderbuffer* renderbuffer);
	gls::FramebufferStatus CheckStatus();
	void InvalidateFramebuffer(int num_attachments, const gls::AttachmentBuffer* attachments);
	void InvalidateSubFramebuffer(int num_attachments, const gls::AttachmentBuffer* attachments, int x, int y, int width, int height);

private:
	GLFramebuffer(const GLFramebuffer&);
	GLFramebuffer& operator = (const GLFramebuffer&);

	GLState* _glState;
};


#endif // _GL_FRAMEBUFFER_H_
