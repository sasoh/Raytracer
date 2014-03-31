#ifndef __SAMPLER__
#define __SAMPLER__

#include "Point2D.h"
#include <vector>

using std::vector;

class Sampler {
public:
	Sampler();
	Sampler(int samples);
	~Sampler();
	Sampler& operator= (const Sampler& rhs);
	virtual void generate_samples() = 0;	// generate sample patterns in an unit square
	void setup_shuffled_indices();			// set up the randomly shuffled indices
	void shuffle_samples();					// randomly shuffle the samples in each pattern
	Point2D sample_unit_square();			// get next sample on unit square
protected:
	int num_samples;						// number of sample points in a pattern
	int num_sets;							// number of sample sets (patterns) stored
	vector<Point2D> samples;				// sample points on an unit square
	vector<int> shuffled_indices;			// shuffled samples array indices
	unsigned long count;					// current number of sample points used
	int jump;								// random index jump
};

#endif
