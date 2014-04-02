
// GL_VERSION_1_2

bool glextLoad_GL_VERSION_1_2(GLContextInfo& info);

EXTPTR PFNGLTEXSUBIMAGE3DPROC ptr_glTexSubImage3D;
EXTPTR PFNGLCOPYTEXSUBIMAGE3DPROC ptr_glCopyTexSubImage3D;

// GL_VERSION_1_3

bool glextLoad_GL_VERSION_1_3(GLContextInfo& info);

EXTPTR PFNGLACTIVETEXTUREPROC ptr_glActiveTexture;
EXTPTR PFNGLSAMPLECOVERAGEPROC ptr_glSampleCoverage;
EXTPTR PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC ptr_glCompressedTexSubImage3D;
EXTPTR PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC ptr_glCompressedTexSubImage2D;
EXTPTR PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC ptr_glCompressedTexSubImage1D;
EXTPTR PFNGLGETCOMPRESSEDTEXIMAGEPROC ptr_glGetCompressedTexImage;

// GL_VERSION_1_4

bool glextLoad_GL_VERSION_1_4(GLContextInfo& info);

EXTPTR PFNGLBLENDFUNCSEPARATEPROC ptr_glBlendFuncSeparate;

// GL_ARB_imaging

bool glextLoad_GL_ARB_imaging(GLContextInfo& info);

EXTPTR PFNGLBLENDCOLORPROC ptr_glBlendColor;
EXTPTR PFNGLBLENDEQUATIONPROC ptr_glBlendEquation;

// GL_VERSION_1_5

bool glextLoad_GL_VERSION_1_5(GLContextInfo& info);

EXTPTR PFNGLGENQUERIESPROC ptr_glGenQueries;
EXTPTR PFNGLDELETEQUERIESPROC ptr_glDeleteQueries;
EXTPTR PFNGLBEGINQUERYPROC ptr_glBeginQuery;
EXTPTR PFNGLENDQUERYPROC ptr_glEndQuery;
EXTPTR PFNGLGETQUERYOBJECTIVPROC ptr_glGetQueryObjectiv;
EXTPTR PFNGLGETQUERYOBJECTUIVPROC ptr_glGetQueryObjectuiv;
EXTPTR PFNGLBINDBUFFERPROC ptr_glBindBuffer;
EXTPTR PFNGLDELETEBUFFERSPROC ptr_glDeleteBuffers;
EXTPTR PFNGLGENBUFFERSPROC ptr_glGenBuffers;
EXTPTR PFNGLBUFFERDATAPROC ptr_glBufferData;
EXTPTR PFNGLBUFFERSUBDATAPROC ptr_glBufferSubData;
EXTPTR PFNGLGETBUFFERSUBDATAPROC ptr_glGetBufferSubData;
EXTPTR PFNGLMAPBUFFERPROC ptr_glMapBuffer;
EXTPTR PFNGLUNMAPBUFFERPROC ptr_glUnmapBuffer;

// GL_VERSION_2_0

bool glextLoad_GL_VERSION_2_0(GLContextInfo& info);

