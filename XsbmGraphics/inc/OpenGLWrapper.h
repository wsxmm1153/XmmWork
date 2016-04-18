#ifndef XSBM_GRAPHICS_INC_OPENGLWRAPPER_H_
#define XSBM_GRAPHICS_INC_OPENGLWRAPPER_H_
#include "GL/glew.h"
#include <string>

namespace xsbm{
	enum TypeInGLProgram_ArrayIndex : int//in glspec43 compatibility, page 93, type table
	{
		XSBM_FLOAT, XSBM_FLOAT_VEC2, XSBM_FLOAT_VEC3, XSBM_FLOAT_VEC4,
		XSBM_DOUBLE, XSBM_DOUBLE_VEC2, XSBM_DOUBLE_VEC3, XSBM_DOUBLE_VEC4,
		XSBM_INT, XSBM_INT_VEC2, XSBM_INT_VEC3, XSBM_INT_VEC4,
		XSBM_UNSIGNED_INT, XSBM_UNSIGNED_INT_VEC2, XSBM_UNSIGNED_INT_VEC3, XSBM_UNSIGNED_INT_VEC4,
		XSBM_BOOL, XSBM_BOOL_VEC2, XSBM_BOOL_VEC3, XSBM_BOOL_VEC4,
		XSBM_FLOAT_MAT2, XSBM_FLOAT_MAT3, XSBM_FLOAT_MAT4,
		XSBM_FLOAT_MAT2x3, XSBM_FLOAT_MAT2x4,
		XSBM_FLOAT_MAT3x2, XSBM_FLOAT_MAT3x4,
		XSBM_FLOAT_MAT4x2, XSBM_FLOAT_MAT4x3,
		XSBM_DOUBLE_MAT2, XSBM_DOUBLE_MAT3, XSBM_DOUBLE_MAT4,
		XSBM_DOUBLE_MAT2x3, XSBM_DOUBLE_MAT2x4,
		XSBM_DOUBLE_MAT3x2, XSBM_DOUBLE_MAT3x4,
		XSBM_DOUBLE_MAT4x2, XSBM_DOUBLE_MAT4x3,
		XSBM_SAMPLER_1D, XSBM_SAMPLER_2D, XSBM_SAMPLER_3D,
		XSBM_SAMPLER_CUBE,
		XSBM_SAMPLER_1D_SHADOW, XSBM_SAMPLER_2D_SHADOW,
		XSBM_SAMPLER_1D_ARRAY, XSBM_SAMPLER_2D_ARRAY,
		XSBM_SAMPLER_CUBE_MAP_ARRAY,
		XSBM_SAMPLER_1D_ARRAY_SHADOW, XSBM_SAMPLER_2D_ARRAY_SHADOW,
		XSBM_SAMPLER_2D_MULTISAMPLE, XSBM_SAMPLER_2D_MULTISAMPLE_ARRAY,
		XSBM_SAMPLER_CUBE_SHADOW, XSBM_SAMPLER_CUBE_MAP_ARRAY_SHADOW,
		XSBM_SAMPLER_BUFFER,
		XSBM_SAMPLER_2D_RECT, XSBM_SAMPLER_2D_RECT_SHADOW,
		XSBM_INT_SAMPLER_1D, XSBM_INT_SAMPLER_2D, XSBM_INT_SAMPLER_3D,
		XSBM_INT_SAMPLER_CUBE, 
		XSBM_INT_SAMPLER_1D_ARRAY, XSBM_INT_SAMPLER_2D_ARRAY,
		XSBM_INT_SAMPLER_CUBE_MAP_ARRAY,
		XSBM_INT_SAMPLER_2D_MULTISAMPLE, XSBM_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
		XSBM_INT_SAMPLER_BUFFER,
		XSBM_INT_SAMPLER_2D_RECT,
		XSBM_UNSIGNED_INT_SAMPLER_1D, XSBM_UNSIGNED_INT_SAMPLER_2D, XSBM_UNSIGNED_INT_SAMPLER_3D,
		XSBM_UNSIGNED_INT_SAMPLER_CUBE,
		XSBM_UNSIGNED_INT_SAMPLER_1D_ARRAY, XSBM_UNSIGNED_INT_SAMPLER_2D_ARRAY,
		XSBM_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY,
		XSBM_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE, XSBM_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
		XSBM_UNSIGNED_INT_SAMPLER_BUFFER,
		XSBM_UNSIGNED_INT_SAMPLER_2D_RECT,
		XSBM_IMAGE_1D, XSBM_IMAGE_2D, XSBM_IMAGE_3D,
		XSBM_IMAGE_2D_RECT,
		XSBM_IMAGE_CUBE,
		XSBM_IMAGE_BUFFER,
		XSBM_IMAGE_1D_ARRAY, XSBM_IMAGE_2D_ARRAY,
		XSBM_IMAGE_CUBE_MAP_ARRAY, 
		XSBM_IMAGE_2D_MULTISAMPLE, XSBM_IMAGE_2D_MULTISAMPLE_ARRAY,
		XSBM_INT_IMAGE_1D, XSBM_INT_IMAGE_2D, XSBM_INT_IMAGE_3D,
		XSBM_INT_IMAGE_2D_RECT,
		XSBM_INT_IMAGE_CUBE,
		XSBM_INT_IMAGE_BUFFER,
		XSBM_INT_IMAGE_1D_ARRAY, XSBM_INT_IMAGE_2D_ARRAY,
		XSBM_INT_IMAGE_CUBE_MAP_ARRAY,
		XSBM_INT_IMAGE_2D_MULTISAMPLE, XSBM_INT_IMAGE_2D_MULTISAMPLE_ARRAY,
		XSBM_UNSIGNED_INT_IMAGE_1D, XSBM_UNSIGNED_INT_IMAGE_2D, XSBM_UNSIGNED_INT_IMAGE_3D,
		XSBM_UNSIGNED_INT_IMAGE_2D_RECT,
		XSBM_UNSIGNED_INT_IMAGE_CUBE,
		XSBM_UNSIGNED_INT_IMAGE_BUFFER,
		XSBM_UNSIGNED_INT_IMAGE_1D_ARRAY, XSBM_UNSIGNED_INT_IMAGE_2D_ARRAY,
		XSBM_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY,
		XSBM_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE, XSBM_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY,
		XSBM_UNSIGNED_INT_ATOMIC_COUNTER,

