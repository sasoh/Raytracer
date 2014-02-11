// Chapter 3 sphere object

void World::build(void) {
	
	vp.set_hres(300);
	vp.set_vres(300);
	vp.set_pixel_size(1.0);
	vp.set_gamma(1.0);

	background_color = black;
	tracer_ptr = new SingleSphere(this);
	sphere.set_center(0.0);
	sphere.set_radius(85.0);

}

