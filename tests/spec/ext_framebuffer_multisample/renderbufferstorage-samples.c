/*
 * Copyright © 2011 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "piglit-util-gl-common.h"

/**
 * @file renderbufferstorage-samples.c
 *
 * From the EXT_framebuffer_multisample spec:
 *
 *     "The command
 *
 *         void RenderbufferStorageEXT(enum target, enum internalformat,
 *                                     sizei width, sizei height);"
 *
 *      is equivalent to calling RenderbufferStorageMultisampleEXT
 *      with <samples> equal to zero."
 */

PIGLIT_GL_TEST_CONFIG_BEGIN

	config.supports_gl_compat_version = 10;

	config.window_width = 32;
	config.window_height = 32;
	config.window_visual = PIGLIT_GL_VISUAL_DOUBLE | PIGLIT_GL_VISUAL_RGBA;

PIGLIT_GL_TEST_CONFIG_END

enum piglit_result
piglit_display(void)
{
	/* UNREACHED */
	return PIGLIT_FAIL;
}

void
piglit_init(int argc, char **argv)
{
	GLint rb_samples;
	GLuint rb;
	bool pass = true;

	piglit_require_extension("GL_EXT_framebuffer_multisample");

	glGenRenderbuffersEXT(1, &rb);
	glBindRenderbufferEXT(GL_RENDERBUFFER, rb);
	glRenderbufferStorageEXT(GL_RENDERBUFFER, GL_RGBA, 1, 1);
	glGetRenderbufferParameterivEXT(GL_RENDERBUFFER,
					GL_RENDERBUFFER_SAMPLES,
					&rb_samples);

	if (rb_samples != 0) {
		fprintf(stderr, "glRenderbufferStorageEXT() produced %d samples\n",
			rb_samples);
		pass = false;
	}

	glDeleteRenderbuffersEXT(1, &rb);

	piglit_report_result(pass ? PIGLIT_PASS : PIGLIT_FAIL);
}
