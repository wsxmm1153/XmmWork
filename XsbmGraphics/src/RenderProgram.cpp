#include <assert.h>
#include "RenderProgram.h"
#include "OpenGLWrapper.h"
#define xsbmProgramUniformfv(dimension)\
 glProgramUniform##dimension##fv(program_handle_, uniform_location_, value_count_, (float*)value)
#define xsbmProgramUniformdv(dimension)\
 glProgramUniform##dimension##dv(program_handle_, uniform_location_, value_count_, (double*)value)
#define xsbmProgramUniformiv(dimension)\
 glProgramUniform##dimension##iv(program_handle_, uniform_location_, value_count_, (int*)value)
#define xsbmProgramUniformuiv(dimension)\
 glProgramUniform##dimension##uiv(program_handle_, uniform_location_, value_count_, (unsigned int*)value)
#define xsbmProgramUniformfvMat(dimension)\
 glProgramUniform##dimension##fv(program_handle_, uniform_location_, value_count_, GL_FALSE, (float*)value)
#define xsbmProgramUniformdvMat(dimension)\
 glProgramUniform##dimension##dv(program_handle_, uniform_location_, value_count_, GL_FALSE, (double*)value)
#define xsbmProgramUniform(type,dimension) {switch(type){\
default:\
case (VariableInfoInGLProgram::var_f):{xsbmProgramUniformfv(dimension);break;}\
case (VariableInfoInGLProgram::var_d):{xsbmProgramUniformdv(dimension);break;}\
case (VariableInfoInGLProgram::var_i):{xsbmProgramUniformiv(dimension);break;}\
case (VariableInfoInGLProgram::var_ui):{xsbmProgramUniformuiv(dimension);break;}\
}}

#define xsbmProgramUniformMat(type,dimension) {switch(type){\
default:\
case (VariableInfoInGLProgram::var_f):{xsbmProgramUniformfvMat(dimension);break;}\
case (VariableInfoInGLProgram::var_d):{xsbmProgramUniformdvMat(dimension);break;}\
}}

namespace xsbm{

	RenderProgramUniform::RenderProgramUniform(std::string name_in_shader,
		GLenum value_type,
		GLint uniform_location,
		GLuint program_handle,
		GLsizei value_size,
		int value_count,
		GLuint texture_unit) :
		name_in_shader_(name_in_shader),
		value_type_(value_type),
		uniform_location_(uniform_location),
		program_handle_(program_handle),
		value_size_(value_size),
		value_count_(value_count),
		texture_unit_(texture_unit)
	{
		int i = 0;
		for (; i < XSBM_TYPEINGLPROGRAM_ARRAYINDEX_COUNT; i++)
		{
			if (TypeInGLProgram_GLEnum[i] == value_type_)
				break;
		}
#ifdef STRICT_CHECK_ERROR
		assert(i < XSBM_TYPEINGLPROGRAM_ARRAYINDEX_COUNT);
#endif
		xsbm_enum_index_ = i;
	}


	bool RenderProgramUniform::operator<<(const void* value) const
	{
#ifdef STRICT_CHECK_ERROR
		assert(program_handle_);
		assert(uniform_location_ >= 0);
		assert(xsbm_enum_index_ >= 0);
		assert(xsbm_enum_index_ < XSBM_TYPEINGLPROGRAM_ARRAYINDEX_COUNT);
		assert(!glGetError());
#endif // STRICT_CHECK_ERROR

		int i = xsbm_enum_index_;

		switch (TypeInGLProgram_VariableInfo[i].dimension_)
		{
		default:
		case VariableInfoInGLProgram::var_1 :
			xsbmProgramUniform(TypeInGLProgram_VariableInfo[i].abbreviate_type_, 1);
			break;
		case VariableInfoInGLProgram::var_2:
			xsbmProgramUniform(TypeInGLProgram_VariableInfo[i].abbreviate_type_, 2);
			break;
		case VariableInfoInGLProgram::var_3:
			xsbmProgramUniform(TypeInGLProgram_VariableInfo[i].abbreviate_type_, 3);
			break;
		case VariableInfoInGLProgram::var_4:
			xsbmProgramUniform(TypeInGLProgram_VariableInfo[i].abbreviate_type_, 4);
			break;
		case VariableInfoInGLProgram::var_mat2:
			xsbmProgramUniformMat(TypeInGLProgram_VariableInfo[i].abbreviate_type_, Matrix2);
			break;
		case VariableInfoInGLProgram::var_mat3:
			xsbmProgramUniformMat(TypeInGLProgram_VariableInfo[i].abbreviate_type_, Matrix3);
			break;
		case VariableInfoInGLProgram::var_mat4:
			xsbmProgramUniformMat(TypeInGLProgram_VariableInfo[i].abbreviate_type_, Matrix4);
			break;
		case VariableInfoInGLProgram::var_mat2x3:
			xsbmProgramUniformMat(TypeInGLProgram_VariableInfo[i].abbreviate_type_, Matrix2x3);
			break;
		case VariableInfoInGLProgram::var_mat2x4:
			xsbmProgramUniformMat(TypeInGLProgram_VariableInfo[i].abbreviate_type_, Matrix2x4);
			break;
		case VariableInfoInGLProgram::var_mat3x2:
			xsbmProgramUniformMat(TypeInGLProgram_VariableInfo[i].abbreviate_type_, Matrix3x2);
			break;
		case VariableInfoInGLProgram::var_mat3x4:
			xsbmProgramUniformMat(TypeInGLProgram_VariableInfo[i].abbreviate_type_, Matrix3x4);
			break;
		case VariableInfoInGLProgram::var_mat4x2:
			xsbmProgramUniformMat(TypeInGLProgram_VariableInfo[i].abbreviate_type_, Matrix4x2);
			break;
		case VariableInfoInGLProgram::var_mat4x3:
			xsbmProgramUniformMat(TypeInGLProgram_VariableInfo[i].abbreviate_type_, Matrix4x3);
			break;
		}
#ifdef STRICT_CHECK_ERROR
		assert(!glGetError());
#endif // STRICT_CHECK_ERROR

		return true;
	}


}