EXTPTR PFNGLBLENDEQUATIONSEPARATEPROC ptr_glBlendEquationSeparate;
EXTPTR PFNGLDRAWBUFFERSPROC ptr_glDrawBuffers;
EXTPTR PFNGLSTENCILOPSEPARATEPROC ptr_glStencilOpSeparate;
EXTPTR PFNGLSTENCILFUNCSEPARATEPROC ptr_glStencilFuncSeparate;
EXTPTR PFNGLSTENCILMASKSEPARATEPROC ptr_glStencilMaskSeparate;
EXTPTR PFNGLATTACHSHADERPROC ptr_glAttachShader;
EXTPTR PFNGLCOMPILESHADERPROC ptr_glCompileShader;
EXTPTR PFNGLCREATEPROGRAMPROC ptr_glCreateProgram;
EXTPTR PFNGLCREATESHADERPROC ptr_glCreateShader;
EXTPTR PFNGLDELETEPROGRAMPROC ptr_glDeleteProgram;
EXTPTR PFNGLDELETESHADERPROC ptr_glDeleteShader;
EXTPTR PFNGLDETACHSHADERPROC ptr_glDetachShader;
EXTPTR PFNGLDISABLEVERTEXATTRIBARRAYPROC ptr_glDisableVertexAttribArray;
EXTPTR PFNGLENABLEVERTEXATTRIBARRAYPROC ptr_glEnableVertexAttribArray;
EXTPTR PFNGLGETPROGRAMIVPROC ptr_glGetProgramiv;
EXTPTR PFNGLGETPROGRAMINFOLOGPROC ptr_glGetProgramInfoLog;
EXTPTR PFNGLGETSHADERIVPROC ptr_glGetShaderiv;
EXTPTR PFNGLGETSHADERINFOLOGPROC ptr_glGetShaderInfoLog;
EXTPTR PFNGLLINKPROGRAMPROC ptr_glLinkProgram;
EXTPTR PFNGLSHADERSOURCEPROC ptr_glShaderSource;
EXTPTR PFNGLVALIDATEPROGRAMPROC ptr_glValidateProgram;
EXTPTR PFNGLVERTEXATTRIBPOINTERPROC ptr_glVertexAttribPointer;

// GL_VERSION_2_1

bool glextLoad_GL_VERSION_2_1(GLContextInfo& info);


// GL_VERSION_3_0

bool glextLoad_GL_VERSION_3_0(GLContextInfo& info);

EXTPTR PFNGLCOLORMASKIPROC ptr_glColorMaski;
EXTPTR PFNGLGETINTEGERI_VPROC ptr_glGetIntegeri_v;
EXTPTR PFNGLENABLEIPROC ptr_glEnablei;
EXTPTR PFNGLDISABLEIPROC ptr_glDisablei;
EXTPTR PFNGLBEGINTRANSFORMFEEDBACKPROC ptr_glBeginTransformFeedback;
EXTPTR PFNGLENDTRANSFORMFEEDBACKPROC ptr_glEndTransformFeedback;
EXTPTR PFNGLBINDBUFFERRANGEPROC ptr_glBindBufferRange;
EXTPTR PFNGLBINDBUFFERBASEPROC ptr_glBindBufferBase;
EXTPTR PFNGLTRANSFORMFEEDBACKVARYINGSPROC ptr_glTransformFeedbackVaryings;
EXTPTR PFNGLCLAMPCOLORPROC ptr_glClampColor;
EXTPTR PFNGLBEGINCONDITIONALRENDERPROC ptr_glBeginConditionalRender;
EXTPTR PFNGLENDCONDITIONALRENDERPROC ptr_glEndConditionalRender;
EXTPTR PFNGLVERTEXATTRIBIPOINTERPROC ptr_glVertexAttribIPointer;
EXTPTR PFNGLCLEARBUFFERIVPROC ptr_glClearBufferiv;
EXTPTR PFNGLCLEARBUFFERUIVPROC ptr_glClearBufferuiv;
EXTPTR PFNGLCLEARBUFFERFVPROC ptr_glClearBufferfv;
EXTPTR PFNGLCLEARBUFFERFIPROC ptr_glClearBufferfi;
EXTPTR PFNGLGETSTRINGIPROC ptr_glGetStringi;

// GL_ARB_depth_buffer_float

bool glextLoad_GL_ARB_depth_buffer_float(GLContextInfo& info);


// GL_ARB_framebuffer_object

bool glextLoad_GL_ARB_framebuffer_object(GLContextInfo& info);