		XSBM_TYPEINGLPROGRAM_ARRAYINDEX_COUNT
	};

	const GLenum TypeInGLProgram_GLEnum[XSBM_TYPEINGLPROGRAM_ARRAYINDEX_COUNT] = {
		GL_FLOAT, GL_FLOAT_VEC2, GL_FLOAT_VEC3, GL_FLOAT_VEC4,
		GL_DOUBLE, GL_DOUBLE_VEC2, GL_DOUBLE_VEC3, GL_DOUBLE_VEC4,
		GL_INT, GL_INT_VEC2, GL_INT_VEC3, GL_INT_VEC4,
		GL_UNSIGNED_INT, GL_UNSIGNED_INT_VEC2, GL_UNSIGNED_INT_VEC3, GL_UNSIGNED_INT_VEC4,
		GL_BOOL, GL_BOOL_VEC2, GL_BOOL_VEC3, GL_BOOL_VEC4,
		GL_FLOAT_MAT2, GL_FLOAT_MAT3, GL_FLOAT_MAT4,
		GL_FLOAT_MAT2x3, GL_FLOAT_MAT2x4,
		GL_FLOAT_MAT3x2, GL_FLOAT_MAT3x4,
		GL_FLOAT_MAT4x2, GL_FLOAT_MAT4x3,
		GL_DOUBLE_MAT2, GL_DOUBLE_MAT3, GL_DOUBLE_MAT4,
		GL_DOUBLE_MAT2x3, GL_DOUBLE_MAT2x4,
		GL_DOUBLE_MAT3x2, GL_DOUBLE_MAT3x4,
		GL_DOUBLE_MAT4x2, GL_DOUBLE_MAT4x3,
		GL_SAMPLER_1D, GL_SAMPLER_2D, GL_SAMPLER_3D,
		GL_SAMPLER_CUBE,
		GL_SAMPLER_1D_SHADOW, GL_SAMPLER_2D_SHADOW,
		GL_SAMPLER_1D_ARRAY, GL_SAMPLER_2D_ARRAY,
		GL_SAMPLER_CUBE_MAP_ARRAY,
		GL_SAMPLER_1D_ARRAY_SHADOW, GL_SAMPLER_2D_ARRAY_SHADOW,
		GL_SAMPLER_2D_MULTISAMPLE, GL_SAMPLER_2D_MULTISAMPLE_ARRAY,
		GL_SAMPLER_CUBE_SHADOW, GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW,
		GL_SAMPLER_BUFFER,
		GL_SAMPLER_2D_RECT, GL_SAMPLER_2D_RECT_SHADOW,
		GL_INT_SAMPLER_1D, GL_INT_SAMPLER_2D, GL_INT_SAMPLER_3D,
		GL_INT_SAMPLER_CUBE,
		GL_INT_SAMPLER_1D_ARRAY, GL_INT_SAMPLER_2D_ARRAY,
		GL_INT_SAMPLER_CUBE_MAP_ARRAY,
		GL_INT_SAMPLER_2D_MULTISAMPLE, GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
		GL_INT_SAMPLER_BUFFER,
		GL_INT_SAMPLER_2D_RECT,
		GL_UNSIGNED_INT_SAMPLER_1D, GL_UNSIGNED_INT_SAMPLER_2D, GL_UNSIGNED_INT_SAMPLER_3D,
		GL_UNSIGNED_INT_SAMPLER_CUBE,
		GL_UNSIGNED_INT_SAMPLER_1D_ARRAY, GL_UNSIGNED_INT_SAMPLER_2D_ARRAY,
		GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY,
		GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE, GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
		GL_UNSIGNED_INT_SAMPLER_BUFFER,
		GL_UNSIGNED_INT_SAMPLER_2D_RECT,
		GL_IMAGE_1D, GL_IMAGE_2D, GL_IMAGE_3D,
		GL_IMAGE_2D_RECT,
		GL_IMAGE_CUBE,
		GL_IMAGE_BUFFER,
		GL_IMAGE_1D_ARRAY, GL_IMAGE_2D_ARRAY,
		GL_IMAGE_CUBE_MAP_ARRAY,
		GL_IMAGE_2D_MULTISAMPLE, GL_IMAGE_2D_MULTISAMPLE_ARRAY,
		GL_INT_IMAGE_1D, GL_INT_IMAGE_2D, GL_INT_IMAGE_3D,
		GL_INT_IMAGE_2D_RECT,
		GL_INT_IMAGE_CUBE,
		GL_INT_IMAGE_BUFFER,
		GL_INT_IMAGE_1D_ARRAY, GL_INT_IMAGE_2D_ARRAY,
		GL_INT_IMAGE_CUBE_MAP_ARRAY,
		GL_INT_IMAGE_2D_MULTISAMPLE, GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY,
		GL_UNSIGNED_INT_IMAGE_1D, GL_UNSIGNED_INT_IMAGE_2D, GL_UNSIGNED_INT_IMAGE_3D,
		GL_UNSIGNED_INT_IMAGE_2D_RECT,
		GL_UNSIGNED_INT_IMAGE_CUBE,
		GL_UNSIGNED_INT_IMAGE_BUFFER,
		GL_UNSIGNED_INT_IMAGE_1D_ARRAY, GL_UNSIGNED_INT_IMAGE_2D_ARRAY,
		GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY,
		GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE, GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY,
		GL_UNSIGNED_INT_ATOMIC_COUNTER
	};

