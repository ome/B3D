cmake_minimum_required(VERSION 3.2)
set (CMAKE_CXX_STANDARD 11)

find_package(CUDA QUIET REQUIRED)

## add_definitions(-D_DEBUG)
## This is broken with:
## error: ‘__debugbreak’ was not declared in this scope
add_definitions(-D_FORCE_INLINES)
add_definitions(-DHDF5_PLUGIN_EXPORTS)
add_definitions(-DH5Z_CUDACOMPRESS_DEBUG)
list(APPEND CMAKE_CXX_FLAGS "-fopenmp -fPIC -std=c++11") # -O3 -ffast-math -Wall")

        ## ${HDF5_INCLUDE_DIR}
include_directories(
	/usr/local/cuda/include/
        ${CMAKE_CURRENT_SOURCE_DIR}/../HDF5/hdf5-1.8.19/src/
	${CMAKE_CURRENT_SOURCE_DIR}/source/include/
	${CMAKE_CURRENT_SOURCE_DIR}/source/src/
        source/src/B3D_HDF5_plugin/
)

link_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/
	../HDF5/build/
        /usr/local/cuda/lib64/
)

add_library(b3d SHARED
	source/src/B3D_cudaCompress/B3D/B3DcompressFunctions.cpp
	source/src/B3D_cudaCompress/BitStreamGPU.cuh
	source/src/B3D_cudaCompress/CPU/ArithmeticCPU.cpp
	source/src/B3D_cudaCompress/CPU/ArithmeticCPU.h
	source/src/B3D_cudaCompress/CPU/EncodeCPU.cpp
	source/src/B3D_cudaCompress/CPU/EncoderTestSuite.cpp
	source/src/B3D_cudaCompress/CPU/EncoderTestSuite.h
	source/src/B3D_cudaCompress/CPU/GolombRiceCPU.cpp
	source/src/B3D_cudaCompress/CPU/GolombRiceCPU.h
	source/src/B3D_cudaCompress/CPU/HistogramCPU.cpp
	source/src/B3D_cudaCompress/CPU/HistogramCPU.h
	source/src/B3D_cudaCompress/CPU/HuffmanCPU.cpp
	source/src/B3D_cudaCompress/CPU/HuffmanCPU.h
	source/src/B3D_cudaCompress/CPU/HuffmanTableCPU.cpp
	source/src/B3D_cudaCompress/CPU/HuffmanTableCPU.h
	source/src/B3D_cudaCompress/CPU/PredictorsCPU.cpp
	source/src/B3D_cudaCompress/CPU/QuantizeCPU.cpp
	source/src/B3D_cudaCompress/CPU/RBUCCPU.cpp
	source/src/B3D_cudaCompress/CPU/RBUCCPU.h
	source/src/B3D_cudaCompress/CPU/RunLengthCPU.cpp
	source/src/B3D_cudaCompress/CPU/RunLengthCPU.h
	source/src/B3D_cudaCompress/CPU/YCoCgCPU.cpp
	source/src/B3D_cudaCompress/CPU/YCoCgCPU.h
	source/src/B3D_cudaCompress/CPU/tools/Entropy.h
	source/src/B3D_cudaCompress/CPU/tools/stb_image.c
	source/src/B3D_cudaCompress/CPU/tools/stb_image.h
	source/src/B3D_cudaCompress/Encode.cpp
	source/src/B3D_cudaCompress/Histogram.cu
	source/src/B3D_cudaCompress/Histogram.h
	source/src/B3D_cudaCompress/HistogramKernels.cui
	source/src/B3D_cudaCompress/Huffman.cu
	source/src/B3D_cudaCompress/Huffman.h
	source/src/B3D_cudaCompress/HuffmanDesign.h
	source/src/B3D_cudaCompress/HuffmanKernels.cui
	source/src/B3D_cudaCompress/HuffmanTable.cu
	source/src/B3D_cudaCompress/HuffmanTable.h
	source/src/B3D_cudaCompress/Instance.cpp
	source/src/B3D_cudaCompress/InstanceImpl.cpp
	source/src/B3D_cudaCompress/InstanceImpl.h
	source/src/B3D_cudaCompress/PackInc.cu
	source/src/B3D_cudaCompress/PackInc.h
	source/src/B3D_cudaCompress/RunLength.cu
	source/src/B3D_cudaCompress/RunLength.h
	source/src/B3D_cudaCompress/RunLengthKernels.cui
	source/src/B3D_cudaCompress/Timing.cpp
	source/src/B3D_cudaCompress/cudaUtil.h
	source/src/B3D_cudaCompress/profiler/profiler.cpp
	source/src/B3D_cudaCompress/profiler/profiler.hpp
	source/src/B3D_cudaCompress/profiler/profilerlogwriter.cpp
	source/src/B3D_cudaCompress/profiler/profilerlogwriter.hpp
	source/src/B3D_cudaCompress/profiler/profilerstreamwriter.cpp
	source/src/B3D_cudaCompress/profiler/profilerstreamwriter.hpp
	source/src/B3D_cudaCompress/reduce/license.txt
	source/src/B3D_cudaCompress/reduce/reduce_app.cui
	source/src/B3D_cudaCompress/reduce/reduce_globals.h
	source/src/B3D_cudaCompress/reduce/reduce_kernel.cui
	source/src/B3D_cudaCompress/reduce/reduce_plan.cpp
	source/src/B3D_cudaCompress/reduce/reduce_plan.h
	source/src/B3D_cudaCompress/scan/license.txt
	source/src/B3D_cudaCompress/scan/scan_app.cui
	source/src/B3D_cudaCompress/scan/scan_cta.cui
	source/src/B3D_cudaCompress/scan/scan_globals.h
	source/src/B3D_cudaCompress/scan/scan_kernel.cui
	source/src/B3D_cudaCompress/scan/scan_plan.cpp
	source/src/B3D_cudaCompress/scan/scan_plan.h
	source/src/B3D_cudaCompress/scan/vector_kernel.cui
	source/src/B3D_cudaCompress/tools/Functor.h
	source/src/B3D_cudaCompress/tools/Operator.h
	source/src/B3D_cudaCompress/util.h
	source/src/B3D_cudaCompress/util/Bits.cu
	source/src/B3D_cudaCompress/util/CudaTimer.cpp
	source/src/B3D_cudaCompress/util/DWTCommon.cuh
	source/src/B3D_cudaCompress/util/DWTFloat.cu
	source/src/B3D_cudaCompress/util/DWTFloat2DLowpassKernels.cui
	source/src/B3D_cudaCompress/util/DWTFloatFilters.cuh
	source/src/B3D_cudaCompress/util/DWTFloatFromSymbolsKernels.cui
	source/src/B3D_cudaCompress/util/DWTFloatKernels.cui
	source/src/B3D_cudaCompress/util/DWTInt.cu
	source/src/B3D_cudaCompress/util/DWTInt2DLowpassKernels.cui
	source/src/B3D_cudaCompress/util/DWTIntKernels.cui
	source/src/B3D_cudaCompress/util/Predictors.cu
	source/src/B3D_cudaCompress/util/Quantize.cu
	source/src/B3D_cudaCompress/util/Quantize.cuh
	source/src/B3D_cudaCompress/util/QuantizeKernels.cui
	source/src/B3D_cudaCompress/util/YCoCg.cu
)

add_library(b3dh5 SHARED
	source/src/B3D_HDF5_plugin/GPUResources.cpp
	source/src/B3D_HDF5_plugin/GPUResources.h
	source/src/B3D_HDF5_plugin/HDF5_plugin.cpp
	source/src/B3D_HDF5_plugin/HDF5_plugin.h
	source/src/B3D_HDF5_plugin/cudaCompressFunctions.cpp
	source/src/B3D_HDF5_plugin/cudaCompressFunctions.h
	source/src/B3D_HDF5_plugin/cudaUtil.h
	source/src/B3D_HDF5_plugin/global.h
)

add_executable(example
	source/src/examples/cudaUtil.h
	source/src/examples/direct_example+benchmark.cpp
	source/src/examples/global.h
	source/src/examples/tools/entropy.h
	source/src/examples/tools/imgtools.h
	source/src/examples/tools/rawfile.cpp
	source/src/examples/tools/rawfile.h
	source/src/examples/tthread/tinythread.cpp
	source/src/examples/tthread/tinythread.h
)

target_link_libraries(example -lpthread -lhdf5 ${CUDA_LIBRARIES} -lb3d -lb3dh5)
