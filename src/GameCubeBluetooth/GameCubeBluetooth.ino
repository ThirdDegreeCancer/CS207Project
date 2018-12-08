#include "Nintendo.h"

// Define a Gamecube Controller
CGamecubeController GamecubeController(7);

uint32_t lastBtnState = 0;
int8_t lastX1 = 0;
int8_t lastY1 = 0;
int8_t lastX2 = 0;
int8_t lastY2 = 0;

uint32_t btnState = 0;
int8_t x1 = 0;
int8_t y1 = 0;
int8_t x2 = 0;
int8_t y2 = 0;

#define ANALOG_DEADZONE 32

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // Try to read the controller data
  if (GamecubeController.read())
  {
    auto status = GamecubeController.getStatus();
    auto report = GamecubeController.getReport();
    btnState = buttonDataByte(report);
    x1 = (report.xAxis - 128) * 1.1;
    y1 = -(report.yAxis - 128) * 1.1;

    if (-ANALOG_DEADZONE <= x1 && x1 <= ANALOG_DEADZONE)
      x1 = 0;
    if (-ANALOG_DEADZONE <= y1 && y1 <= ANALOG_DEADZONE)
      y1 = 0;
    if (-ANALOG_DEADZONE <= x2 && x2 <= ANALOG_DEADZONE)
      x2 = 0;
    if (-ANALOG_DEADZONE <= y2 && y2 <= ANALOG_DEADZONE)
      y2 = 0;
    
    if (lastBtnState != btnState
      || lastX1 != x1 || lastY1 != y1
      || lastX2 != x2 || lastY2 != y2)
    {
      sendGamepadState(btnState, x1, y1, x2, y2);

      lastBtnState = btnState;
      lastX1 = x1;
      lastY1 = y1;
      lastX2 = x2;
      lastY2 = y2;
    }
    delay(16);
  }
  else
  {
    // Add debounce if reading failed
    Serial.println(F("Error reading Gamecube controller."));
    delay(1000);
  }
}

//---------------------------------------------------//
//                                                   //
//            Edit this part for payload             //
//                                                   //
//---------------------------------------------------//
void sendGamepadState(uint32_t btnState, int8_t x1, int8_t y1, int8_t x2, int8_t y2)
{
  // First byte, needs to be this
  Serial.write((uint8_t)0xFD);
  // Second byte, size of payload
  Serial.write((uint8_t)0x06);
  // Third byte
  Serial.write((uint8_t)x1);
  // Fourth byte
  Serial.write((uint8_t)y1);
  // Fifth byte
  Serial.write((uint8_t)x2);
  // Sixth byte
  Serial.write((uint8_t)y2);
  uint8_t btnState1 = btnState & 0xFF;
  uint8_t btnState2 = (btnState >> 8) & 0xFF;
  // Seventh byte
  Serial.write((uint8_t)btnState1);
  // Eighth byte
  Serial.write((uint8_t)btnState2);
}

//---------------------------------------------------//
//                                                   //
//            Edit this part for bindings            //
//                                                   //
//---------------------------------------------------//

uint32_t buttonDataByte(Gamecube_Report_t r) {
  uint32_t btn = 0x0000;
  // Not sure
  /*if (r.dup == 1) {
    btn += 0x8000;
  }*/
  // Right Thumb Stick
  /*if (r.dright == 1) {
    btn += 0x4000;
  }*/
  // Nothing??
  /*if (r.left == 1) {
    btn += 0x2000;
  }*/
  // Button Mode???
  if (r.ddown == 1) {
    btn += 0x1000;
  }
  // Start
  /*if (r.start == 1) {
    btn += 0x0800;
  }*/
  // Select
  if (r.start == 1) {
    btn += 0x0400;
  }
  // Any C-stick movement
  if (r.cxAxis < 120 || r.cxAxis > 135 || r.cyAxis < 120 || r.cyAxis > 135) {
    btn += 0x4000;
  }
  // R Trigger
  if (r.r == 1) {
    btn += 0x0200;
  }
  // L Trigger
  if (r.l == 1) {
    btn += 0x0100;
  }
  // R Bumper
  if (r.z == 1) {
    btn += 0x0080;
  }
  // L Bumper
  /*if (r.XXX == 1) {
    btn += 0x0040;
  }*/
  // Z Button ???
  /*if (r.XXX == 1) {
    btn += 0x0020;
  }*/
  // Y Button
  if (r.y == 1) {
    btn += 0x0010;
  }
  // X Button
  if (r.x == 1) {
    btn += 0x0008;
  }
  // C Button ???
  /*if (r.XXX == 1) {
    btn += 0x0004;
  }*/
  // B Button
  if (r.b == 1) {
    btn += 0x0002;
  }
  // A button
  if (r.a == 1) {
    btn += 0x0001;
  }
  return btn;
}