EXTPTR PFNGLBINDRENDERBUFFERPROC ptr_glBindRenderbuffer;
EXTPTR PFNGLDELETERENDERBUFFERSPROC ptr_glDeleteRenderbuffers;
EXTPTR PFNGLGENRENDERBUFFERSPROC ptr_glGenRenderbuffers;
EXTPTR PFNGLBINDFRAMEBUFFERPROC ptr_glBindFramebuffer;
EXTPTR PFNGLDELETEFRAMEBUFFERSPROC ptr_glDeleteFramebuffers;
EXTPTR PFNGLGENFRAMEBUFFERSPROC ptr_glGenFramebuffers;
EXTPTR PFNGLCHECKFRAMEBUFFERSTATUSPROC ptr_glCheckFramebufferStatus;
EXTPTR PFNGLFRAMEBUFFERTEXTURE2DPROC ptr_glFramebufferTexture2D;
EXTPTR PFNGLFRAMEBUFFERRENDERBUFFERPROC ptr_glFramebufferRenderbuffer;
EXTPTR PFNGLGENERATEMIPMAPPROC ptr_glGenerateMipmap;
EXTPTR PFNGLBLITFRAMEBUFFERPROC ptr_glBlitFramebuffer;
EXTPTR PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC ptr_glRenderbufferStorageMultisample;
EXTPTR PFNGLFRAMEBUFFERTEXTURELAYERPROC ptr_glFramebufferTextureLayer;

// GL_ARB_framebuffer_sRGB

bool glextLoad_GL_ARB_framebuffer_sRGB(GLContextInfo& info);


// GL_ARB_half_float_vertex

bool glextLoad_GL_ARB_half_float_vertex(GLContextInfo& info);


// GL_ARB_map_buffer_range

bool glextLoad_GL_ARB_map_buffer_range(GLContextInfo& info);

EXTPTR PFNGLMAPBUFFERRANGEPROC ptr_glMapBufferRange;
EXTPTR PFNGLFLUSHMAPPEDBUFFERRANGEPROC ptr_glFlushMappedBufferRange;

// GL_ARB_texture_compression_rgtc

bool glextLoad_GL_ARB_texture_compression_rgtc(GLContextInfo& info);


// GL_ARB_texture_rg

bool glextLoad_GL_ARB_texture_rg(GLContextInfo& info);


// GL_ARB_vertex_array_object

bool glextLoad_GL_ARB_vertex_array_object(GLContextInfo& info);

EXTPTR PFNGLBINDVERTEXARRAYPROC ptr_glBindVertexArray;
EXTPTR PFNGLGENVERTEXARRAYSPROC ptr_glGenVertexArrays;

// GL_VERSION_3_1

bool glextLoad_GL_VERSION_3_1(GLContextInfo& info);

EXTPTR PFNGLTEXBUFFERPROC ptr_glTexBuffer;
EXTPTR PFNGLPRIMITIVERESTARTINDEXPROC ptr_glPrimitiveRestartIndex;

// GL_ARB_copy_buffer

bool glextLoad_GL_ARB_copy_buffer(GLContextInfo& info);

EXTPTR PFNGLCOPYBUFFERSUBDATAPROC ptr_glCopyBufferSubData;

// GL_ARB_uniform_buffer_object

bool glextLoad_GL_ARB_uniform_buffer_object(GLContextInfo& info);


// GL_VERSION_3_2

bool glextLoad_GL_VERSION_3_2(GLContextInfo& info);


// GL_ARB_depth_clamp

bool glextLoad_GL_ARB_depth_clamp(GLContextInfo& info);


// GL_ARB_draw_elements_base_vertex

bool glextLoad_GL_ARB_draw_elements_base_vertex(GLContextInfo& info);

EXTPTR PFNGLDRAWELEMENTSBASEVERTEXPROC ptr_glDrawElementsBaseVertex;
EXTPTR PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC ptr_glDrawRangeElementsBaseVertex;

// GL_ARB_fragment_coord_conventions

bool glextLoad_GL_ARB_fragment_coord_conventions(GLContextInfo& info);


// GL_ARB_provoking_vertex

bool glextLoad_GL_ARB_provoking_vertex(GLContextInfo& info);

EXTPTR PFNGLPROVOKINGVERTEXPROC ptr_glProvokingVertex;

// GL_ARB_seamless_cube_map

bool glextLoad_GL_ARB_seamless_cube_map(GLContextInfo& info);


