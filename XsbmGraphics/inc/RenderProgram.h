#ifndef XSBM_GRAPHICS_INC_RENDERPROGRAM_H_
#define XSBM_GRAPHICS_INC_RENDERPROGRAM_H_
#include <string>
#include <map>
#include "GL/glew.h"
namespace xsbm{

	struct RenderProgramUniform
	{
		std::string name_in_shader_;
		GLenum value_type_;
		GLint uniform_location_;
		GLuint program_handle_;
		GLsizei value_size_;
		int value_count_;
		GLuint texture_unit_;
		int xsbm_enum_index_;

		RenderProgramUniform(){}
		RenderProgramUniform(std::string name_in_shader,
			GLenum value_type,
			GLint uniform_location,
			GLuint program_handle,
			GLsizei value_size,
			int value_count,
			GLuint texture_unit);
		~RenderProgramUniform(){}
		bool operator<<(const void* value)	const;
	};

	class RenderProgram
	{
	public:
		RenderProgram();
		virtual ~RenderProgram();
		bool CompileFromFiles(const std::string& program_config_file);
		bool CompileFromStrings(const std::string& vertex_shader,
			const std::string& fragment_shader);

		const RenderProgramUniform& operator[](const std::string& name_in_shader)const;
	private:
		bool AnalyzeProgram();
		std::map<std::string, RenderProgramUniform> uniform_map_;
	};
}
#endif