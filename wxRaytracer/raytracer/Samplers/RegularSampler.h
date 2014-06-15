#pragma once
#include "Sampler.h"

class RegularSampler: public Sampler {
public:
	RegularSampler();
	RegularSampler(int samples);
	~RegularSampler();
	RegularSampler& operator= (const RegularSampler& rhs);
private:
	virtual void generate_samples();		// generate sample patterns in an unit square
};
