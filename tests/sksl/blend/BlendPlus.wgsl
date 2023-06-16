struct FSIn {
  @builtin(front_facing) sk_Clockwise: bool,
};
struct FSOut {
  @location(0) sk_FragColor: vec4<f32>,
};
struct _GlobalUniforms {
  src: vec4<f32>,
  dst: vec4<f32>,
};
@binding(0) @group(0) var<uniform> _globalUniforms: _GlobalUniforms;
fn main(_stageOut: ptr<function, FSOut>) {
  {
    let _skTemp0 = min(_globalUniforms.src + _globalUniforms.dst, vec4<f32>(1.0));
    (*_stageOut).sk_FragColor = _skTemp0;
  }
}
@fragment fn fragmentMain(_stageIn: FSIn) -> FSOut {
  var _stageOut: FSOut;
  main(&_stageOut);
  return _stageOut;
}