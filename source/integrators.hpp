#pragma once
#include <functional>
#include "core.hpp"
#include <assert.h>
#include "particle.hpp"


using namespace furia;

class ExponentialDamping {
public:
	void integrate(Particle<ExponentialDamping>& _p, scalar duration) {
		if (_p.inverseMass <= 0.0f) {
			return;
		}

		assert(duration >= 0.0f);

		_p.position.addScaledVector(_p.velocity, duration);
		Vector3 resultinAcceleration = _p.acceleration;

		_p.velocity.addScaledVector(resultinAcceleration, duration);

		_p.velocity *= pow(_p.damping, duration);

		_p.clearAccumulator();
	};
};