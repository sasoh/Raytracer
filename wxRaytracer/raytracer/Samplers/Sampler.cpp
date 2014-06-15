#include "Sampler.h"
#include <algorithm>

const int NUM_SETS_MAGIC_NUMBER = 83;

Sampler::Sampler() : num_samples(1), num_sets(NUM_SETS_MAGIC_NUMBER), count(0), jump(0) {
	setup_shuffled_indices();
}

Sampler::Sampler(int samples): num_samples(samples), num_sets(NUM_SETS_MAGIC_NUMBER), count(0), jump(0) {
	setup_shuffled_indices();
}

Sampler::~Sampler() {
	shuffled_indices.clear();
	samples.clear();
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

int Sampler::get_num_samples() const {
	return num_samples;
}

void Sampler::generate_samples() {

	// should be overriden

}

void Sampler::setup_shuffled_indices() {
	shuffled_indices.reserve(num_samples * num_sets);
	vector<int> indices;

	for (int i = 0; i < num_samples; ++i) {
		indices.push_back(i);
	}

	for (int i = 0; i < num_sets; ++i) {
		std::random_shuffle(indices.begin(), indices.end());
		
		for (int j = 0; j < num_samples; ++j) {
			shuffled_indices.push_back(indices[j]);
		}
	}
}

void Sampler::shuffle_samples() {

	// should be overriden

}

Point2D Sampler::sample_unit_square() {
	if (count % num_samples == 0) {
		jump = (rand() % num_sets) * num_samples;
	}

	return samples[jump + shuffled_indices[jump + ((count++) % num_samples)]];
}