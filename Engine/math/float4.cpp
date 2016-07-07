#include "float4.h"

namespace math {

	float4::float4() {
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}

	float4::float4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {
	}


	float4::~float4() {
	}

}