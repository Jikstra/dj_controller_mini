var MiniX1 = {};

function DBG(str) {
  print("[MiniX1] " + str);
}

function isButtonPressed(value) {
  if (value === 127) {
    return true
  } else if (value !== 0) {
    DBG('Error: Received invalid value for button: ' + value);
  }
  return false
}

function isRotaryEncoderCW(value) {
  if (value === 127) {
    return true
  } else if (value !== 0) {
    DBG('Error: Received invalid value for rotary encoder: ' + value);
  }
  return false
}


MiniX1.shift = false

MiniX1.init = function(id, debugging) {
  DBG("Hello from MiniX1!");
}

MiniX1.shiftButton = function(channel, control, value, status, group) {
  if (isButtonPressed(value)) {
    MiniX1.shift = true;
    DBG('Shift pressed');
  } else {
    MiniX1.shift = false;
    DBG('Shift released');
  }
}

MiniX1.beatJumpEncoder = function(channel, control, value, status, group) {
  if (isRotaryEncoderCW(value) == true) {
    print("beatJumpEncoder: turned CW");
    engine.setValue(group, 'beatjump_forward', 1)
  } else {
    print("beatJumpEncoder: turned CCW");
    engine.setValue(group, 'beatjump_backward', 1)
  }
}

MiniX1.beatJumpButton = function(channel, control, value, status, group) {
  if (isButtonPressed(value)) {
    DBG('beatJumpButton: pressed');

    if (MiniX1.shift === true) {
      DBG('beatJumpButton: shift is pressed, slowing down ' + group);
      engine.setValue(group, 'rate_temp_down', 1);
    }
  } else {
    DBG('beatJumpButton: released');
    if (engine.getValue(group, 'rate_temp_down') === 1) {
      engine.setValue(group, 'rate_temp_down', 0)
      engine.setValue(group, 'beats_translate_match_alignment', 1)
    } else {
      engine.setValue(group, 'reloop_toggle', 1)
    }
  }
}

MiniX1.loopButton = function(channel, control, value, status, group) {
  if (isButtonPressed(value)) {
    DBG('loopButton: pressed');
    if (MiniX1.shift === true) {
      DBG('loopButton: shift is pressed, slowing down ' + group);
      engine.setValue(group, 'rate_temp_up', 1);
    }
  } else {
    DBG('loopButton: released');
    if (engine.getValue(group, 'rate_temp_down') === 1) {
      engine.setValue(group, 'rate_temp_up', 0)
      engine.setValue(group, 'beats_translate_match_alignment', 1)
    } else {
      engine.setValue(group, 'beatloop_activate', 1)
    }
  }
}

MiniX1.loopEncoder = function(channel, control, value, status, group) {
  var loop_size = engine.getValue(group, 'beatloop_size');
  if (isRotaryEncoderCW(value) == true) {
    print("loopEncoder: turned CW");
    loop_size = loop_size * 2;
  } else {
    print("loopEncoder: turned CCW");
    loop_size = loop_size / 2;
  }
  engine.setValue(group, 'beatjump_size', loop_size);
  engine.setValue(group, 'beatloop_size', loop_size);
}

MiniX1.shutdown = function() {
  DBG("Goodbye from MiniX1!");
}
