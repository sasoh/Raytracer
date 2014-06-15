#pragma once
#include "Sampler.h"

class MultijitteredSampler : public Sampler
{
public:
	MultijitteredSampler();
	MultijitteredSampler(int samples);
	~MultijitteredSampler();
	MultijitteredSampler& operator= (const MultijitteredSampler& rhs);
private:
	virtual void generate_samples();		// generate sample patterns in an unit square
};
