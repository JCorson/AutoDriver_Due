void dSPINConfig_board()
{
  // X Axis for maniipulator #1
  board.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations;
                                    //  second paramter ignored.
  board.setParam(STEP_MODE,STEP_FS_128);  // 128 microsteps per step
  board.setMaxSpeed(60);        // 500 steps/s max
  board.setMinSpeed(0);          // No minimum speed
  board.setFullSpeed(500);       // Microstep below 500 steps/s
  board.setAcc(0xFFF);             // Accelerate at maximum steps/s/s; 0xFFF = infinite
  board.setDec(0xFFF);             // Deccelerate at maximum steps/s/s; 0xFFF = infinite
  board.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board.setOCThreshold(OC_1500mA);  // Overcurrent threshold
  board.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board.setOCShutdown(OC_SD_ENABLE); // don't shutdown on OC
  board.setVoltageComp(VS_COMP_DISABLE); // Motor V compensation
  board.setSwitchMode(SW_USER);    // Switch is not hard stop
  board.setOscMode(INT_16MHZ_OSCOUT_16MHZ); // Clock settings
  board.setAccKVAL(40);            // This controls the acceleration current
  board.setDecKVAL(40);            // This controls the deceleration current
  board.setRunKVAL(40);            // This controls the run current
  board.setHoldKVAL(40);           // This controls the holding current
  board.setLoSpdOpt(false);         // Enabled low speed compensation. If enabled, MinSpeed is upper threshold at which this compensation is employed.
}