// GL_ARB_sync

bool glextLoad_GL_ARB_sync(GLContextInfo& info);

EXTPTR PFNGLFENCESYNCPROC ptr_glFenceSync;
EXTPTR PFNGLDELETESYNCPROC ptr_glDeleteSync;
EXTPTR PFNGLCLIENTWAITSYNCPROC ptr_glClientWaitSync;
EXTPTR PFNGLWAITSYNCPROC ptr_glWaitSync;
EXTPTR PFNGLGETINTEGER64VPROC ptr_glGetInteger64v;

// GL_ARB_texture_multisample

bool glextLoad_GL_ARB_texture_multisample(GLContextInfo& info);

EXTPTR PFNGLFRAMEBUFFERTEXTUREPROC ptr_glFramebufferTexture;
EXTPTR PFNGLGETMULTISAMPLEFVPROC ptr_glGetMultisamplefv;
EXTPTR PFNGLSAMPLEMASKIPROC ptr_glSampleMaski;

// GL_VERSION_3_3

bool glextLoad_GL_VERSION_3_3(GLContextInfo& info);


// GL_ARB_blend_func_extended

bool glextLoad_GL_ARB_blend_func_extended(GLContextInfo& info);


// GL_ARB_explicit_attrib_location

bool glextLoad_GL_ARB_explicit_attrib_location(GLContextInfo& info);


// GL_ARB_occlusion_query2

bool glextLoad_GL_ARB_occlusion_query2(GLContextInfo& info);


// GL_ARB_sampler_objects

bool glextLoad_GL_ARB_sampler_objects(GLContextInfo& info);

EXTPTR PFNGLGENSAMPLERSPROC ptr_glGenSamplers;
EXTPTR PFNGLDELETESAMPLERSPROC ptr_glDeleteSamplers;
EXTPTR PFNGLBINDSAMPLERPROC ptr_glBindSampler;
EXTPTR PFNGLSAMPLERPARAMETERIPROC ptr_glSamplerParameteri;
EXTPTR PFNGLSAMPLERPARAMETERFPROC ptr_glSamplerParameterf;
EXTPTR PFNGLSAMPLERPARAMETERFVPROC ptr_glSamplerParameterfv;

// GL_ARB_shader_bit_encoding

bool glextLoad_GL_ARB_shader_bit_encoding(GLContextInfo& info);


// GL_ARB_texture_rgb10_a2ui

bool glextLoad_GL_ARB_texture_rgb10_a2ui(GLContextInfo& info);


// GL_ARB_texture_swizzle

bool glextLoad_GL_ARB_texture_swizzle(GLContextInfo& info);


// GL_ARB_timer_query

bool glextLoad_GL_ARB_timer_query(GLContextInfo& info);

EXTPTR PFNGLQUERYCOUNTERPROC ptr_glQueryCounter;
EXTPTR PFNGLGETQUERYOBJECTUI64VPROC ptr_glGetQueryObjectui64v;

// GL_ARB_vertex_type_2_10_10_10_rev

bool glextLoad_GL_ARB_vertex_type_2_10_10_10_rev(GLContextInfo& info);

EXTPTR PFNGLVERTEXATTRIBDIVISORPROC ptr_glVertexAttribDivisor;

// GL_VERSION_4_0

bool glextLoad_GL_VERSION_4_0(GLContextInfo& info);

EXTPTR PFNGLMINSAMPLESHADINGPROC ptr_glMinSampleShading;
EXTPTR PFNGLBLENDEQUATIONIPROC ptr_glBlendEquationi;
EXTPTR PFNGLBLENDEQUATIONSEPARATEIPROC ptr_glBlendEquationSeparatei;
EXTPTR PFNGLBLENDFUNCIPROC ptr_glBlendFunci;
EXTPTR PFNGLBLENDFUNCSEPARATEIPROC ptr_glBlendFuncSeparatei;

// GL_ARB_draw_buffers_blend

