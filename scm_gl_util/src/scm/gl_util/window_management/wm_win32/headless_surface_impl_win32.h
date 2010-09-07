
#ifndef SCM_GL_UTIL_WM_WIN32_HEADLESS_SURFACE_IMPL_WIN32_H_INCLUDED
#define SCM_GL_UTIL_WM_WIN32_HEADLESS_SURFACE_IMPL_WIN32_H_INCLUDED

#include <scm/core/platform/platform.h>

#if SCM_PLATFORM == SCM_PLATFORM_WINDOWS

#include <scm/core/platform/windows.h>
#include <GL/GL.h>
#include <scm/gl_util/window_management/GL/wglext.h>

#include <scm/core/pointer_types.h>

#include <scm/gl_util/window_management/headless_surface.h>
#include <scm/gl_util/window_management/window.h>

namespace scm {
namespace gl {
namespace wm {

class window;

namespace util {

class wgl_extensions;

} // namespace util

struct headless_surface::headless_surface_impl
{
    headless_surface_impl(const window& in_parent_wnd);
    virtual ~headless_surface_impl();

    void            cleanup();

    HPBUFFERARB     _pbuffer_handle;
    HDC             _device_handle;

    shared_ptr<util::wgl_extensions>  _wgl_extensions;

}; // class headless_surface_impl

} // namespace wm
} // namepspace gl
} // namepspace scm

#endif // SCM_PLATFORM == SCM_PLATFORM_WINDOWS
#endif // SCM_GL_UTIL_WM_WIN32_HEADLESS_SURFACE_IMPL_WIN32_H_INCLUDED
