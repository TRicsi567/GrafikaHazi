#pragma once

// GLEW
#include <GL/glew.h>

// SDL
#include <SDL.h>
#include <SDL_opengl.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>

class CMyApp
{
public:
	CMyApp(void);
	~CMyApp(void);

	bool Init();
	void Clean();

	void Update();
	void Render();

	void KeyboardDown(SDL_KeyboardEvent&);
	void KeyboardUp(SDL_KeyboardEvent&);
	void MouseMove(SDL_MouseMotionEvent&);
	void MouseDown(SDL_MouseButtonEvent&);
	void MouseUp(SDL_MouseButtonEvent&);
	void MouseWheel(SDL_MouseWheelEvent&);
	void Resize(int, int);
protected:
	// shaderekhez sz�ks�ges v�ltoz�k
	GLuint m_programID; // shaderek programja

	// OpenGL-es dolgok
	GLuint m_vaoID; // vertex array object er�forr�s azonos�t�
	GLuint m_vboID; // vertex buffer object er�forr�s azonos�t�

	// transzform�ci�s m�trixok
	glm::mat4 m_matWorld;
	glm::mat4 m_matView;
	glm::mat4 m_matProj;

	GLfloat m_time = 0;


	// m�trixok helye a shaderekben
	GLuint	m_loc_world;
	GLuint	m_loc_view;
	GLuint	m_loc_proj;

	GLuint m_loc_time;

private:
	double look_at_from_x = 0;
	double look_at_from_y = 0;
	double look_at_from_z = 5;

	double deg_horiz = 90;
	double deg_vert = 0;

	int x_offset1 = -2;
	int x_offset2 = 2;

	struct Vertex
	{
		glm::vec3 p;
		glm::vec3 c;
	};
};

