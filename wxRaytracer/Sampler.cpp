#include "Sampler.h"

Sampler::Sampler() {
	num_samples = 0;
	num_sets = 0;
	count = 0;
	jump = 0;
}

Sampler::Sampler(int samples): num_samples(samples) {
	
}

Sampler::~Sampler() {

}

Sampler& Sampler::operator= (const Sampler& rhs) {
	if (this == &rhs) {
		return *this;
	}

	num_samples = rhs.num_samples;
	num_sets = rhs.num_sets;
	samples = rhs.samples;
	shuffled_indices = rhs.shuffled_indices;
	count = rhs.count;
	jump = rhs.jump;

	return *this;
}