	struct VariableInfoInGLProgram
	{
		enum full_type : int
		{
			var_float,
			var_double,
			var_int,
			var_unsigned_int,
			max_full_type
		};
		enum abbreviate_type : int
		{
			var_f,
			var_d,
			var_i,
			var_ui,
			max_abbreviate_type
		};
		enum dimension : int
		{
			var_1,
			var_2,
			var_3,
			var_4,
			var_mat2,
			var_mat3,
			var_mat4,
			var_mat2x3,
			var_mat2x4,
			var_mat3x2,
			var_mat3x4,
			var_mat4x2,
			var_mat4x3,
			max_dimension
		};
		full_type full_type_;
		abbreviate_type abbreviate_type_;
		dimension dimension_;
		VariableInfoInGLProgram(const std::string _full_type,
			const std::string _abbreviate_type,
			const std::string _dimension):
			full_type_(max_full_type),
			abbreviate_type_(max_abbreviate_type),
			dimension_(max_dimension)
		{
			if (_full_type == "float")	full_type_ = var_float;
			else if (_full_type == "double")	full_type_ = var_double;
			else if (_full_type == "int")	full_type_ = var_int;
			else if (_full_type == "unsigned int")	full_type_ = var_unsigned_int;
			else;
			if (_dimension == "1")	dimension_ = var_1;
			else if (_dimension == "2")	dimension_ = var_2;
			else if (_dimension == "3")	dimension_ = var_3;
			else if (_dimension == "4") dimension_ = var_4;
			else if (_dimension == "Matrix2")	dimension_ = var_mat2;
			else if (_dimension == "Matrix3")	dimension_ = var_mat3;
			else if (_dimension == "Matrix4")	dimension_ = var_mat4;
			else if (_dimension == "Matrix2x3")	dimension_ = var_mat2x3;
			else if (_dimension == "Matrix2x4")	dimension_ = var_mat2x4;
			else if (_dimension == "Matrix3x2")	dimension_ = var_mat3x2;
			else if (_dimension == "Matrix3x4")	dimension_ = var_mat3x4;
			else if (_dimension == "Matrix4x2")	dimension_ = var_mat4x2;
			else if (_dimension == "Matrix4x3")	dimension_ = var_mat4x3;
			else;
			if (_abbreviate_type == "f")	abbreviate_type_ = var_f;
			if (_abbreviate_type == "d")	abbreviate_type_ = var_d;
			if (_abbreviate_type == "i")	abbreviate_type_ = var_i;
			if (_abbreviate_type == "ui")	abbreviate_type_ = var_ui;
		}

	};