bool glextLoad_GL_ARB_draw_buffers_blend(GLContextInfo& info);


// GL_ARB_draw_indirect

bool glextLoad_GL_ARB_draw_indirect(GLContextInfo& info);

EXTPTR PFNGLDRAWARRAYSINDIRECTPROC ptr_glDrawArraysIndirect;
EXTPTR PFNGLDRAWELEMENTSINDIRECTPROC ptr_glDrawElementsIndirect;

// GL_ARB_gpu_shader5

bool glextLoad_GL_ARB_gpu_shader5(GLContextInfo& info);


// GL_ARB_gpu_shader_fp64

bool glextLoad_GL_ARB_gpu_shader_fp64(GLContextInfo& info);


// GL_ARB_shader_subroutine

bool glextLoad_GL_ARB_shader_subroutine(GLContextInfo& info);

EXTPTR PFNGLGETSUBROUTINEINDEXPROC ptr_glGetSubroutineIndex;
EXTPTR PFNGLUNIFORMSUBROUTINESUIVPROC ptr_glUniformSubroutinesuiv;

// GL_ARB_tessellation_shader

bool glextLoad_GL_ARB_tessellation_shader(GLContextInfo& info);

EXTPTR PFNGLPATCHPARAMETERIPROC ptr_glPatchParameteri;
EXTPTR PFNGLPATCHPARAMETERFVPROC ptr_glPatchParameterfv;

// GL_ARB_texture_buffer_object_rgb32

bool glextLoad_GL_ARB_texture_buffer_object_rgb32(GLContextInfo& info);


// GL_ARB_texture_cube_map_array

bool glextLoad_GL_ARB_texture_cube_map_array(GLContextInfo& info);


// GL_ARB_texture_gather

bool glextLoad_GL_ARB_texture_gather(GLContextInfo& info);


// GL_ARB_texture_query_lod

bool glextLoad_GL_ARB_texture_query_lod(GLContextInfo& info);


// GL_ARB_transform_feedback2

bool glextLoad_GL_ARB_transform_feedback2(GLContextInfo& info);

EXTPTR PFNGLBINDTRANSFORMFEEDBACKPROC ptr_glBindTransformFeedback;
EXTPTR PFNGLDELETETRANSFORMFEEDBACKSPROC ptr_glDeleteTransformFeedbacks;
EXTPTR PFNGLGENTRANSFORMFEEDBACKSPROC ptr_glGenTransformFeedbacks;
EXTPTR PFNGLPAUSETRANSFORMFEEDBACKPROC ptr_glPauseTransformFeedback;
EXTPTR PFNGLRESUMETRANSFORMFEEDBACKPROC ptr_glResumeTransformFeedback;

// GL_ARB_transform_feedback3

bool glextLoad_GL_ARB_transform_feedback3(GLContextInfo& info);

EXTPTR PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC ptr_glDrawTransformFeedbackStream;
EXTPTR PFNGLBEGINQUERYINDEXEDPROC ptr_glBeginQueryIndexed;

// GL_VERSION_4_1

bool glextLoad_GL_VERSION_4_1(GLContextInfo& info);


// GL_ARB_ES2_compatibility

bool glextLoad_GL_ARB_ES2_compatibility(GLContextInfo& info);


// GL_ARB_get_program_binary

bool glextLoad_GL_ARB_get_program_binary(GLContextInfo& info);

EXTPTR PFNGLGETPROGRAMBINARYPROC ptr_glGetProgramBinary;
EXTPTR PFNGLPROGRAMBINARYPROC ptr_glProgramBinary;
EXTPTR PFNGLPROGRAMPARAMETERIPROC ptr_glProgramParameteri;

// GL_ARB_separate_shader_objects

bool glextLoad_GL_ARB_separate_shader_objects(GLContextInfo& info);

