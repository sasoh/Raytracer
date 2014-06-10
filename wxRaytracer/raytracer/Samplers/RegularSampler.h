#ifndef __REGULAR_SAMPLER__
#define __REGULAR_SAMPLER__

#include "Sampler.h"

class RegularSampler: public Sampler {
public:
	RegularSampler();
	RegularSampler(int samples);
	~RegularSampler();
	RegularSampler& operator= (const RegularSampler& rhs);
//private:
	virtual void generate_samples();		// generate sample patterns in an unit square
	void setup_shuffled_indices();			// set up the randomly shuffled indices
	void shuffle_samples();					// randomly shuffle the samples in each pattern
	Point2D sample_unit_square();			// get next sample on unit square
};

#endif