	const VariableInfoInGLProgram TypeInGLProgram_VariableInfo[XSBM_TYPEINGLPROGRAM_ARRAYINDEX_COUNT] = {
		VariableInfoInGLProgram("float", "f", "1"), VariableInfoInGLProgram("float", "f", "2"), VariableInfoInGLProgram("float", "f", "3"), VariableInfoInGLProgram("float", "f", "4"),
		VariableInfoInGLProgram("double", "d", "1"), VariableInfoInGLProgram("double", "d", "2"), VariableInfoInGLProgram("double", "d", "3"), VariableInfoInGLProgram("double", "d", "4"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "2"), VariableInfoInGLProgram("int", "i", "3"), VariableInfoInGLProgram("int", "i", "4"),
		VariableInfoInGLProgram("unsigned int", "ui", "1"), VariableInfoInGLProgram("unsigned int", "ui", "2"), VariableInfoInGLProgram("unsigned int", "ui", "3"), VariableInfoInGLProgram("unsigned int", "ui", "4"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "2"), VariableInfoInGLProgram("int", "i", "3"), VariableInfoInGLProgram("int", "i", "4"),
		VariableInfoInGLProgram("float", "f", "Matrix2"), VariableInfoInGLProgram("float", "f", "Matrix3"), VariableInfoInGLProgram("float", "f", "Matrix4"),
		VariableInfoInGLProgram("float", "f", "Matrix2x3"), VariableInfoInGLProgram("float", "f", "Matrix2x4"),
		VariableInfoInGLProgram("float", "f", "Matrix3x2"), VariableInfoInGLProgram("float", "f", "Matrix3x4"),
		VariableInfoInGLProgram("float", "f", "Matrix4x2"), VariableInfoInGLProgram("float", "f", "Matrix4x3"),
		VariableInfoInGLProgram("double", "d", "Matrix2"), VariableInfoInGLProgram("double", "d", "Matrix3"), VariableInfoInGLProgram("double", "d", "Matrix4"),
		VariableInfoInGLProgram("double", "d", "Matrix2x3"), VariableInfoInGLProgram("double", "d", "Matrix2x4"),
		VariableInfoInGLProgram("double", "d", "Matrix3x2"), VariableInfoInGLProgram("double", "d", "Matrix3x4"),
		VariableInfoInGLProgram("double", "d", "Matrix4x2"), VariableInfoInGLProgram("double", "d", "Matrix4x3"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1"), VariableInfoInGLProgram("int", "i", "1"),
		VariableInfoInGLProgram("int", "i", "1")
	};
}

#endif