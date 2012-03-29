
// Copyright (c) 2012 Christopher Lux <christopherlux@gmail.com>
// Distributed under the Modified BSD License, see license.txt.

#ifndef SCM_CL_CORE_OPENCL_ACCUMU_TIMER_H_INCLUDED
#define SCM_CL_CORE_OPENCL_ACCUMU_TIMER_H_INCLUDED

#include <scm/core/time/accum_timer_base.h>
#include <scm/core/time/cpu_timer.h>

#include <scm/cl_core/opencl/opencl_fwd.h>

#include <CL/cl_fwd.hpp>

#include <scm/core/platform/platform.h>
#include <scm/core/utilities/platform_warning_disable.h>

namespace scm {
namespace cl {
namespace util {

class __scm_export(cl_core) accum_timer : public time::accum_timer_base
{
public:
    typedef time::cpu_timer::nanosec_type   nanosec_type;
    struct cl_times : public time::cpu_timer::cpu_times
    {
        nanosec_type    cl;
    };

public:
    accum_timer();
    virtual ~accum_timer();

    ::cl::Event*const       event() const;

    void                    stop();
    void                    collect();
    void                    force_collect();
    void                    reset();

    cl_times                detailed_last_time() const;
    cl_times                detailed_accumulated_time() const;
    cl_times                detailed_average_time() const;

    void                    report(std::ostream&                     os,
                                   time::timer_base::time_unit       tunit  = time::timer_base::msec) const;
    void                    report(std::ostream&                     os,
                                   size_t                            dsize,
                                   time::timer_base::time_unit       tunit  = time::timer_base::msec,
                                   time::timer_base::throughput_unit tpunit = time::timer_base::MiBps) const;
    void                    detailed_report(std::ostream&                     os,
                                            time::timer_base::time_unit       tunit  = time::timer_base::msec) const;
    void                    detailed_report(std::ostream&                     os,
                                            size_t                            dsize,
                                            time::timer_base::time_unit       tunit  = time::timer_base::msec,
                                            time::timer_base::throughput_unit tpunit = time::timer_base::MiBps) const;

protected:
    event_ptr               _cl_event;
    bool                    _cl_event_finished;

    cl_times                _detailed_last_time;
    cl_times                _detailed_accumulated_time;
    time::cpu_timer         _cpu_timer;

}; // class accum_timer

} // namespace util
} // namespace cl
} // namespace scm

#include <scm/core/utilities/platform_warning_enable.h>

#endif // SCM_CL_CORE_OPENCL_ACCUMU_TIMER_H_INCLUDED
