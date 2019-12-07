#pragma once
#include "core.hpp"

namespace furia {
	template<class Integrator>
	class Particle {
		Vector3 position;
		Vector3 velocity;
		Vector3 acceleration;
		scalar damping;
		scalar inverseMass;
		friend Integrator;
		Integrator integrator;
		void clearAccumulator() {};
	public:
		void integrate(scalar duration) { integrator.integrate(*this, duration); };
		Particle(const Vector3& p, const Vector3& v, const Vector3& a, scalar m, scalar d) {
			position = p;
			velocity = v;
			acceleration = a;
			inverseMass = 1 / m;
			damping = d;
		}
	};
}