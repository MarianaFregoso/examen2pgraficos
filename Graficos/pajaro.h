#pragma once
#include "Modelo.h"
#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"

class Pajaro : public Modelo {
public: 
	Pajaro();
	float angulo;
	vec3 coordenadas; 
	float velocidadAngular = 0.003f;
	float velocidad = 0.0005f;
	void rotarpajaro(int direccion );
};