cmake_minimum_required(VERSION 3.2)
find_package(CUDA QUIET REQUIRED)
#project(b3d LANGUAGES CXX CUDA)
#INCLUDE_DIRECTORIES(/usr/local/cuda/include)
 
#cuda_add_executable(
#    hellocuda
#    source/src/B3D_cudaCompress/
#    src/hellocuda.cu)

set (CMAKE_CXX_STANDARD 11)
add_definitions(-D_FORCE_INLINES)
LIST(APPEND CMAKE_CXX_FLAGS "-std=c++11") # -O3 -ffast-math -Wall")

#set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} \"-D_FORCE_INLINES\" ")

include_directories(
	/usr/local/cuda/include
	source/include
	source/src)

add_library(b3d STATIC
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
