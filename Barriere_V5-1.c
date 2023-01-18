task main()
{	int mode=0;
	int step;
	while (getButtonPress(buttonLeft)!=true || getButtonPress(buttonRight)!=true)
{
			 displayCenteredTextLine(10,"Bienvenue Barriere Automatix");
}

			eraseDisplay();
			sleep(1000);


	while (!(getButtonPress(buttonUp)==1 && getButtonPress(buttonDown)==1) )
	{

	    	displayCenteredBigTextLine(5," Fonctionnement");

	    		if( getButtonPress(buttonRight)==true) {
						mode=1;
					}
					if (getButtonPress(buttonLeft)==true) {
						mode=2;
					}


				while (mode==1)
				{
				//mode libre
				if (getButtonPress(buttonLeft)==true)
										{
											mode=2;
										}
				displayCenteredBigTextLine(5," Mode Libre");

									SensorType[S1] = sensorEV3_Ultrasonic;
									SensorType[S2] = sensorEV3_Ultrasonic;
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

				while (mode==2)
					{
				//mode protégé
					SensorType[S1] = sensorEV3_Ultrasonic;
					SensorType[S2] = sensorEV3_Ultrasonic;
				displayCenteredBigTextLine(5," Mode Protege");

							if (step==0 && getButtonPress(buttonRight)==1)
							{
									step=1;
									eraseDisplay();
									displayCenteredBigTextLine(5," code 1");
									sleep(5000);

							}
							if (step==1 && getButtonPress(buttonRight)==1)
							{
								    step=2;
										eraseDisplay();
										displayCenteredBigTextLine(5," code 2");
										sleep(5000);


							}
							if (step==2 && getButtonPress(buttonLeft)==1)
							{
							step=3;

							sleep(5000);
							}
							if (step==3 && getButtonPress(buttonUp)==1)
							{
							step=4;
							sleep(5000);
							}
							if (step==4 && getButtonPress(buttonUp)==1)
							{
							step=5;
							sleep(5000);
							}
							if (getButtonPress(buttonBack)==1){
								step=0;
								sleep(5000);
							}
				while (step==5)
				{

										SensorType[S1] = sensorEV3_Ultrasonic;
										SensorType[S2] = sensorEV3_Ultrasonic;
									eraseDisplay();
									sleep(1000);
									displayCenteredBigTextLine(5," code bon");

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
				}

				if ( getButtonPress(buttonRight)==true)
						{
							mode=1;
						}
				}
}
