cd /D "%~dp0"

CALL :compile_shaders_in_dir .\resources\shaders
CALL :compile_shaders_in_dir .\tests\resources\observer\block\shaders\global_lighting
CALL :compile_shaders_in_dir .\tests\resources\observer\isometric\shaders\lighting
CALL :compile_shaders_in_dir .\tests\resources\observer\sprite\shaders\health_bars

EXIT /B 0

:compile_shaders_in_dir
echo "Compiling shaders in %~1"
glslc %~1\triangle-textured.frag -o %~1\triangle-textured.frag.spv
glslc %~1\triangle-textured.vert -o %~1\triangle-textured.vert.spv
