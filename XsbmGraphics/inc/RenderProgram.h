#ifndef XSBM_GRAPHICS_INC_RENDERPROGRAM_H_
#define XSBM_GRAPHICS_INC_RENDERPROGRAM_H_
#include <string>
#include "GL/glew.h"
namespace xsbm{

	struct RenderProgramUniform
	{
		std::string name_in_shader_;
		GLenum value_type_;
		GLint uniform_location_;
		GLuint program_handle_;
		GLsizei value_size_;
		GLuint texture_unit_;

		RenderProgramUniform(){}
		RenderProgramUniform(std::string name_in_shader,
			GLenum value_type,
			GLint uniform_location,
			GLuint program_handle,
			GLsizei value_size):
			name_in_shader_(name_in_shader),
			value_type_(value_type),
			uniform_location_(uniform_location),
			program_handle_(program_handle),
			value_size_(value_size){}
		~RenderProgramUniform(){}
		bool operator<<(const void* value)	const;
	};

	class RenderProgram
	{
	public:
		RenderProgram();
		~RenderProgram();

	private:

	};
}
#endif