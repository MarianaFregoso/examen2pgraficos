// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"

#include <iostream>

#include "Vertice.h"
#include "Shader.h"
#include "Modelo.h"
#include "pajaro.h"

using namespace std;


GLfloat red, green, blue;

GLuint posicionID;
GLuint colorID;
GLuint transformacionesID;

Pajaro *pajaro;
Modelo *figura2;
Modelo *puerta;
Modelo *ventana;
Modelo *ventana2;


Shader *shader;
//Declaración de ventana
GLFWwindow *window;

void actualizar() {
	int estadoderecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoderecha == GLFW_PRESS) {
		pajaro->rotarpajaro(1);
		}
	

	int estadoizq = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoizq == GLFW_PRESS) {
		pajaro->rotarpajaro(0);
	}
		
	
};


void dibujar() {

	
	figura2->dibujar(GL_POLYGON);
	puerta->dibujar(GL_POLYGON);
	ventana->dibujar(GL_POLYGON);
	ventana2->dibujar(GL_POLYGON);
	pajaro->dibujar(GL_POLYGON);
}



void inicializarFigura() {
	pajaro = new Pajaro();

	Vertice v1 = { vec4(-0.1f, -0.1f, 0.0f, 1.0f), vec4(1.0f, 0.0f, 1.0f, 1.0f) };

	Vertice v2 = { vec4(0.0f, 0.1f, 0.0f, 1.0f), vec4(1.0f, 0.0f, 1.0f, 1.0f) };

	Vertice v3 = { vec4(0.1f, -0.1f, 0.0f, 1.0f), vec4(1.0f, 0.0f, 1.0f, 1.0f) };

	pajaro->vertices.push_back(v1);
	pajaro->vertices.push_back(v2);
	pajaro->vertices.push_back(v3);
}


void inicializarCuadrado() {
	figura2 = new Modelo();
	Vertice v1 = { vec4(-0.4f, -0.2f, 0.0f, 1.0f), vec4(1.0f, 0.5f, 0.0f, 1.0f) };

	Vertice v2 = { vec4(0.4f, -0.2f, 0.0f, 1.0f), vec4(1.0f, 0.5f, 0.0f, 1.0f) };

	Vertice v3 = { vec4(0.4f, -0.9f, 0.0f, 1.0f), vec4(1.0f, 0.5f, 0.0f, 1.0f) };

	Vertice v4 = { vec4(-0.4f, -0.9f, 0.0f, 1.0f), vec4(1.0f, 0.5f, 0.0f, 1.0f) };

	figura2->vertices.push_back(v1);
	figura2->vertices.push_back(v2);
	figura2->vertices.push_back(v3);
	figura2->vertices.push_back(v4);

	puerta = new Modelo();
	Vertice v5 = { vec4(-0.1f, -0.5f, 0.0f, 1.0f), vec4(0.0f, 0.8f, 0.0f, 0.6f) };

	Vertice v6 = { vec4(0.1f, -0.5, 0.0f, 1.0f), vec4(0.5f, 0.2f, 0.0f, 0.6f) };

	Vertice v7 = { vec4(0.1f, -0.9f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 0.4f) };

	Vertice v8 = { vec4(-0.1f, -0.9f, 0.0f, 1.0f), vec4(0.0f, 0.1f, 0.0f, 0.8f) };

	puerta->vertices.push_back(v5);
	puerta->vertices.push_back(v6);
	puerta->vertices.push_back(v7);
	puerta->vertices.push_back(v8);

	ventana = new Modelo();
	Vertice v9 = { vec4(-0.3f, -0.3f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 1.0f, 0.0f) };

	Vertice v10 = { vec4(-0.1f, -0.3f, 0.0f, 1.0f), vec4(1.6f, .5f, 1.0f, 1.0f) };

	Vertice v11 = { vec4(-0.1f, -0.4f, 0.0f, 1.0f), vec4(0.9f, 0.6f, 0.0f, 1.0f) };

	Vertice v12 = { vec4(-0.3f, -0.4f, 0.0f, 1.0f), vec4(0.0f, 1.0f, 0.0f, 1.0f) };

	ventana->vertices.push_back(v9);
	ventana->vertices.push_back(v10);
	ventana->vertices.push_back(v11);
	ventana->vertices.push_back(v12);

	ventana2 = new Modelo();
	Vertice v13 = { vec4(0.3f, -0.3f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 1.0f, 0.0f) };

	Vertice v14 = { vec4(0.1f, -0.3f, 0.0f, 1.0f), vec4(1.6f, .5f, 1.0f, 1.0f) };

	Vertice v15 = { vec4(0.1f, -0.4f, 0.0f, 1.0f), vec4(0.9f, 0.6f, 0.0f, 1.0f) };

	Vertice v16 = { vec4(0.3f, -0.4f, 0.0f, 1.0f), vec4(0.0f, 1.0f, 0.0f, 1.0f) };

	ventana2->vertices.push_back(v13);
	ventana2->vertices.push_back(v14);
	ventana2->vertices.push_back(v15);
	ventana2->vertices.push_back(v16);
	
}



int main()
{
	
	//Propiedades de la ventana
	GLfloat ancho = 1024;
	GLfloat alto = 768;

	//Inicialización de GLFW
	if (!glfwInit()) {
		//Si no se inició bien, terminar la ejecución
		exit(EXIT_FAILURE);
	}

	//Inicializar la ventana
	window = glfwCreateWindow(ancho, alto, "Graficos", NULL, NULL);
	//Verficar si se creó bien la ventana
	if (!window) {
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		//Termina ejecución
		exit(EXIT_FAILURE);
	}

	//Establecer "window" como contexto
	glfwMakeContextCurrent(window);

	//Se trae las funciones de OpenGL Moderno
	glewExperimental = true;
	//Inicializar GLEW
	GLenum glewError = glewInit();
	//Verificar que GLEW se inicializó bien
	if (glewError != GLEW_OK) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}


	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGL: " << version << endl;


	red =0.0f, green =0.6f, blue = 1.0f;

	inicializarFigura();
	inicializarCuadrado();


	//crear instancia del shader
	const char * rutaVertex = "vShaderSimple.shader";
	const char * rutaFragment = "fShaderSimple.shader";

	shader = new  Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos 

	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");
	transformacionesID = glGetUniformLocation (shader->getID(), "transformaciones");

	//Desenlazar el shader
	shader->desenlazarShader();

	pajaro->shader = shader;
	pajaro->inicializarVertexArray(posicionID, colorID,transformacionesID);

	figura2->shader = shader;
	figura2->inicializarVertexArray(posicionID, colorID,transformacionesID);
    puerta->shader = shader;
	puerta->inicializarVertexArray(posicionID, colorID, transformacionesID);
	ventana->shader = shader;
	ventana->inicializarVertexArray(posicionID, colorID, transformacionesID);
	ventana2->shader = shader;
	ventana2->inicializarVertexArray(posicionID, colorID, transformacionesID);




	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window)) {
		//Establecer el area de render (viewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia la pantalla
		glClearColor(red, green, blue, 1);
		//Limpiar la pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//rutina de dibujo
		actualizar();
		dibujar();

		//Intercambio de buffers
		glfwSwapBuffers(window);
		//Buscar señales de entrada
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

