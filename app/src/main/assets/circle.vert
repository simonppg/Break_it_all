attribute vec3 vPosition;
uniform mat4 matrix;

void main()
{
	gl_Position = matrix * vec4(vPosition, 1.0);
}