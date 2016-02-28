#include "tracer.hpp"

long SortTracer::n_created_ = 0;
long SortTracer::n_destroyed_ = 0;
long SortTracer::n_max_live_ = 0;
long SortTracer::n_assigned_ = 0;
long SortTracer::n_compared_ = 0;
