
task main()
{

									SensorType[S1] = sensorEV3_Ultrasonic;
									SensorType[S2] = sensorEV3_Ultrasonic;
									//setSensorMode(S1,modeEV3Ultrasonic_Cm);

									if (getUSDistance(S1)<15)
										{
									setMotorTarget(motorA, 90, 10);
									sleep(2000);
									}
									if (getUSDistance(S2)>15 && getUSDistance(S1)>15 )
										{
									setMotorTarget(motorA, 0, 10);
									sleep(1000);}
}