EXTPTR PFNGLUSEPROGRAMSTAGESPROC ptr_glUseProgramStages;
EXTPTR PFNGLCREATESHADERPROGRAMVPROC ptr_glCreateShaderProgramv;
EXTPTR PFNGLBINDPROGRAMPIPELINEPROC ptr_glBindProgramPipeline;
EXTPTR PFNGLGENPROGRAMPIPELINESPROC ptr_glGenProgramPipelines;
EXTPTR PFNGLGETPROGRAMPIPELINEIVPROC ptr_glGetProgramPipelineiv;
EXTPTR PFNGLVALIDATEPROGRAMPIPELINEPROC ptr_glValidateProgramPipeline;

// GL_ARB_shader_precision

bool glextLoad_GL_ARB_shader_precision(GLContextInfo& info);


// GL_ARB_vertex_attrib_64bit

bool glextLoad_GL_ARB_vertex_attrib_64bit(GLContextInfo& info);

EXTPTR PFNGLVERTEXATTRIBLPOINTERPROC ptr_glVertexAttribLPointer;

// GL_ARB_viewport_array

bool glextLoad_GL_ARB_viewport_array(GLContextInfo& info);

EXTPTR PFNGLVIEWPORTINDEXEDFPROC ptr_glViewportIndexedf;
EXTPTR PFNGLSCISSORINDEXEDPROC ptr_glScissorIndexed;
EXTPTR PFNGLDEPTHRANGEINDEXEDPROC ptr_glDepthRangeIndexed;
EXTPTR PFNGLGETFLOATI_VPROC ptr_glGetFloati_v;

// GL_VERSION_4_2

bool glextLoad_GL_VERSION_4_2(GLContextInfo& info);


// GL_ARB_base_instance

bool glextLoad_GL_ARB_base_instance(GLContextInfo& info);

EXTPTR PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC ptr_glDrawArraysInstancedBaseInstance;
EXTPTR PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC ptr_glDrawElementsInstancedBaseVertexBaseInstance;

// GL_ARB_shading_language_420pack

bool glextLoad_GL_ARB_shading_language_420pack(GLContextInfo& info);


// GL_ARB_transform_feedback_instanced

bool glextLoad_GL_ARB_transform_feedback_instanced(GLContextInfo& info);

EXTPTR PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC ptr_glDrawTransformFeedbackStreamInstanced;

// GL_ARB_compressed_texture_pixel_storage

bool glextLoad_GL_ARB_compressed_texture_pixel_storage(GLContextInfo& info);


// GL_ARB_conservative_depth

bool glextLoad_GL_ARB_conservative_depth(GLContextInfo& info);


// GL_ARB_internalformat_query

bool glextLoad_GL_ARB_internalformat_query(GLContextInfo& info);

EXTPTR PFNGLGETINTERNALFORMATIVPROC ptr_glGetInternalformativ;

// GL_ARB_map_buffer_alignment

bool glextLoad_GL_ARB_map_buffer_alignment(GLContextInfo& info);


// GL_ARB_shader_atomic_counters

bool glextLoad_GL_ARB_shader_atomic_counters(GLContextInfo& info);


// GL_ARB_shader_image_load_store

bool glextLoad_GL_ARB_shader_image_load_store(GLContextInfo& info);

EXTPTR PFNGLBINDIMAGETEXTUREPROC ptr_glBindImageTexture;
EXTPTR PFNGLMEMORYBARRIERPROC ptr_glMemoryBarrier;

// GL_ARB_shading_language_packing

bool glextLoad_GL_ARB_shading_language_packing(GLContextInfo& info);


// GL_ARB_texture_compression_bptc

bool glextLoad_GL_ARB_texture_compression_bptc(GLContextInfo& info);


// GL_ARB_texture_storage

bool glextLoad_GL_ARB_texture_storage(GLContextInfo& info);

EXTPTR PFNGLTEXSTORAGE1DPROC ptr_glTexStorage1D;
EXTPTR PFNGLTEXSTORAGE2DPROC ptr_glTexStorage2D;
EXTPTR PFNGLTEXSTORAGE3DPROC ptr_glTexStorage3D;

// GL_VERSION_4_3

bool glextLoad_GL_VERSION_4_3(GLContextInfo& info);


