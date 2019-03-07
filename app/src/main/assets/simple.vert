attribute vec3 vPosition;
attribute vec3 vColor;
varying vec3 v_Color;
uniform mat4 matrix;

void main()
{
	gl_Position = matrix * vec4(vPosition, 1.0);
	v_Color = vColor;
}