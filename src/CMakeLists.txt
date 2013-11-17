set(SOURCES main.cpp color.cpp image_buffer.cpp vertex_buffer.cpp scene_object.cpp
	scene_geometry.cpp scene_light.cpp sphere.cpp plane.cpp camera.cpp
	scene.cpp shader.cpp blinn.cpp)

include_directories(math)

add_executable(raytracer ${SOURCES})
target_link_libraries(raytracer ${LIBRARIES} )

if(WIN32)
	if(MSVC_IDE)
		set(LIBRARY_DESTINATION 
			${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration))

		add_custom_command(TARGET raytracer POST_BUILD 
			COMMAND ${CMAKE_COMMAND} -E copy 
			${DLLS} ${LIBRARY_DESTINATION})
	else()
		set(LIBRARY_DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
		add_custom_command(TARGET raytracer POST_BUILD 
			COMMAND ${CMAKE_COMMAND} -E copy 
			${DLLS} ${LIBRARY_DESTINATION})
	endif()
endif()

if(UNIX)
	install(TARGETS raytracer RUNTIME DESTINATION bin)
endif()