// GL_ARB_arrays_of_arrays

bool glextLoad_GL_ARB_arrays_of_arrays(GLContextInfo& info);


// GL_ARB_fragment_layer_viewport

bool glextLoad_GL_ARB_fragment_layer_viewport(GLContextInfo& info);


// GL_ARB_shader_image_size

bool glextLoad_GL_ARB_shader_image_size(GLContextInfo& info);


// GL_ARB_ES3_compatibility

bool glextLoad_GL_ARB_ES3_compatibility(GLContextInfo& info);


// GL_ARB_clear_buffer_object

bool glextLoad_GL_ARB_clear_buffer_object(GLContextInfo& info);

EXTPTR PFNGLCLEARBUFFERDATAPROC ptr_glClearBufferData;
EXTPTR PFNGLCLEARBUFFERSUBDATAPROC ptr_glClearBufferSubData;

// GL_ARB_compute_shader

bool glextLoad_GL_ARB_compute_shader(GLContextInfo& info);

EXTPTR PFNGLDISPATCHCOMPUTEPROC ptr_glDispatchCompute;
EXTPTR PFNGLDISPATCHCOMPUTEINDIRECTPROC ptr_glDispatchComputeIndirect;

// GL_ARB_copy_image

bool glextLoad_GL_ARB_copy_image(GLContextInfo& info);

EXTPTR PFNGLCOPYIMAGESUBDATAPROC ptr_glCopyImageSubData;

// GL_KHR_debug

bool glextLoad_GL_KHR_debug(GLContextInfo& info);

EXTPTR PFNGLDEBUGMESSAGECONTROLPROC ptr_glDebugMessageControl;
EXTPTR PFNGLDEBUGMESSAGEINSERTPROC ptr_glDebugMessageInsert;
EXTPTR PFNGLDEBUGMESSAGECALLBACKPROC ptr_glDebugMessageCallback;
EXTPTR PFNGLPUSHDEBUGGROUPPROC ptr_glPushDebugGroup;
EXTPTR PFNGLPOPDEBUGGROUPPROC ptr_glPopDebugGroup;
EXTPTR PFNGLOBJECTLABELPROC ptr_glObjectLabel;
EXTPTR PFNGLOBJECTPTRLABELPROC ptr_glObjectPtrLabel;

// GL_ARB_explicit_uniform_location

bool glextLoad_GL_ARB_explicit_uniform_location(GLContextInfo& info);


// GL_ARB_framebuffer_no_attachments

bool glextLoad_GL_ARB_framebuffer_no_attachments(GLContextInfo& info);

EXTPTR PFNGLFRAMEBUFFERPARAMETERIPROC ptr_glFramebufferParameteri;

// GL_ARB_internalformat_query2

bool glextLoad_GL_ARB_internalformat_query2(GLContextInfo& info);

EXTPTR PFNGLGETINTERNALFORMATI64VPROC ptr_glGetInternalformati64v;

// GL_ARB_invalidate_subdata

bool glextLoad_GL_ARB_invalidate_subdata(GLContextInfo& info);

EXTPTR PFNGLINVALIDATETEXSUBIMAGEPROC ptr_glInvalidateTexSubImage;
EXTPTR PFNGLINVALIDATETEXIMAGEPROC ptr_glInvalidateTexImage;
EXTPTR PFNGLINVALIDATEBUFFERSUBDATAPROC ptr_glInvalidateBufferSubData;
EXTPTR PFNGLINVALIDATEBUFFERDATAPROC ptr_glInvalidateBufferData;
EXTPTR PFNGLINVALIDATEFRAMEBUFFERPROC ptr_glInvalidateFramebuffer;
EXTPTR PFNGLINVALIDATESUBFRAMEBUFFERPROC ptr_glInvalidateSubFramebuffer;

// GL_ARB_multi_draw_indirect

bool glextLoad_GL_ARB_multi_draw_indirect(GLContextInfo& info);

