precision mediump float;
varying vec3 v_Color;
void main()
{
  gl_FragColor = vec4(v_Color, 1.0);
}



/*
precision mediump float;
uniform vec4 vColor;

void main()
{
    gl_FragColor = vColor;
}

*/