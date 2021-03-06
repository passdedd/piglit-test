/* [config]
 * expect_result: pass
 * glsl_version: 1.10
 * require_extensions: GL_ARB_shader_texture_lod
 * [end config]
 */
#extension GL_ARB_shader_texture_lod: require

uniform sampler1D s;
attribute vec4 pos;
attribute float coord;
attribute float dPdx;
attribute float dPdy;
varying vec4 color;

void main()
{
  gl_Position = pos;
  color = texture1DGradARB(s, coord, dPdx, dPdy);
}