EXTPTR PFNGLMULTIDRAWARRAYSINDIRECTPROC ptr_glMultiDrawArraysIndirect;
EXTPTR PFNGLMULTIDRAWELEMENTSINDIRECTPROC ptr_glMultiDrawElementsIndirect;

// GL_ARB_program_interface_query

bool glextLoad_GL_ARB_program_interface_query(GLContextInfo& info);


// GL_ARB_robust_buffer_access_behavior

bool glextLoad_GL_ARB_robust_buffer_access_behavior(GLContextInfo& info);


// GL_ARB_shader_storage_buffer_object

bool glextLoad_GL_ARB_shader_storage_buffer_object(GLContextInfo& info);


// GL_ARB_stencil_texturing

bool glextLoad_GL_ARB_stencil_texturing(GLContextInfo& info);


// GL_ARB_texture_buffer_range

bool glextLoad_GL_ARB_texture_buffer_range(GLContextInfo& info);

EXTPTR PFNGLTEXBUFFERRANGEPROC ptr_glTexBufferRange;

// GL_ARB_texture_query_levels

bool glextLoad_GL_ARB_texture_query_levels(GLContextInfo& info);


// GL_ARB_texture_storage_multisample

bool glextLoad_GL_ARB_texture_storage_multisample(GLContextInfo& info);

EXTPTR PFNGLTEXSTORAGE2DMULTISAMPLEPROC ptr_glTexStorage2DMultisample;
EXTPTR PFNGLTEXSTORAGE3DMULTISAMPLEPROC ptr_glTexStorage3DMultisample;

// GL_ARB_texture_view

bool glextLoad_GL_ARB_texture_view(GLContextInfo& info);

EXTPTR PFNGLTEXTUREVIEWPROC ptr_glTextureView;

// GL_ARB_vertex_attrib_binding

bool glextLoad_GL_ARB_vertex_attrib_binding(GLContextInfo& info);

EXTPTR PFNGLBINDVERTEXBUFFERPROC ptr_glBindVertexBuffer;
EXTPTR PFNGLVERTEXATTRIBFORMATPROC ptr_glVertexAttribFormat;
EXTPTR PFNGLVERTEXATTRIBIFORMATPROC ptr_glVertexAttribIFormat;
EXTPTR PFNGLVERTEXATTRIBLFORMATPROC ptr_glVertexAttribLFormat;
EXTPTR PFNGLVERTEXBINDINGDIVISORPROC ptr_glVertexBindingDivisor;

// GL_VERSION_4_4

bool glextLoad_GL_VERSION_4_4(GLContextInfo& info);


// GL_ARB_buffer_storage

bool glextLoad_GL_ARB_buffer_storage(GLContextInfo& info);


// GL_ARB_clear_texture

bool glextLoad_GL_ARB_clear_texture(GLContextInfo& info);


// GL_ARB_enhanced_layouts

bool glextLoad_GL_ARB_enhanced_layouts(GLContextInfo& info);


// GL_ARB_multi_bind

bool glextLoad_GL_ARB_multi_bind(GLContextInfo& info);


// GL_ARB_query_buffer_object

bool glextLoad_GL_ARB_query_buffer_object(GLContextInfo& info);


// GL_ARB_texture_mirror_clamp_to_edge

bool glextLoad_GL_ARB_texture_mirror_clamp_to_edge(GLContextInfo& info);


// GL_ARB_texture_stencil8

bool glextLoad_GL_ARB_texture_stencil8(GLContextInfo& info);


// GL_ARB_vertex_type_10f_11f_11f_rev

bool glextLoad_GL_ARB_vertex_type_10f_11f_11f_rev(GLContextInfo& info);


// GL_EXT_texture_filter_anisotropic

bool glextLoad_GL_EXT_texture_filter_anisotropic(GLContextInfo& info);


// GL_EXT_texture_sRGB

bool glextLoad_GL_EXT_texture_sRGB(GLContextInfo& info);


// GL_EXT_texture_snorm

bool glextLoad_GL_EXT_texture_snorm(GLContextInfo& info);

