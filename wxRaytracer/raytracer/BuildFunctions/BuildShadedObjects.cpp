
void World::build(void) {

	int num_samples = 16; 
	
	// view plane  
	  
	vp.set_hres(512);
	vp.set_vres(512);
	vp.set_pixel_size(0.5);
	vp.set_samples(num_samples);
	
	background_color = black;
	tracer_ptr = new SingleSphere(this);
	sphere.set_center(0.0);
	sphere.set_radius(85.0);

}

