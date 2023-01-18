

task main()
{int mode=0;


	while (getButtonPress(buttonLeft)!=true || getButtonPress(buttonRight)!=true){
			 displayCenteredTextLine(10,"Bienvenue Barriere Automatix");
	}

	eraseDisplay();
	sleep(1000);
	while (getButtonPress(buttonUp)!=true || getButtonPress(buttonDown)!=true ){

	    	displayCenteredBigTextLine(5," Fonctionnement");

	    		if ( getButtonPress(buttonRight)==true) {
						mode=1;
					}
					if (getButtonPress(buttonLeft)==true) {
						mode=2;
					}


				while (mode==1) {	if (getButtonPress(buttonLeft)==true) {
						mode=2;
					}
				//mode libre
	SensorType[S1] = sensorEV3_Ultrasonic;
										SensorType[S2] = sensorEV3_Ultrasonic;
				displayCenteredBigTextLine(5," Mode Libre");

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

				while (mode==2) {
				//mode protégé

				displayCenteredBigTextLine(5," Mode Potege");
				if ( getButtonPress(buttonRight)==true) {
						mode=1;
					}
				}
}
