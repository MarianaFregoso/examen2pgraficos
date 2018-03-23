#include "stdafx.h"
#include "pajaro.h"

Pajaro::Pajaro() {

	angulo = 360.0f;
	transformaciones = mat4(1.0f);
}

void Pajaro::rotarpajaro(int direccion) {
	float rotacion = velocidadAngular;
	if (direccion == 1) {
		rotacion = -rotacion;
	}
	transformaciones =
		rotate(transformaciones, rotacion, vec3(0.0f, 0.0f, 1.0f));

	
}


