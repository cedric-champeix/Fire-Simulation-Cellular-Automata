exec_parallel: parallel.c calc_fire_evolution_parallel.c generate_map.c is_fire_spreading.c init_write.c write_map.c swap_maps.c
	gcc parallel.c calc_fire_evolution_parallel.c generate_map.c is_fire_spreading.c init_write.c write_map.c swap_maps.c -o parallel_exec -lpthread

exec_serial: serial.c generate_map.c init_write.c write_map.c is_fire_spreading.c swap_maps.c
	gcc serial.c init_map.c generate_map.c write_map.c is_fire_spreading.c swap_maps.c -o serial_exec