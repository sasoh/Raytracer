#include "RegularSampler.h"

RegularSampler::RegularSampler(): Sampler() {

}

RegularSampler::RegularSampler(int samples): Sampler(samples) {

}

RegularSampler::~RegularSampler() {

}

RegularSampler& RegularSampler::operator= (const RegularSampler& rhs) {
	if (this == &rhs) {
		return *this;
	}

	Sampler::operator=(rhs);

	return *this;
}

void RegularSampler::generate_samples() {
	int n = static_cast<int>(sqrt(num_samples));

	Point2D sample_point(0.5f, 0.5f);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			samples.push_back(sample_point);
		}
	}
}
