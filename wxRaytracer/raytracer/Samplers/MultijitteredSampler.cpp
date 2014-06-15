#include "MultijitteredSampler.h"
#include <random>

MultijitteredSampler::MultijitteredSampler() : Sampler() {
	generate_samples();
}

MultijitteredSampler::MultijitteredSampler(int samples): Sampler(samples) {
	generate_samples();
}

MultijitteredSampler::~MultijitteredSampler() {

}

MultijitteredSampler& MultijitteredSampler::operator= (const MultijitteredSampler& rhs) {
	if (this == &rhs) {
		return *this;
	}

	Sampler::operator=(rhs);

	return *this;
}

// function done with some help from the graphics gems 4 sources
/// http://users.soe.ucsc.edu/~pang/160/f99/Gems/GemsIV/multi_jitter/
void MultijitteredSampler::generate_samples() {
	int n = static_cast<int>(sqrt(num_samples));

	float subcell_width = 1.0f / static_cast<float>(num_samples);

	// fill samples with dummy points so we can access the elements with the brackets operator later
	Point2D dummy_point;
	for (int i = 0; i < num_samples * num_sets; ++i) {
		samples.push_back(dummy_point);
	}

	// random generators
	std::default_random_engine generator;
	std::uniform_real_distribution<float> float_distribution(0.0f, subcell_width);

	// initial generation
	for (int k = 0; k < num_sets; ++k) {
		// n x n grid	
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int current_index = i * n + j + k * num_samples;
				samples[current_index].x = (i * n + j) * subcell_width + float_distribution(generator);
				samples[current_index].y = (j * n + i) * subcell_width + float_distribution(generator);
			}
		}
	}

	// x-coordinate shuffling within each column
	for (int k = 0; k < num_sets; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				std::uniform_int_distribution<int> int_distribution(j, n - 1);
				int random = int_distribution(generator);
				int random_index = i * n + random + k * num_samples;
				int current_index = i * n + j + k * num_samples;
				
				float temp = samples[current_index].x;
				samples[current_index].x = samples[random_index].x;
				samples[random_index].x = temp;
			}
		}
	}
	
	// y-coordinate shuffling within each row
	for (int k = 0; k < num_sets; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				std::uniform_int_distribution<int> int_distribution(j, n - 1);
				int random = int_distribution(generator);
				int random_index = random * n + i + k * num_samples;
				int current_index = j * n + i + k * num_samples;

				float temp = samples[current_index].x;
				samples[current_index].x = samples[random_index].x;
				samples[random_index].x = temp;
			}
		}
	}
}