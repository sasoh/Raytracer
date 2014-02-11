
void World::build(void) {

	int num_samples = 8; 
	
	// view plane  
	  
	vp.set_hres(512);
	vp.set_vres(512);
	vp.set_pixel_size(0.5);
	vp.set_samples(num_samples);
	
	tracer_ptr = new SingleSphere();

}

